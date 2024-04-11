#include <algorithm>
#include <stdio.h>
#include <memory.h>
using namespace std;

const int MAX_N = 2000005;

int n,m;
int in[MAX_N];
int inv[MAX_N];
int out[MAX_N], temp[MAX_N];
int pos2bckt[MAX_N];

int bckt[MAX_N], relabel[MAX_N];
int bpos[MAX_N];

void build() {
    for (int i = 0; i < n; i++) out[i] = i;
    sort(out, out + n, [](int a,int bckt) { return in[a] < in[bckt];});
    for(int i = 0, c = 0; i < n; i++) { bckt[i] = c; if (i+1 == n || in[out[i]] != in[out[i+1]]) c++; }
    for(int h = 1; h < n; h <<= 1) {
        for (int i = 0; i < n; i++) pos2bckt[out[i]] = bckt[i];
        for (int i = n-1; i>=0; i--) bpos[bckt[i]] = i;
        for (int i = 0; i < n; i++) if (out[i] >= n-h) temp[bpos[bckt[i]]++] = out[i];
        for (int i = 0; i < n; i++) if (out[i] >= h) temp[bpos[pos2bckt[out[i]-h]]++] = out[i]-h;
        for (int i = 0, c = 0; i < n; i++) {
            relabel[i] = c;
            if (i+1 == n) break;
            if (bckt[i] != bckt[i+1]) c++;
            else if(temp[i+1] >= n-h || temp[i] >= n-h) c++;
            else if(pos2bckt[temp[i+1] + h] != pos2bckt[temp[i]+h]) c++;
        }
        memcpy(out, temp, sizeof(temp[0]) * n);
        memcpy(bckt, relabel, sizeof(relabel[0]) * n);
    }
}

char str[MAX_N];
int cnt[MAX_N],mmn[MAX_N],rmmn[MAX_N];

int main()
{
    scanf ("%s",str);
    while (str[n]) n++;
    for (int i=0;i<n;i++) in[i] = str[i] == ')';
    for (int i=0;i<n;i++) in[i+n] = in[i];

    int step = 0, mn = 0;
    for (int i=0;i<n;i++){
        if (in[i] == 1) step--;
        else step++;
        cnt[i+1] = step;
        if (mn > step)
            mn = step;
        mmn[i+1] = mn;
    }
    int p = step;
    for (int i=n-1;i>=0;i--){
        if (in[i] == 1) step++;
        else step--;
        if (p > step)
            p = step;
        rmmn[i] = p;
    }

    n *= 2;
    build();
    n /= 2;

    int c[2] = {0,};
    for (int i=0;i<n;i++) c[in[i]]++;
    if (c[0] >= c[1]){
        for (int i=0;i<2*n;i++){
            if (out[i] < n && rmmn[out[i]] - cnt[out[i]] >= 0 && cnt[n] - cnt[out[i]] + mmn[out[i]] >= 0){
                for (int j=0;j<n;j++) str[j] = in[out[i]+j] == 0 ? '(' : ')';
                for (int j=n,k=0;k<c[0]-c[1];j++,k++) str[j] = ')';
                break;
            }
        }
    }
    else{
        for (int i=0;i<2*n;i++){
            if (out[i] < n && rmmn[out[i]] - cnt[out[i]] >= c[0] - c[1] && cnt[n] - cnt[out[i]] + mmn[out[i]] >= c[0] - c[1]){
                for (int j=0;j<c[1]-c[0];j++) str[j] = '(';
                for (int j=c[1]-c[0],k=0;k<n;j++,k++) str[j] = in[out[i]+k] == 0 ? '(' : ')';
                break;
            }
        }
    }
    puts(str);

    return 0;
}
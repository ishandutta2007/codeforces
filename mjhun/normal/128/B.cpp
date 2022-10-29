#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1 << 17;
char S[MAXN];
int n, gap;
int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];

bool sufcmp(int i, int j){
    if (pos[i] != pos[j])
        return pos[i] < pos[j];
    i += gap;
    j += gap;
    return (i < n && j < n) ? pos[i] < pos[j] : i > j;
}

void buildSA(){
    for(int i=0;i<n;++i){
        sa[i] = i;
        pos[i] = S[i];
    }
    for (gap = 1;; gap *= 2){
        sort(sa, sa + n, sufcmp);
        for(int i=0;i<n-1;++i)
            tmp[i + 1] = tmp[i] + sufcmp(sa[i], sa[i + 1]);
        for(int i=0;i<n;++i)
            pos[sa[i]] = tmp[i];
        if (tmp[n - 1] == n - 1) break;
    }
}

void buildLCP(){
    for (int i = 0, k = 0; i < n; ++i) if (pos[i] != n - 1){
        for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];++k);
        lcp[pos[i]] = k;
        if (k)--k;
    }
}

int base[MAXN];

int main(){
    int k;
    gets(S);n=strlen(S);
    scanf("%d",&k);
    if(k>(long long)n*(n+1)/2){
        puts("No such line.");return 0;
    }
    buildSA();
    buildLCP();

    int j=0,l=1;
    while(k>0){
        int i;
        for(i=j;lcp[i]>base[i];++i);
        k-=i-j+1;
        if(k<=0)break;
        for(int w=j;w<i+1;++w)base[w]++;
        if(l+1<=n-sa[j])l++;
        else {
            l=base[j+1]+1;
            j++;
        }
    }
    for(int i=sa[j];i<sa[j]+l;++i)putchar(S[i]);
    puts("");

    return 0;
}
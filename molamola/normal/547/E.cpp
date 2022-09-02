#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()

int SA[400050], RA[400050], tRA[400050], C[400050], tSA[400050];
int LCP[400050][20], iSA[400050], N;
char ch[400050];
int len[400040];
int n, q;

void build_SA(){
    int i, cnt = 128;
    for(i=0;i<N;i++)SA[i] = i, RA[i] = ch[i] + 1;
    for(int L=1;L<N;L<<=1){
        for(i=0;i<N;i++)++C[i+L < N ? RA[i+L] : 0];
        for(i=1;i<=cnt;i++)C[i] += C[i-1];
        for(i=N-1;i>=0;i--)tSA[--C[i+L < N ? RA[i+L] : 0]] = i;
        for(i=0;i<=cnt;i++)C[i] = 0;
        for(i=0;i<N;i++)++C[RA[i]];
        for(i=1;i<=cnt;i++)C[i] += C[i-1];
        for(i=N-1;i>=0;i--)SA[--C[RA[tSA[i]]]] = tSA[i];
        for(i=0;i<=cnt;i++)C[i] = 0;
        for(i=0,cnt=1;i<N;i++){
            if(i!=0 && (RA[SA[i]] != RA[SA[i-1]] || SA[i]+L>=N || SA[i-1]+L>=N || RA[SA[i]+L] != RA[SA[i-1]+L]))cnt++;
            tRA[i] = cnt;
        }
        for(i=0;i<N;i++)RA[SA[i]] = tRA[i];
    }
}

void build_LCP(){
    for(int i=0;i<N;i++)iSA[SA[i]] = i;
    for(int i=0,L=0;i<N;LCP[iSA[i++]][0] = L, L = (L?L-1:0)){
        if(iSA[i] == 0)continue;
        while(ch[i+L] == ch[SA[iSA[i]-1]+L])L++;
    }
    for(int i=1;i<N;i++){
        for(int j=1;j<20;j++){
            if((1<<j) > i)break;
            LCP[i][j] = min(LCP[i][j-1], LCP[i-(1<<(j-1))][j-1]);
        }
    }
}

int get_l(int x,int h){
    for(int i=19;i>=0;i--){
        if((1<<i) <= x && LCP[x][i] >= h)x -= (1<<i);
    }
    return x;
}

int get_r(int x,int h){
    for(int i=19;i>=0;i--){
        if(x + (1<<i) < N && LCP[x+(1<<i)][i] >= h)x += (1<<i);
    }
    return x;
}

int BIT[400020];
int ans[500020];
void update(int x,int w){
    for(int i=x;i<=N;i+=(i&-i))BIT[i] += w;
}

int read(int x){
    int res = 0;
    for(int i=x;i;i-=(i&-i))res += BIT[i];
    return res;
}

int read(int x,int y){
    return read(y) - read(x-1);
}

struct query{
    int l, r, c, k;
    bool operator<(const query &l)const{
        return k > l.k;
    }
}que[1000050];

Pi A[400040];

int main(){
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++){
        scanf("%s", ch + N);
        len[i] = N;
        N += strlen(ch + N);
        if(i != n-1)N++;
    }
    len[n] = N+1;
    build_SA();
    build_LCP();
    for(int i=0;i<N;i++)A[i] = Pi(SA[i], i);
    sort(A, A+N);
    for(int i=0;i<q;i++){
        int l, r, k; scanf("%d%d%d",&l,&r,&k); --l, --r, --k;
        int xL = get_l(iSA[len[k]], len[k+1] - len[k] - 1);
        int xR = get_r(iSA[len[k]], len[k+1] - len[k] - 1);
        int L = len[l], R = len[r+1] - 1;
        que[i] = {xL, xR, i, L};
        que[i+q] = {xL, xR, i+q, R+1};
    }
    sort(que, que + q + q);
    for(int i=0, now = N-1;i<q+q;i++){
        while(now != -1 && A[now].Fi >= que[i].k){
            update(A[now].Se + 1, 1);
            now--;
        }
        int t = read(que[i].l + 1, que[i].r + 1);
        if(que[i].c >= q)ans[que[i].c-q] -= t;
        else ans[que[i].c] += t;
    }
    for(int i=0;i<q;i++)printf("%d\n", ans[i]);
    return 0;
}
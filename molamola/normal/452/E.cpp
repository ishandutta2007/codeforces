#include<stdio.h>
#include<vector>
using namespace std;

#define ll long long
#define N_ 300030

char ch[N_];
int N;
int SA[N_], RA[N_], tRA[N_], C[N_], tSA[N_];
int LCP[N_], iSA[N_];
vector <int> v[N_];
int L1, L2, L3, LL;
ll now, D[N_];

struct unf{
    int p[N_], w[N_][3];
    void init(){
        for(int i=2;i<N;i++){
            p[i] = i;
            if(SA[i] < L1)w[i][0] = 1;
            else if(SA[i] < L1 + L2 + 1)w[i][1] = 1;
            else w[i][2] = 1;
        }
    }
    int Find(int x){return p[x] == x ? x : p[x] = Find(p[x]);}
    void Union(int x,int y){
        x = Find(x), y = Find(y);
        p[x] = y;
        now -= (ll)w[x][0] * w[x][1] * w[x][2];
        now -= (ll)w[y][0] * w[y][1] * w[y][2];
        for(int i=0;i<3;i++)w[y][i] += w[x][i];
        now += (ll)w[y][0] * w[y][1] * w[y][2];
    }
}uf;

int main(){
    scanf("%s",ch);
    while(ch[++N]);
    LL = L1 = N;
    ch[N++] = '#';
    scanf("%s",ch+N);
    while(ch[++N]);
    if(LL > (L2 = N-L1-1))LL = L2;
    ch[N++] = '$';
    scanf("%s",ch+N);
    while(ch[++N]);
    if(LL > (L3 = N-L1-L2-2))LL = L3;
    int i, cnt = 128;
    for(i=0;i<N;i++)SA[i] = i, RA[i] = ch[i];
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
            if(i!=0 && (RA[SA[i]] != RA[SA[i-1]] || (SA[i]+L<N?RA[SA[i]+L]:0) != (SA[i]+L<N?RA[SA[i-1]+L]:0)))cnt++;
            tRA[i] = cnt;
        }
        for(i=0;i<N;i++)RA[SA[i]] = tRA[i];
    }
    for(i=0;i<N;i++)iSA[SA[i]] = i;
    int L;
    for(i=0,L=0;i<N;LCP[iSA[i++]] = L, L = (L?L-1:0)){
        if(iSA[i] == 0)continue;
        while(ch[i+L] == ch[SA[iSA[i]-1]+L])L++;
    }
    for(i=2;i<N;i++)v[LCP[i]].push_back(i);
    uf.init();
    for(i=N-1;i;i--){
        int sz = (int)v[i].size();
        for(int j=0;j<sz;j++)uf.Union(v[i][j], v[i][j]-1);
        if(i <= LL)D[i] = now;
    }
    for(i=1;i<=LL;i++)printf("%lld ", D[i] % 1000000007);
    return 0;
}
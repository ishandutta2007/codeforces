#include <stdio.h>
#include <map>
using namespace std;

#define MAXN 100005
#define MAXK 10000000
#define mem(n) ((V[(n)>>5]>>((n)&31))&1)
#define write(n) (V[(n)>>5]|=1<<((n)&31))

int N,M,A[MAXN],B[MAXN];
int prime[664580],pcnt;
unsigned V[312505];
map <int,int> cnt;

void reg(int n,int v)
{
    int i,k;
    for (i=1;prime[i]*prime[i]<=n;i++) if (n%prime[i] == 0){
        k = 0;
        for (;n%prime[i]==0;n/=prime[i]) k += v;
        cnt[prime[i]] += k;
    }
    if (n > 1) cnt[n] += v;
}

void proc(int &n,int v)
{
    int i,j,k,m=1;
    for (i=1;prime[i]*prime[i]<=n;i++) if (n%prime[i] == 0){
        k = 0;
        for (;n%prime[i]==0;n/=prime[i]) k++;
        if (cnt[prime[i]]*v > 0){
            j = min(k,cnt[prime[i]]*v);
            cnt[prime[i]] -= j*v;
            while (j--) m *= prime[i];
        }
    }
    if (n > 1){
        if (cnt[n]*v > 0){
            j = min(1,cnt[n]*v);
            cnt[n] -= j*v;
            while (j--) m *= n;
        }
    }
    n = m;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin), freopen("output.txt","w",stdout);
#endif
    int i,j,k;
    prime[++pcnt] = 2;
    for (i=3;i<=MAXK;i+=2) if (!mem(i)){
        prime[++pcnt] = i;
        write(i);
        if (i > MAXK/i) continue;
        for (j=i*i;j<=MAXK;j+=i+i) write(j);
    }
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++) scanf("%d",A+i), reg(A[i],1);
    for (i=1;i<=M;i++) scanf("%d",B+i), reg(B[i],-1);
    for (i=1;i<=N;i++) proc(A[i],1);
    for (i=1;i<=M;i++) proc(B[i],-1);
    printf("%d %d\n",N,M);
    for (i=1;i<=N;i++) printf("%d ",A[i]); puts("");
    for (i=1;i<=M;i++) printf("%d ",B[i]);
}
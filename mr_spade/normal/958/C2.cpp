#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<bitset>
#include<stack>
#include<cassert>
#define F first
#define S second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define mem(x,y) memset(x,y,sizeof x)
#define sqr(x) ((x)*(x))
using namespace std;
typedef long long ll;
typedef double db;
const int INF=2e9;
const db eps=1e-8;
template<typename T>
inline void read(T &x)
{
    x=0; int f=1; char ch=getchar();
    while( (ch<'0' || ch>'9') && ch!='-') ch=getchar(); if(ch=='-') {f=-1; ch=getchar();}
    while(ch>='0' && ch <='9') x=x*10+ch-'0',ch=getchar();
    x*=f;
}
//====================cvgfdhrvs======head template==========================
#define int long long
const int N=20010,K=25,P=105;
int f[N][K],g[P];
int n,k,p;
int a[N];
int tmp[N];
inline void roll(int u) {
//	memmove(tmp,g,sizeof(g));
    for(int i=0;i<p;i++) tmp[i]=g[i];
    for(int i=0;i<p;i++)
        g[i]=tmp[(i-u+p)%p];
}
signed main()
{
    read(n); read(k); read(p);
    for(int i=1;i<=n;i++) read(a[i]),a[i]%=p;
    for(int i=1;i<=n;i++) f[i][1]=(f[i-1][1]+a[i])%p;
//	for(int i=1;i<=n;i++) printf("%lld ",a[i]); puts("");
    for(int j=2;j<=k;j++) {
        mem(g,-1); g[a[j]]=f[j-1][j-1];
        for(int i=j;i<=n;i++) {
//			printf("%lld %lld\n",j,i);
//	for(int ii=0;ii<p;ii++) printf("%lld ",g[ii]); puts("");
            
            for(int kk=0;kk<p;kk++)
                if(g[kk]!=-1) {
                    f[i][j]=max(f[i][j],g[kk]+kk);
                }
            g[0]=max(g[0],f[i][j-1]);
            roll(a[i+1]);
        }
    }
//	for(int j=1;j<=k;j++) {
//		for(int i=1;i<=n;i++)
//			printf("%lld ",f[i][j]);
//		puts("");
//	}
    printf("%lld\n",f[n][k]);
    return 0;
}
/*
6 6 4
6 6 6 6 6 6
*/
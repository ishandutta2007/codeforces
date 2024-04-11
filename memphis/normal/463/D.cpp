#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define LL long long
#define LB long double
#define mod 1000000007
using namespace std;
inline int lowbit(int x){return x&-x;}
inline int ABS(int x){return x<0?-x:x;}
inline LL ABS(LL x){return x<0?-x:x;}
inline void MAX(int &a,int b){if(b>a)a=b;}
inline void MAX(LL &a,LL b){if(b>a)a=b;}
inline void MIN(int &a,int b){if(b<a)a=b;}
inline void MIN(LL &a,LL b){if(b<a)a=b;}
int fast(int x,int v){int ans=1;for(;v;v>>=1,x=(LL)x*x%mod)if(v&1)ans=(LL)ans*x%mod;return ans;}
LL fast(LL x,LL v){LL ans=1;for(;v;v>>=1,x=x*x%mod)if(v&1)ans=ans*x%mod;return ans;}

#define N 2005


int n,m,ans,a[10][N],b[10][N],f[N];

int main(){
	
	
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i)
	    for (int j=1;j<=n;++j) scanf("%d",&a[i][j]);
    for (int i=1;i<=m;++i)
    	for (int j=1;j<=n;++j) b[i][a[i][j]]=j;
	for (int i=1;i<=n;++i){
		int ii=a[1][i];
		f[i]=1;
		for (int j=1;j<i;++j){
			bool ff=1;
			int jj=a[1][j];
			for (int k=2;k<=m;++k)
				if (b[k][jj]>b[k][ii]){
					ff=0;
					break;
				}
			if (ff) f[i]=max(f[i],f[j]+1);
		}
	}
	for (int i=1;i<=n;++i) ans=max(ans,f[i]);
	printf("%d\n",ans);
}
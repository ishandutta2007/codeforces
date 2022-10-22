#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=3010,mod=1e9+7;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
inline void add(int &x,int y){if((x+=y)>=mod)x-=mod;}
int f[maxn],g[maxn],m,n,x,y;
char s[maxn];
signed main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i){
		scanf("%s",s+1);
		for(ri j=1;j<=m;++j)
			if(s[j]!='#'){
				if(i==1&&j==2)f[j]=1;
				if(i==2&&j==1)g[j]=1;
				add(f[j],f[j-1]);
				add(g[j],g[j-1]);
			}
			else f[j]=g[j]=0;
		if(i+1==n)x=f[m],y=g[m];
	}
	printf("%d",((1ll*x*g[m-1]-1ll*f[m-1]*y)%mod+mod)%mod);
	return 0;
}
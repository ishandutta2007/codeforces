#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2010;
int a[maxn],ans,f[maxn][maxn],h,l,n,r,t_case;
int main(){
	scanf("%d%d%d%d",&n,&h,&l,&r);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	memset(f,-0x3f,sizeof f);
	f[0][0]=0;
	for(ri i=1;i<=n;++i)
		for(ri j=0;j<h;++j)
			ckmax(f[i][j],max(f[i-1][(j-a[i]+h)%h],f[i-1][(j-(a[i]-1)+h)%h])+(l<=j&&j<=r));
	for(ri i=0;i<h;++i)ckmax(ans,f[n][i]);
	printf("%d",ans);
	return 0;
}
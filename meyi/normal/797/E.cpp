#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxp=321,maxn=1e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
int a[maxn],ans[maxn][maxp],m,n;
int main(){
	scanf("%d",&n);
	ri lim=sqrt(n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	for(ri i=n;i;--i)
		for(ri j=lim;j;--j)
			ans[i][j]=(i+a[i]+j<=n?ans[i+a[i]+j][j]+1:1);
	scanf("%d",&m);
	while(m--){
		ri x,y;
		scanf("%d%d",&x,&y);
		if(y<=lim)printf("%d\n",ans[x][y]);
		else{
			ri cnt=0;
			while(x<=n)++cnt,x+=a[x]+y;
			printf("%d\n",cnt);
		}
	}
	return 0;
}
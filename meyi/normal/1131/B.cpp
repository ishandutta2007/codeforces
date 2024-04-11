#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int ans=1,m,n,t_case,x,y;
signed main(){
	scanf("%d",&n);
	for(ri i=1,a,b;i<=n;++i){
		scanf("%d%d",&a,&b);
		if(x==y)ans+=min(a,b)-x;
		if(x<y){
			x=min(a,y);
			if(x==y)ans+=max(min(a,b)-y+1,0);
		}
		if(x>y){
			y=min(b,x);
			if(x==y)ans+=max(min(a,b)-x+1,0);
		}
		x=a,y=b;
	}
	printf("%d",ans);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int h,hh,w,ww,t_case,x,xx,y,yy;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d%d%d%d%d%d",&w,&h,&x,&y,&xx,&yy,&ww,&hh);
		ri ans=INT_MAX,xl=xx-x,yl=yy-y;
		if(ww+xl<=w)ckmin(ans,ww-x),ckmin(ans,xx-(w-ww));
		if(hh+yl<=h)ckmin(ans,hh-y),ckmin(ans,yy-(h-hh));
		printf("%d\n",ans==INT_MAX?-1:max(ans,0));
	}
	return 0;
}
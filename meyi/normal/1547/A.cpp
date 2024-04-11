#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		ri x,xx,xxx,y,yy,yyy;
		scanf("%d%d%d%d%d%d",&x,&y,&xx,&yy,&xxx,&yyy);
		ri ans=abs(xx-x)+abs(yy-y);
		if((x==xx&&x==xxx&&((y<yyy&&yy>yyy)||(y>yyy&&yy<yyy)))
		||(y==yy&&y==yyy&&((x<xxx&&xx>xxx)||(x>xxx&&xx<xxx))))ans+=2;
		printf("%d\n",ans);
	}
	return 0;
}
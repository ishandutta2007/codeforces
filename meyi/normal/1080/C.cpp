#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
inline ll calc(ll x,ll y,bool w){return (x*y+w)>>1;}
inline ll calc(ll x,ll y,ll xx,ll yy,bool w){return calc(xx,yy,w)-calc(x-1,yy,w)-calc(xx,y-1,w)+calc(x-1,y-1,w);}
ll ansb,answ,m,n,x[7],y[7];
inline ll cross(){
	if(x[5]>x[6]||y[5]>y[6])return 0;
	return (x[6]-x[5]+1)*(y[6]-y[5]+1);
}
int t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%lld%lld",&n,&m);
		ansb=calc(n,m,0),answ=calc(n,m,1);
		for(ri i=1;i<5;++i)scanf("%lld%lld",x+i,y+i);
		x[5]=max(x[1],x[3]),x[6]=min(x[2],x[4]);
		y[5]=max(y[1],y[3]),y[6]=min(y[2],y[4]);
		ansb-=calc(x[1],y[1],x[2],y[2],0)+calc(x[3],y[3],x[4],y[4],0);
		answ-=calc(x[1],y[1],x[2],y[2],1)+calc(x[3],y[3],x[4],y[4],1);
		if(cross()){
			ansb+=calc(x[5],y[5],x[6],y[6],0);
			answ+=calc(x[5],y[5],x[6],y[6],1);
		}
		ansb+=(x[4]-x[3]+1)*(y[4]-y[3]+1);
		answ+=(x[2]-x[1]+1)*(y[2]-y[1]+1)-cross();
		printf("%lld %lld\n",answ,ansb);
	}
	return 0;
}
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int h,c,t;
inline double calc(ll k){
	return (double)(h*(k+1)+c*k)/(k*2+1);
}
int ans;
int main(){
	//freopen("in1.txt","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d%d",&h,&c,&t);
		for(int i=0;i<10;i++);
			//printf("%d calc %.2f\n",i,calc(i));
		int l=0,r=1e9;
		while(l<r){
			ll mid=l+r+1>>1;
			if(calc(mid)<=t) r=mid-1;
			else l=mid;
		}
		//printf("r %d\n",r);
		if(r<1e9&&min(fabs(calc(r)-t),fabs(calc(r+1)-t))<fabs((h+c)/2-t))
			ans=r+(fabs(calc(r+1)-t)<fabs(calc(r)-t)),ans=ans*2+1;
		else ans=2;
		printf("%d\n",ans);
	}
	return 0;
}
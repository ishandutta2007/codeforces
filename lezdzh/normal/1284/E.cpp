#include<cstdio>
#include<algorithm>
using namespace std;

struct dn{
	int x,y;
};
dn operator-(dn u,dn v){
	return(dn){u.x-v.x,u.y-v.y};
}
bool operator<(dn u,dn v){
	bool uu=u.y>0||u.y==0&&u.x>0,
		vv=v.y>0||v.y==0&&v.x>0;
	return uu!=vv?uu>vv:1ll*u.x*v.y-1ll*v.x*u.y>0;
}
dn a[2501],w[2501];
int wt;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	long long ans=0;
	for(int i=1;i<=n;i++){
		wt=0;
		for(int j=1;j<=n;j++)
			if(i!=j)w[++wt]=a[j]-a[i];
		sort(w+1,w+wt+1);
		ans+=1ll*wt*(wt-1)*(wt-2)*(wt-3)/24;
		for(int j=1;j<=wt;j++){
			int jj=lower_bound(w+1,w+wt+1,(dn){-w[j].x,-w[j].y})-w;
			int p;
			if(w[j].y>0||w[j].y==0&&w[j].x>0)
				p=jj-j-1;
			else p=wt-j+jj-1;
			ans-=1ll*p*(p-1)*(p-2)/6;
		}
	}
	printf("%lld\n",ans);
}
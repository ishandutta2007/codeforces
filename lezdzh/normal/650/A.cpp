#include<cstdio>
#include<algorithm>
using namespace std;

struct dn{int x,y;}a[200001];
bool cm1(dn u,dn v){
	return u.x^v.x?u.x<v.x:u.y<v.y;
}
bool cm2(dn u,dn v){
	return u.y<v.y;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cm1);
	long long ans=0;
	for(int i=1;i<=n;i++){
		int j=i+1;
		for(;j<=n&&a[i].x==a[j].x&&a[i].y==a[j].y;j++);
		ans-=1ll*(j-i-1)*(j-i)>>1;
		i=j-1;
	}
	for(int i=1;i<=n;i++){
		int j=i+1;
		for(;j<=n&&a[i].x==a[j].x;j++);
		ans+=1ll*(j-i-1)*(j-i)>>1;
		i=j-1;
	}
	sort(a+1,a+n+1,cm2);
	for(int i=1;i<=n;i++){
		int j=i+1;
		for(;j<=n&&a[i].y==a[j].y;j++);
		ans+=1ll*(j-i-1)*(j-i)>>1;
		i=j-1;
	}
	printf("%I64d\n",ans);
}
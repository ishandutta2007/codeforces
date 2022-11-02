#include<cstdio>
const int N=52;
int n,h,m,i,a[N],x,l,r,ans;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d%d%d",&n,&h,&m);
	for(i=1;i<=n;i++)
		a[i]=h;
	while(m--){
		scanf("%d%d%d",&l,&r,&x);
		for(i=l;i<=r;i++)
			a[i]=min(a[i],x);
	}
	for(i=1;i<=n;i++)
		ans+=a[i]*a[i];
	printf("%d",ans);
}
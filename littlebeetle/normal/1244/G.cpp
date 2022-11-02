#include<cstdio>
const int N=1000200;
typedef long long ll;
int n,a[N],mid,i,j;
ll k,ans;
void init(){
	scanf("%d%lld",&n,&k);
}
void swap(int &x,int &y){
	int t=x;x=y;y=t;
}
int max(int x,int y){
	return x>y?x:y;
}
void work(){
	if(1ll*(1+n)*n/2>k){
		printf("-1");
		return;
	}
	k-=1ll*(1+n)*n/2;
	for(i=1;i<=n;i++)
		a[i]=i;
	mid=n+1>>1;
	for(i=n;i>mid;i--){
		j=i-(n-i+1);
		if(j<=k)
			k-=j,
			swap(a[n-i+1],a[i]);
		else{
			j=i-k;
			swap(a[j],a[i]);
			break;
		}	
	}
	for(i=1;i<=n;i++)
		ans+=max(a[i],i);
	printf("%lld\n",ans);
	for(i=1;i<=n;i++)
		printf("%d ",i);
	printf("\n");
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
}
int main(){
	init();
	work();
	return 0;
}
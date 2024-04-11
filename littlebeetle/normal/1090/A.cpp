#include<cstdio>
int n,m,x,y,a,sum,i;
long long ans;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		y=0;
		sum+=m;
		for(i=0;i<m;i++){
			scanf("%d",&a);
			if(a>y)
			y=a;
		}
		ans-=1ll*m*y;
		if(y>x)
		x=y;
	}
	printf("%lld",ans+1ll*sum*x);
}
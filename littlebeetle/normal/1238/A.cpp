#include<cstdio>
int t;
long long x,y;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&x,&y);
		if(x==y+1)
			printf("NO\n");
		else
			printf("YES\n");
	}
}
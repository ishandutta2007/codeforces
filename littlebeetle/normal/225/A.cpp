#include<cstdio>
int n,k,a,b;
int main(){
	scanf("%d%d",&n,&k);
	k=7-k;
	while(n--){
		scanf("%d%d",&a,&b);
		if(a==k||b==k||(7-a==k)||(7-b==k)){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES");
}
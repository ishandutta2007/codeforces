#include<cstdio>
int a,b;
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		if(a%b) puts("NO");
		else puts("YES");
	}
	return 0;
}
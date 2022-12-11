#include<cstdio>

using namespace std;

int x[100001],y[100001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	if(n%2){
		printf("NO\n");
		return 0;
	}
	for(int i=1;i<=n/2;i++)
		if(!(x[i]+x[i+n/2]==x[1]+x[1+n/2]&&y[i]+y[i+n/2]==y[1]+y[1+n/2])){
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
}
#include<cstdio>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int z=a+b+c+d,ans=1;
	for(int i=1;i<=n-1;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a+b+c+d>z)ans++;
	}
	printf("%d\n",ans);
}
#include<cstdio>
#include<algorithm>
using namespace std;

int a[100001];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n,m,z;
		scanf("%d%d",&n,&m);
		z=-1;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			z=max(z,a[i]);
		}
		for(int i=1;i<=n;i++)
			if(a[i]==m){printf("1\n");goto ed;}
		printf("%d\n",(m+z-1)/z==1?m==z?1:2:(m+z-1)/z);
		ed:;
	}
}
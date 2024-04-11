#include<cstdio>
#include<algorithm>

using namespace std;

int a[101],b[101];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++)
			printf("%d%c",a[i],i==n?'\n':' ');
		for(int i=1;i<=n;i++)
			printf("%d%c",b[i],i==n?'\n':' ');
	}
}
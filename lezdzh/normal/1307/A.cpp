#include<cstdio>
#include<algorithm>
using namespace std;

int a[101];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=2;i<=n;i++){
			int w=min(a[i],m/(i-1));
			a[1]+=w;
			a[i]-=w;
			m-=(i-1)*w;
		}
		printf("%d\n",a[1]);
	}
}
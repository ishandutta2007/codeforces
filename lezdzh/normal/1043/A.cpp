#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int s=0,mx=0;
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		s+=a;
		mx=max(mx,a);
	}
	printf("%d\n",max((2*s+n)/n,mx));
}
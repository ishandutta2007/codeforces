#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,x,a,b;
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&x,&a,&b);
		printf("%d\n",min(n-1,abs(a-b)+x));
	}
	return 0;
}
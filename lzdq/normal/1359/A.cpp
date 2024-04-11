#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d%d",&n,&m,&k);
		int a=m-(n/k);
		if(a<0) a=0;
		//printf("a %d\n",a);
		printf("%d\n",min(m,n/k)-(a+k-2)/(k-1));
	}
	return 0;
}
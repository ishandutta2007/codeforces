#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int n,m;
bool Solve(){
	if(n>m) return puts("No"),0;
	if(n&1){
		puts("Yes");
		for(int i=1; i<n; i++)
			printf("1 ");
		printf("%d\n",m-(n-1));
		return 1;
	}
	if(!(m&1)){
		puts("Yes");
		for(int i=1; i<=n-2; i++)
			printf("%d ",1);
		printf("%d ",m-(n-2)>>1);
		printf("%d\n",m-(n-2)>>1);
		return 1;
	}
	puts("No");
	return 0;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		Solve();
	}
	return 0;
}
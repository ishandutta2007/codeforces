#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int n;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		n>>=1;
		int ans=1<<n*2;
		ans+=(1<<n)-2;
		ans-=(1<<2*n)-(1<<n);
		printf("%d\n",ans);
	}
	return 0;
}
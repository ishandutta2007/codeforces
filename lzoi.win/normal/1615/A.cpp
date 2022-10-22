#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,sum;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		sum=0;
		for(int i=1; i<=n; i++){
			int a;
			scanf("%d",&a);
			sum+=a;
		}
		if(sum%n==0) puts("0");
		else puts("1");
	}
	return 0;
}
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		int ans=0;
		while(n){
			ans=max(ans,n%10);
			n/=10;
		}
		printf("%d\n",ans);
	}
	return 0;
}
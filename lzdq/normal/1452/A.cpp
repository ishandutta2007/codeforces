#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m,a[MAXN];
int ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		printf("%d\n",n+m+max(0,abs(n-m)-1));
	}
	return 0;
}
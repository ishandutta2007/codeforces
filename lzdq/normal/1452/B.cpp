#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m,a[MAXN];
int ans,mx;
ll s;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		mx=s=0;
		for(int i=1; i<=n; i++)
			scanf("%d",a+i),mx=max(mx,a[i]),s+=a[i];
		if(s-mx<(n-2ll)*mx) printf("%lld\n",(n-2ll)*mx-s+mx);
		else if(s%(n-1)) printf("%lld\n",(s+n-2)/(n-1)*(n-1)-s);
		else puts("0");
	}
	return 0;
}
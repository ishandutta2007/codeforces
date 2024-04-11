#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int t_case;
ll a,m,n;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%lld%lld%lld",&n,&m,&a);
		ll x=(a-1)%n+1,y=(a-x)/n+1;
		printf("%lld\n",(x-1)*m+y);
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T;ll n;
void solve(){
	scanf("%lld",&n);
	if((n&1)||n<4){printf("-1\n");return;}
	if(n==4||n==6){printf("1 1\n");return;}
	printf("%lld %lld\n",(n-1)/6+1,n/4);
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
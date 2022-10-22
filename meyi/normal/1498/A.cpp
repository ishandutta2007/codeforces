#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int t_case;
ll n;
inline ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
inline ll sum(ll k){
	ll ret=0;
	while(k)ret+=k%10,k/=10;
	return ret;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%lld",&n);
		while(gcd(n,sum(n))==1)++n;
		printf("%lld\n",n);
	}
	return 0;
}
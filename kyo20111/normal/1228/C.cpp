#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,ans=1,mod=1e9+7;
unordered_set<int> st;
ll pw(ll a,ll b){
	if(b == 0) return 1;
	if(b == 1) return a;
	ll F = pw(a, b/2) % mod;
	return F * F % mod * (b%2 ? a : 1) % mod;
}
ll f(ll p,ll n){
	ll cnt = 0;
	while(p <= n){
		cnt += n/p;
		n/=p;
	}
	return pw(p, cnt);
}
int main(){
    scanf("%lld %lld",&a,&b);
    for(ll i=2;i*i<=a;i++){
    	if(a%i == 0) st.insert(i);
    	while(a%i == 0) a/=i;
    }
    if(a != 1) st.insert(a);

    for(int x : st) ans = ans * f(x, b) % mod;
    printf("%lld",ans);
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll phi(ll n, ll m) {
    ll result = n;
    for (ll i = 2; i * i <= m; i++) {
        if(m % i == 0) {
            while(m % i == 0)
                m /= i;
            result -= result / i;
        }
    }
    if(m > 1)
        result -= result / m;
    return result;
}
int main(){
	scanf("%d",&t);
	while(t--){
		ll a, b; scanf("%lld %lld",&a,&b);
		ll g = __gcd(a, b);
		a /= g, b /= g;
		printf("%lld\n",phi(a+b-1,b)-phi(a-1,b));
	}
}
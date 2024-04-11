#include <iostream>
using namespace std;
typedef long long int ll;

ll f(ll x){return (x + 1) * (x + 2) / 2;}
ll solve(ll a, ll b, ll c, ll l){
	ll ret = 0LL;
	for(ll la = 0LL; la <= l; ++ la){
		if(min(a - b - c + la, l - la) < 0) continue;
		ret += f(min(a - b - c + la, l - la));
	}
	return ret;
}
int main(){
	ll a, b, c, l;
	cin >> a >> b >> c >> l;
	cout << (l + 1) * (l + 2) * (l + 3) / 6 - solve(a, b, c, l) - solve(b, a, c, l) - solve(c, a, b, l) << endl;
	return 0;
}
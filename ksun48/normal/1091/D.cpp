#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 998244353;

int main(){
	LL n;
	cin >> n;
	LL f = 1;
	LL ans = 0;
	for(LL i = 1; i <= n; i++){
		f *= (n+1 - i);
		f %= MOD;
		ans += f;
		ans %= MOD;
	}
	LL g = (n+1) * f;
	g -= ans;
	g %= MOD;
	if(g < 0) g += MOD;
	g %= MOD;
	cout << g << endl;
}
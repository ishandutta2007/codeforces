#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 20000005;

lint minCut(lint n, lint a, lint b, lint m, lint k){
	lint ret = 5e18;
	for(auto &p : {0ll, (n + 1) / 2}){
		for(auto &q : {0ll, n / 2}){
			for(auto &r : {0ll, m}){
				ret = min(ret, p * a + q * b + r * k + (n - p - q) * (m - r));
			}
		}
	}
	return ret;
}

int main(){
	lint t, n, a, b, k;
	cin >> t >> n >> a >> b >> k;
	if(n < k){
		puts("0");
		return 0;
	}
	lint s = 0, e = t;
	while(s != e){
		lint m = (s + e + 1) / 2;
		if(minCut(n, a, b, m, k) == m * k) s = m;
		else e = m - 1;
	}
	cout << s << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL solve(LL n){
	set<LL> f;
	for(LL b = 0; b < 9; b++){
		for(LL c = 0; c < 49; c++){
			for(LL d = 0; b + c + d <= n; d++){
				f.insert(4*b+9*c+49*d);
			}
		}
	}
	return f.size();
}
int main(){
	LL n;
	cin >> n;
	if(n <= 100){
		cout << solve(n) << '\n';
	} else {
		cout << solve(100) + 49*(n-100) << '\n';
	}
}
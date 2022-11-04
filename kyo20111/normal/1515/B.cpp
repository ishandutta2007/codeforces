#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

bool f(int x){
	int k = sqrt(x);
	return k * k == x;
}

void solve(){
	cin >> n;
	if((n % 2 == 0 && f(n / 2)) || (n % 4 == 0 && f(n / 4))) cout << "YES";
	else cout << "NO";
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int tc = 1; cin >> tc;
	while(tc--) solve(), cout << "\n";
}
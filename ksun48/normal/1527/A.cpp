#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	int a = 1;
	while(a * 2 <= n) a *= 2;
	cout << (a - 1) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
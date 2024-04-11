#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	sort(a.rbegin(), a.rend());
	int asum = 0;
	for(int x : a) asum += x;
	if(a[0] > asum - a[0] || asum % 2 == 1){
		cout << "T" << '\n';
	} else {
		cout << "HL" << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
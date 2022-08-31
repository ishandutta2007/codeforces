#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> x(n);
	for(int& a : x) cin >> a;
	set<int> r;
	for(int a : x) for(int b : x) if(b > a) r.insert(b-a);
	cout << r.size() << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int a, b;
	cin >> a >> b;
	int n = (a + b);
	int x = n / 2;
	int y = (n+1) / 2;
	set<int> val;
	for(int _ = 0; _ < 2; _++){
		for(int z = min(a, x) + min(b, y); z >= max(a + x, b + y) - n; z -= 2) val.insert(n - z);
		swap(a, b);
	}
	cout << val.size() << '\n';
	for(int z : val){
		cout << z << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
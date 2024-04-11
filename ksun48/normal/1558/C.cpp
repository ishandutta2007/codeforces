#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a){
		cin >> x;
		x--;
	}
	vector<int> res;
	while(n > 1){
		int x = n-2;
		int y = n-1;
		int lx = 0;
		int ly = 0;
		auto set_val = [&](){
			lx = 0;
			ly = 0;
			while(a[lx] != x) lx++;
			while(a[ly] != y) ly++;
		};
		set_val();
		if(((x - lx) & 1) || ((y - ly) & 1)){
			cout << -1 << '\n';
			return;
		}
		res.push_back(ly + 1);
		reverse(a.begin(), a.begin() + ly + 1);
		set_val();
		res.push_back(lx);
		reverse(a.begin(), a.begin() + lx);
		set_val();
		res.push_back(lx + 2);
		reverse(a.begin(), a.begin() + lx + 2);
		set_val();
		res.push_back(3);
		reverse(a.begin(), a.begin() + 3);
		res.push_back(n);
		reverse(a.begin(), a.begin() + n);
		n -= 2;
	}
	cout << res.size() << '\n';
	for(int r : res){
		cout << r << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<string> b(m);
	for(int j = 0; j < m; j++) cin >> b[j];
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int x;
		cin >> x;
		x--;
		cout << a[x % n] << b[x % m] << '\n';
	}
}
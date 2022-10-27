#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, r;
	cin >> n >> r;
	vector <int> a(pow(2, n));
	int sum = 0;
	int t = 1;
	for(int i = 0; i < pow(2, n); i++){
		cin >> a[i];
		sum += a[i];
	}
	cout << fixed << setprecision(10) << sum * 1.0 / (a.size())  << "\n";
	for(int i = 0; i < r; i++){
		int id, val;
		cin >> id >> val;
		sum += val - a[id];
		a[id] = val;
		cout << fixed << setprecision(10) << sum * 1.0 / (a.size()) << "\n";
	}
	return 0;
}
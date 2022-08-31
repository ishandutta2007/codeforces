#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<LL> a(2*n);
	for(int i = 0; i < 2*n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	LL v1 = a[n-1] - a[0];
	LL v2 = a[2*n-1] - a[n];
	LL d = v1 * v2;
	for(int i = 0; i + n-1 < 2*n; i++){
		d = min(d, (a[2*n-1] - a[0]) * (a[i+n-1] - a[i]));
	}
	cout << d << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<LL> a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	if(a[0] != b[0]){
		cout << "No" << '\n';
		return 0;
	}
	vector<int> c, d;
	for(int i = 0; i + 1 < n; i++){
		c.push_back(a[i+1] - a[i]);
		d.push_back(b[i+1] - b[i]);
	}
	sort(c.begin(), c.end());
	sort(d.begin(), d.end());
	if(c == d){
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
	}
	return 0;
}
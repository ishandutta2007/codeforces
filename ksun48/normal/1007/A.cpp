#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	multiset<int> r;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	int ans = 0;
	for(int i = 0; i < n; i++){
		r.insert(a[i]);
		if(r.upper_bound(a[i]) != r.end()){
			r.erase(r.upper_bound(a[i]));
			ans++;
		}
	}
	cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int& x : a) cin >> x;
	for(int& x : b) cin >> x;
	map<int,int> freq;
	reverse(b.begin(), b.end());
	reverse(a.begin(), a.end());
	int ai = 0;
	int bi = 0;
	while(bi < n){
		int x = b[bi];
		freq[x]++;
		bi++;
		while(bi < n && b[bi] == x){
			freq[x]++;
			bi++;
		}
		while(ai < n && a[ai] != x){
			freq[a[ai]]--;
			if(freq[a[ai]] < 0){
				cout << "NO" << '\n';
				return;
			}
			ai++;
		}
		if(ai >= n){
			cout << "NO" << '\n';
			return;
		}
		freq[a[ai]]--;
		ai++;
	}
	cout << "YES" << '\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
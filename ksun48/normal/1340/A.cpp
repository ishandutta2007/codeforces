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
	set<int> where;
	multiset<int> freq;
	where.insert(-1);
	for(int i = 0; i <= n; i++){
		where.insert(i);
		freq.insert(1);
	}
	where.erase(n);
	vector<int> invp(n);
	for(int i = 0; i < n; i++){
		invp[a[i]] = i;
	}
	for(int j = 0; j < n; j++){
		int x = invp[j];
		auto r = where.find(x);
		int pdiff = x - *prev(r);
		if(pdiff != *freq.rbegin()){
			cout << "No" << '\n';
			return;
		}
		freq.erase(freq.find(pdiff));
		if(next(r) != where.end()){
			int ndiff = *next(r) - x;
			freq.erase(freq.find(ndiff));
			freq.insert(pdiff + ndiff);
		}
		where.erase(r);
	}
	cout << "Yes" << '\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
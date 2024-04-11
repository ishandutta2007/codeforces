#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, l, r, a[200200];

void solve(){
	cin >> n >> l >> r;
	for(int i=1;i<=n;i++) cin >> a[i];

	multiset<int> sl, sr;
	for(int i=1;i<=n;i++){
		if(i <= l) sl.insert(a[i]);
		else sr.insert(a[i]);
	}

	int ans = 0;
	vector<int> er;

	for(auto x : sl){
		auto it = sr.find(x);
		if(it != sr.end() && *it == x){
			sr.erase(it);
			er.push_back(x);
			l--, r--;
		}
	}
	for(auto x : er) sl.erase(sl.find(x));

	if(l < r) swap(l, r), swap(sl, sr);

	for(auto it = sl.begin(); l != r && it != sl.end() && next(it) != sl.end(); ){
		if(*it == *next(it)){
			it = sl.erase(it);
			it = sl.erase(it);
			ans++, l -= 2;
		}else{
			it++;
		}
	}

	int A = sl.size(), B = sr.size();

	cout << ans + max(A, B);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int tc = 1; cin >> tc;
	while(tc--) solve(), cout << "\n";
}
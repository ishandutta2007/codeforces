#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	vector<int> del;

	set<int> songs_left;
	set<int> bad_songs_left;
	for(int i = 0; i < n; i++){
		int r = (i+1) % n;
		if(gcd(a[i], a[r]) == 1) bad_songs_left.insert(i);
	}
	for(int i = 0; i < n; i++) songs_left.insert(i);
	int cur = 0;
	while(songs_left.size() > 1 && !bad_songs_left.empty()){
		auto v = bad_songs_left.lower_bound(cur);
		if(v == bad_songs_left.end()) v = bad_songs_left.begin();
		int k = *v;
		assert(songs_left.count(k));

		auto w = next(songs_left.find(k));
		if(w == songs_left.end()) w = songs_left.begin();
		int l = *w;
		del.push_back(l);
		bad_songs_left.erase(l);
		songs_left.erase(l);
		bad_songs_left.erase(k);

		if(songs_left.size() == 1) break;

		auto g = next(songs_left.find(k));
		if(g == songs_left.end()) g = songs_left.begin();
		if(gcd(a[*g], a[k]) == 1){
			bad_songs_left.insert(k);
		}

		cur = l;
	}
	if(songs_left.size() == 1){
		int r = *songs_left.begin();
		if(a[r] == 1) del.push_back(r);
	}
	cout << del.size();
	for(int d : del){
		cout << ' ' << (d+1);
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
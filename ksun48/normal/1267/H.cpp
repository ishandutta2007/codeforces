#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<pair<int,int> > z(n);
	for(int i = 0; i < n; i++){
		cin >> z[i].second;
		z[i].second--;
		z[i].first = i;
	}
	sort(z.begin(), z.end());

	vector<int> a(n, -1);
	int d = 1;
	while(!z.empty()){
		set<int> v;
		v.insert(-1); v.insert(n);
		for(pair<int, int> r : z) v.insert(r.second);
		reverse(z.begin(), z.end());

		vector<pair<int,int> > newz;
		set<int> bad;
		for(pair<int,int> r : z){
			int x = r.second;
			v.erase(x);
			if(bad.count(x)){
				newz.push_back(r);
			} else {
				a[x] = d;
				bad.insert(*prev(v.lower_bound(x)));
				bad.insert(*v.lower_bound(x));
			}
		}
		reverse(newz.begin(), newz.end());
		z = newz;
		assert(d <= 18);
		d++;
	}
	for(int s : a) cout << s << ' ';
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}
#include <bits/stdc++.h>
using namespace std;

int ask(vector<int> a, vector<int> b){
	cout << a.size() << ' ' << b.size();
	for(int x : a) cout << ' ' << x;
	for(int x : b) cout << ' ' << x;
	cout << '\n' << flush;
	int ans;
	cin >> ans;
	return ans;
}

void solve(){
	int n;
	cin >> n;
	vector<int> q;
	for(int i = 2; i <= n; i++) q.push_back(i);
	int d = ask({1}, q);
	while(q.size() > 1){
		vector<int> r;
		vector<int> s;
		for(int i = 0; i < q.size(); i++){
			if(i & 1){
				r.push_back(q[i]);
			} else {
				s.push_back(q[i]);
			}
		}
		if(ask({1}, r) == d){
			q = r;
		} else {
			q = s;
		}
	}
	int b = q[0];
	vector<int> z;
	for(int i = 1; i <= n; i++){
		if(i != b) z.push_back(i);
	}
	int ans = ask({b}, z);
	cout << -1 << ' ' << ans << '\n';
	cout << flush;
}


int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		solve();
	}
}
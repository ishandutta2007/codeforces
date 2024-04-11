#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> s){
	int cnt = 0;
	for(int x : s) cnt += x;
	if(cnt == 0){
		cout << -1 << '\n';
		return;
	}
	int st = cnt;
	while(cnt > 1 && __builtin_clz(st) == __builtin_clz(cnt-1)) st++;
	vector<pair<int,int> > ivals;
	int n = (int)s.size();
	while(true){
		int extra = st - cnt;
		int f = 0;
		auto score = [&](int x){
			return x - __builtin_popcount(x);
		};
		while(f < n){
			if(s[f] == 0){
				ivals.push_back({f, f});
				f++;
				continue;
			}
			int cur = 0;
			int g = f;
			while(g < n){
				if(score(cur * 2 + s[g]) <= extra){
					cur = cur * 2 + s[g];
					g++;
				} else {
					break;
				}
			}
			assert(g >= f);
			extra -= score(cur);
			ivals.push_back({f, g-1});
			f = g;
		}
		if(extra == 0){
			break;
		} else {
			st *= 2;
			ivals = {};
		}
	}
	cout << ivals.size() << '\n';
	for(auto [a, b] : ivals){
		cout << (a+1) << ' ' << (b+1) << '\n';
	}
}

void test(){
	for(int i = 1; ; i++){
		vector<int> s;
		int c = i;
		while(c){
			s.push_back(c & 1);
			c /= 2;
		}
		reverse(s.begin(), s.end());
		solve(s);
	}
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	// test();
	int T;
	cin >> T;
	while(T--){
		string _s;
		cin >> _s;
		vector<int> s;
		for(char c : _s) s.push_back(c - '0');
		solve(s);
	}
}
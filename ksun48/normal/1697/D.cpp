#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	auto ask = [&](int l, int r){
		cout << "? 2 " << (l+1) << ' ' << (r+1) << '\n';
		cout << flush;
		int x;
		cin >> x;
		return x;
	};
	auto gc = [&](int l) -> int {
		cout << "? 1 " << (l+1) << '\n';
		cout << flush;
		char c;
		cin >> c;
		return int(c-'a');
	};
	vector<int> s;
	vector<int> last_occ(26, -1);
	while((int)s.size() < n){
		int cur = (int)s.size();
		vector<int> occs;
		for(int i = 0; i < 26; i++){
			if(last_occ[i] >= 0){
				occs.push_back(last_occ[i]);
			}
		}
		sort(occs.begin(), occs.end());
		int st = -1;
		int en = (int)occs.size();
		while(st + 1 < en){
			int m = (st + en) / 2;
			int loc = occs[m];
			int expected = (int)occs.size() - m + 1;
			int r = ask(loc, cur);
			if(r == expected - 1){
				st = m;
			} else if(r == expected){
				en = m;
			} else assert(false);
		}
		if(st == -1){
			s.push_back(gc(cur));
		} else {
			s.push_back(s[occs[st]]);
		}
		last_occ[s[cur]] = cur;
	}
	cout << "! ";
	for(int x : s){
		cout << char(x + 'a');
	}
	cout << '\n';
}
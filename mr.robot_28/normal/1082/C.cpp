#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

int n, m;
vector<int> s, r;

inline bool read() {
	if(!(cin >> n >> m))
		return false;
	s.assign(n, 0);
	r.assign(n, 0);
	
	fore(i, 0, n) {
		assert(cin >> s[i] >> r[i]);
		s[i]--;
	}
	return true;
}

vector< vector<int> > subs;

inline void solve() {
	subs.assign(m + 1, vector<int>());
	
	fore(i, 0, n)
		subs[s[i]].push_back(r[i]);
		
	fore(id, 0, sz(subs)) {
		sort(subs[id].begin(), subs[id].end());
		reverse(subs[id].begin(), subs[id].end());
	}
	
	vector<int> mx(n + 5, 0);
	fore(id, 0, sz(subs)) {
		int curSum = 0;
		fore(i, 0, sz(subs[id])) {
			curSum += subs[id][i];
			if(curSum < 0)
				break;
				
			mx[i + 1] += curSum;
		}
	}
	
	cout << *max_element(mx.begin(), mx.end()) << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	cout << fixed << setprecision(15);
	
	if(read()) {
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}
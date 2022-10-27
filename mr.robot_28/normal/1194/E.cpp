#include <bits/stdc++.h>

using namespace std;

#define mp make_pair

const int N = 10009;
const int INF = 1000000009;
 
int n;
vector <pair<int, int> > vs[N], hs[N];
int f[N];
vector <int> d[N];

void upd(int pos, int x){
	for(; pos < N; pos |= pos + 1)
		f[pos] += x;
}

int get(int pos){
	int res = 0;
	for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
		res += f[pos];
	return res;
}

int get(int l, int r){
	return get(r) - get(l - 1);
}

const int D = 5000;

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += D, y1 += D, x2 += D, y2 += D; 
		if(y1 == y2) 
			hs[y1].push_back( mp(min(x1, x2), max(x1, x2)) );	
		else 
			vs[x1].push_back( mp(min(y1, y2), max(y1, y2)) );	
	}

	long long res = 0;
	for(int y = 0; y < N; ++y) for(auto s : hs[y]){
		for(int i = 0; i < N; ++i) d[i].clear();
		memset(f, 0, sizeof f);

		int l = s.first, r = s.second;
		for(int x = l; x <= r; ++x) for(auto s2 : vs[x])
			if(s2.first <= y && s2.second > y) {
				d[s2.second].push_back(x);
				upd(x, 1);
			}

		for(int y2 = y + 1; y2 < N; ++y2){
			for(auto s2 : hs[y2]){			
				int cur = get(s2.first, s2.second);
				res += cur * (cur - 1) / 2;
			}
			for(auto x : d[y2]) upd(x, -1);
		}
	}

	cout << res << endl;
	return 0;
}
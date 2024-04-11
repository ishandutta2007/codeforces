#include <bits/stdc++.h>
using namespace std;

using B = bitset<2100>;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	vector<B> stuff(n);
	vector<B> prefixes(m+1);
	for(int i = 1; i <= m; i++){
		prefixes[i] = prefixes[i-1];
		prefixes[i].flip(i-1);
	}
	set<pair<int,int> > z;
	z.insert({-1, -1});
	z.insert({m+1, n});

	int i1, i2, j1, j2;

	auto check = [&](int a, int b){
		if(a < 0 || a >= n || b < 0 || b >= n) return;
		int diff = (int)(stuff[a] ^ stuff[b]).count();
		int ca = (int)stuff[a].count();
		int cb = (int)stuff[b].count();
		if(diff == abs(ca - cb)) return;
		B r1 = stuff[a] & (~stuff[b]);
		B r2 = stuff[b] & (~stuff[a]);
		i1 = a;
		i2 = b;
		j1 = (int)r1._Find_first();
		j2 = (int)r2._Find_first();
	};
	for(int i = 0; i < n; i++){
		z.insert({0, i});
	}
	set<pair<int,int> > ok;
	for(int _ = 0; _ < q; _++){
		int i, l, r;
		cin >> i >> l >> r;
		i--;
		l--;
		r--;
		int c = (int)stuff[i].count();
		auto b = z.find({c, i});
		ok.insert({(*prev(b)).second, (*next(b)).second});
		z.erase(b);

		stuff[i] ^= prefixes[l];
		stuff[i] ^= prefixes[r+1];

		c = (int)stuff[i].count();
		z.insert({c, i});
		b = z.find({c, i});
		ok.insert({(*prev(b)).second, (*b).second});
		ok.insert({(*b).second, (*next(b)).second});

		i1 = i2 = j1 = j2 = -1;
		while(!ok.empty()){
			pair<int,int> a = *ok.begin();
			check(a.first, a.second);
			if(i1 >= 0) break;
			ok.erase(ok.begin());
		}

		if(i1 == -1){
			cout << -1 << '\n';
		} else {
			if(i1 > i2) swap(i1, i2);
			if(j1 > j2) swap(j1, j2);
			assert(stuff[i1][j1] == stuff[i2][j2]);
			assert(stuff[i1][j2] == stuff[i2][j1]);
			assert(stuff[i1][j1] != stuff[i1][j2]);
			cout << i1 + 1 << " " << j1 + 1 << " " << i2 + 1 << " " << j2 + 1 << '\n';
		}
	}
}
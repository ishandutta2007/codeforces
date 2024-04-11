#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	using ll = long long;

	int p, q;
	cin >> p >> q;
	vector<vector<ll> > level_sums(p+1);
	for(int b = 0; b <= p; b++) level_sums[b].assign(1 << b, 0);
	for(int i = 0; i < (1 << p); i++) cin >> level_sums[p][i];
	for(int b = p-1; b >= 0; b--){
		for(int i = 0; i < (1 << b); i++){
			level_sums[b][i] = level_sums[b+1][i << 1] + level_sums[b+1][(i << 1) ^ 1];
		}
	}
	auto upd = [&](int x, ll v){
		for(int b = p; b >= 0; b--) level_sums[b][x >> (p-b)] += v;
	};
	int xor_idx = 0;
	auto query = [&](int l, int r) -> ll {
		r++;
		int cidx = xor_idx;
		ll ret = 0;
		for(int b = p; b >= 0; b--){
			if(l == r) break;
			if(l & 1){
				ret += level_sums[b][l ^ cidx];
				l++;
			}
			if(r & 1){
				r--;
				ret += level_sums[b][r ^ cidx];
			}
			l >>= 1;
			r >>= 1;
			cidx >>= 1;
		}
		assert(l == r);
		return ret;
	};
	for(int _ = 0; _ < q; _++){
		int type;
		cin >> type;
		if(type == 1){
			int x;
			ll v;
			cin >> x >> v;
			x--;
			v -= query(x, x);
			upd(xor_idx ^ x, v);
		} else if(type == 2){
			int k;
			cin >> k;
			xor_idx ^= (1 << k) - 1;
		} else if(type == 3){
			int k;
			cin >> k;
			xor_idx ^= (1 << k);
		} else if(type == 4){
			int l, r;
			cin >> l >> r;
			l--; r--;
			ll ans = query(l, r);
			cout << ans << '\n';
		}
	}
}
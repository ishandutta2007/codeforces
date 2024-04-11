#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
ll powmod(ll a, ll b, ll m) {
	assert(b >= 0);
	ll r = 1; while (b) { if (b & 1) r = (r * a) % m; b >>= 1; a = (a * a) % m; } return r % m;
}

struct D {
	int free;
	int val;
	int dim;
};

D merge(D x, D y){
	if(x.free == -1 || y.free == -1) return {-1, 0, 0};
	return {x.free || y.free, x.val ^ y.val, x.dim + y.dim + int(x.free && y.free)};
}
D eq(D x, D y){
	if(x.free == -1 || y.free == -1) return {-1, 0, 0};
	if(!x.free && !y.free && x.val != y.val) return {-1, 0, 0};
	return {x.free && y.free, x.free ? y.val : x.val, x.dim + y.dim};
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m, t, w;
	cin >> n >> m >> t >> w;
	vector<int> status(n, -1);
	int v2 = __builtin_ctz(n);

	t = min(t, 1 << v2);

	int rt = min(t, (1 << v2) - 1);

	vector<vector<D> > val(v2+1);
	for(int i = 0; i <= v2; i++){
		val[i].assign(1 << i, {0, 0, 0});
	}
	vector<int> n2free(1 << v2, n >> v2);
	vector<int> n2sum(1 << v2, 0);
	auto set_val = [&](int v, D state, bool update){
		val[v2][v] = state;
		if(update){
			for(int i = v2-1; i >= 0; i--){
				if(v & (1 << i)) v ^= (1 << i);
				if(rt & (1 << i)){
					val[i][v] = eq(val[i+1][v], val[i+1][v + (1 << i)]);
				} else {
					val[i][v] = merge(val[i+1][v], val[i+1][v + (1 << i)]);
				}
			}
		}
	};
	auto recomp = [&](int dloc, bool update){
		set_val(dloc, {n2free[dloc] > 0, n2sum[dloc], max(n2free[dloc] - 1, 0)}, update);
	};
	auto upd = [&](int d, int v, bool update){
		int dloc = d % (1 << v2);
		if(status[d] >= 0){
			n2free[dloc] += 1;
			n2sum[dloc] ^= status[d];
			status[d] = -1;
		}
		if(v >= 0){
			status[d] = v;
			n2free[dloc] -= 1;
			n2sum[dloc] ^= status[d];
		}
		recomp(dloc, update);
	};
	for(int dloc = 0; dloc < (1 << v2); dloc++){
		recomp(dloc, false);
	}
	for(int i = 0; i < m; i++){
		int d, v;
		cin >> d >> v;
		d--;
		upd(d, v, false);
	}
	for(int i = v2-1; i >= 0; i--){
		for(int v = 0; v < (1 << i); v++){
			if(rt & (1 << i)){
				val[i][v] = eq(val[i+1][v], val[i+1][v + (1 << i)]);
			} else {
				val[i][v] = merge(val[i+1][v], val[i+1][v + (1 << i)]);
			}
		}
	}
	int Q;
	cin >> Q;
	for(int i = 0; i < Q; i++){
		int d, v;
		ll p;
		cin >> d >> v >> p;
		d--;
		upd(d, v, true);
		D root = val[0][0];
		if(t == (1 << v2)) root = eq(root, {0, 0, 0});
		if(root.free == -1){
			cout << 0 << '\n';
		} else {
			ll f = ll(w) * ll(root.dim + root.free);
			cout << powmod(2, f, p) << '\n';
		}
	}
}
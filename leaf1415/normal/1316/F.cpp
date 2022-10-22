#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#define llint long long
#define inf 1e18
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

llint beki[300005];

struct Data{
	llint a, sl, sr, n;
	Data(){}
	Data(llint x, llint b, llint c, llint d){
		a = x, sl = b, sr = c, n = d;
	}
};

Data merge(Data &d1, Data &d2)
{
	Data ret;
	ret.a = d1.a * beki[d2.n] % mod + d2.a * beki[d1.n] % mod + d1.sl * d2.sr % mod, ret.a %= mod;
	ret.sl = d1.sl + d2.sl * beki[d1.n] % mod, ret.sl %= mod;
	ret.sr = d2.sr + d1.sr * beki[d2.n] % mod, ret.sr %= mod;
	ret.n = d1.n + d2.n;
	return ret;
}

struct SegTree{
	int size;
	vector<Data> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = Data(0, 0, 0, 0);
	}
	
	void update(int i, Data val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = merge(seg[i*2], seg[i*2+1]);
		}
	}

	Data query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return Data(0, 0, 0, 0);
		if(a <= l && r <= b) return seg[k];
		Data lval = query(a, b, k*2, l, (l+r)/2);
		Data rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return merge(lval, rval);
	}
	Data query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

llint n, Q;
llint a[300005];
llint p[300005], x[300005];
vector<P> vec;
llint ppos[300005], qpos[300005];
SegTree seg(20);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	cin >> Q;
	for(int q = 1; q <= Q; q++) cin >> p[q] >> x[q];
	
	beki[0] = 1;
	for(int i = 1; i <= n; i++) beki[i] = beki[i-1] * 2, beki[i] %= mod;
	
	for(int i = 1; i <= n; i++) vec.push_back(P(a[i], -i));
	for(int q = 1; q <= Q; q++) vec.push_back(P(x[q], q));
	sort(vec.begin(), vec.end());
	for(int i = 0; i < vec.size(); i++){
		if(vec[i].second > 0) qpos[vec[i].second] = i;
		else ppos[-vec[i].second] = i;
	}
	
	llint N = vec.size();
	llint div = modpow(modpow(2, n), mod-2) % mod;
	
	seg.init();
	for(int i = 0; i < vec.size(); i++){
		if(vec[i].second > 0) continue;
		seg.update(i, Data(0, vec[i].first, vec[i].first, 1));
	}
	llint ans = seg.query(0, N).a;
	cout << ans * div % mod << endl;
	
	for(int q = 1; q <= Q; q++){
		seg.update(ppos[p[q]], Data(0, 0, 0, 0));
		ppos[p[q]] = qpos[q];
		seg.update(ppos[p[q]], Data(0, x[q], x[q], 1));
		ans = seg.query(0, N).a;
		cout << ans * div % mod << "\n";
	}
	flush(cout);
	
	return 0;
}
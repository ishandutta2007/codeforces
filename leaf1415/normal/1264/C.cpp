#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#define llint long long
#define mod 998244353

using namespace std;

struct Task{
	llint a, b, c;
	Task(){}
	Task(llint x, llint y, llint z){
		a = x, b = y, c = z;
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


Task merge(Task t1, Task t2)
{
	Task ret;
	ret.a = t1.a + t2.a*t1.b%mod, ret.a %= mod;
	ret.b = t1.b*t2.b, ret.b %= mod;
	ret.c = t1.c*t2.c, ret.c %= mod;
	return ret;
}

struct SegTree{
	int size;
	vector<Task> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = Task(0, 1, 1);
	}
	
	void update(int i, Task val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = merge(seg[i*2], seg[i*2+1]);
		}
	}

	Task query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return Task(0, 1, 1);
		if(a <= l && r <= b) return seg[k];
		Task lval = query(a, b, k*2, l, (l+r)/2);
		Task rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return merge(lval, rval);
	}
	Task query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

int n, Q;
llint p[200005];
set<llint> S;
llint mul[200005];
SegTree seg(18);

llint getPrev(llint x)
{
	auto it = S.lower_bound(x);
	it--;
	return *it;
}
llint getNext(llint x)
{
	auto it = S.upper_bound(x);
	return *it;
}

llint calc(Task t)
{
	llint ret = (1+t.a);
	ret += mod-t.b, ret %= mod;
	ret *= t.c, ret %= mod;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	for(int i = 1; i <= n; i++) cin >> p[i];
	
	llint inv100 = modpow(100, mod-2);
	for(int i = 1; i <= n; i++){
		p[i] *= inv100, p[i] %= mod;
	}
	
	seg.init();
	for(int i = 1; i <= n; i++) seg.update(i, Task(p[i], p[i], modpow(p[i], mod-2)));
	
	S.insert(1); S.insert(n+1);
	mul[1] = calc(seg.query(1, n));
	llint ans = mul[1];
	
	int u;
	for(int q = 0; q < Q; q++){
		cin >> u;
		llint l = getPrev(u), r = getNext(u);
		if(S.count(u)){
			ans += mod - mul[u], ans %= mod;
			mul[u] = 0;
			ans += mod - mul[l], ans %= mod;
			mul[l] = calc(seg.query(l, r-1));
			ans += mul[l], ans %= mod;
			S.erase(u);
		}
		else{
			ans += mod - mul[l], ans %= mod;
			mul[l] = calc(seg.query(l, u-1));
			mul[u] = calc(seg.query(u, r-1));
			ans += mul[l], ans %= mod;
			ans += mul[u], ans %= mod;
			S.insert(u);
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}
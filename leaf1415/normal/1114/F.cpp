#include <iostream>
#include <vector>
#define llint long long
#define mod 1000000007

using namespace std;

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


struct SegTreeMul{
	llint size;
	vector<llint> seg, delay;
	
	SegTreeMul(){}
	SegTreeMul(llint size){
		this->size = size;
		seg.resize(1<<(size+1));
		delay.resize(1<<(size+1));
	}
	
	void init()
	{
		for(llint i = 0; i < (1<<(size+1)); i++){
			seg[i] = 1;
			delay[i] = 1;
		}
	}
	
	void eval(llint l, llint r, llint k)
	{
		if(delay[k] > 1){
			seg[k] *= modpow(delay[k], r-l+1), seg[k] %= mod;
			if(l < r){
				delay[k*2] *= delay[k], delay[k*2] %= mod;
				delay[k*2+1] *= delay[k], delay[k*2+1] %= mod;
			}
			delay[k] = 1;
		}
	}
	
	void update(llint i, llint val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = seg[i*2] * seg[i*2+1] % mod;
		}
	}
	
	void add(llint a, llint b, llint k, llint l, llint r, llint val)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			delay[k] *= val, delay[k] %= mod;
			eval(l, r, k);
			return;
		}
		add(a, b, k*2, l, (l+r)/2, val);
		add(a, b, k*2+1, (l+r)/2+1, r, val);
		seg[k] = seg[k*2] * seg[k*2+1] % mod;
	}
	void add(llint a, llint b, llint val){
		if(a > b) return;
		add(a, b, 1, 0, (1<<size)-1, val);
	}

	llint query(llint a, llint b, llint k, llint l, llint r)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return 1;
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return lval * rval % mod;
	}
	llint query(llint a, llint b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

struct SegTreeOR{
	llint size;
	vector<llint> seg, delay;
	
	SegTreeOR(){}
	SegTreeOR(llint size){
		this->size = size;
		seg.resize(1<<(size+1));
		delay.resize(1<<(size+1));
	}
	
	void init()
	{
		for(llint i = 0; i < (1<<(size+1)); i++){
			seg[i] = 0;
			delay[i] = 0;
		}
	}
	
	void eval(llint l, llint r, llint k)
	{
		if(delay[k]){
			seg[k] |= delay[k];
			if(l < r){
				delay[k*2] |= delay[k];
				delay[k*2+1] |= delay[k];
			}
			delay[k] = 0;
		}
	}
	
	void update(llint i, llint val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = seg[i*2] | seg[i*2+1];
		}
	}
	
	void add(llint a, llint b, llint k, llint l, llint r, llint val)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			delay[k] |= val;
			eval(l, r, k);
			return;
		}
		add(a, b, k*2, l, (l+r)/2, val);
		add(a, b, k*2+1, (l+r)/2+1, r, val);
		seg[k] = seg[k*2] | seg[k*2+1];
	}
	void add(llint a, llint b, llint val){
		if(a > b) return;
		add(a, b, 1, 0, (1<<size)-1, val);
	}

	llint query(llint a, llint b, llint k, llint l, llint r)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return 0;
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return lval | rval;
	}
	llint query(llint a, llint b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

llint n, Q;
llint a[400005];
bool prime[305];
vector<llint> pvec;
llint fact[305], revp[305];
SegTreeMul seg(19);
SegTreeOR seg2(19);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(llint i = 2; i <= 300; i++){
		if(prime[i]) continue;
		for(llint j = 2*i; j <= 300; j+=i) prime[j] = true;
	}
	for(llint i = 2; i <= 300; i++) if(!prime[i]) pvec.push_back(i);
	
	for(llint i = 1; i <= 300; i++){
		for(llint j = 0; j < pvec.size(); j++){
			if(i % pvec[j] == 0) fact[i] |= (1LL<<j);
		}
	}
	for(int i = 0; i < pvec.size(); i++) revp[pvec[i]] = modpow(pvec[i], mod-2);
	
	cin >> n >> Q;
	for(llint i = 1; i <= n; i++) cin >> a[i];
	
	seg.init(), seg2.init();
	for(llint i = 1; i <= n; i++) seg.update(i, a[i]);
	for(llint i = 1; i <= n; i++) seg2.update(i, fact[a[i]]);
	
	string s; llint l, r, x;
	for(llint q = 0; q < Q; q++){
		cin >> s;
		if(s == "MULTIPLY"){
			cin >> l >> r >> x;
			seg.add(l, r, x);
			seg2.add(l, r, fact[x]);
		}
		if(s == "TOTIENT"){
			cin >> l >> r;
			llint m = seg.query(l, r);
			llint k = seg2.query(l, r);
			for(llint i = 0; i < pvec.size(); i++){
				if(k & (1LL<<i)){
					m *= pvec[i] - 1, m %= mod;
					m *= revp[pvec[i]], m %= mod;
				}
			}
			cout << m << "\n";
		}
	}
	flush(cout);
	
	return 0;
}
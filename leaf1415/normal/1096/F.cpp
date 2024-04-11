#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long
#define mod 998244353

using namespace std;

struct BIT{
	int size;
	vector<llint> bit;
	BIT(){size = 0;}
	BIT(int s){
		size = s;
		bit.resize(size+1);
		init();
	}
	void init(){
		for(int i = 1; i <= size; i++) bit[i] = 0;
	}
	int query(int i){
		llint ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&(-i);
		}
		return ret;
	}
	void add(int i, llint x){
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};

llint n;
llint p[200005];
llint qcnt;
llint rcnt[200005];
bool used[200005];
BIT bit(200005);

llint fact[200005], fact_inv[200005];

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

void make_fact()
{
	llint val = 1;
	fact[0] = 1;
	for(int i = 1; i < 200005; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	for(int i = 0; i < 200005; i++){
		fact_inv[i] = modpow(fact[i], mod-2);
	}
}

llint comb(llint n, llint k)
{
	llint ret = 1;
	ret *= fact[n];
	ret *= fact_inv[k], ret %= mod;
	ret *= fact_inv[n-k], ret %= mod;
	return ret;
}

llint calc()
{
	bit.init();
	llint q = 0, ret = 0;
	for(int i = 1; i <= n; i++){
		if(p[i] == -1) q++;
		else{
			ret += q * rcnt[p[i]] % mod;
			ret %= mod;
		}
	}
	return ret;
}

int main(void)
{
	make_fact();
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> p[i];
	
	for(int i = 1; i <= n; i++) if(p[i] == -1) qcnt++;
	for(int i = 1; i <= n; i++) if(p[i] != -1) used[p[i]] = true;
	for(int i = n; i >= 1; i--){
		rcnt[i] = rcnt[i+1];
		if(!used[i]) rcnt[i]++;
	}
	
	llint ans = 0, q = 0;
	for(int i = 1; i <= n; i++){
		if(p[i] == -1){
			q++;
			continue;
		}
		ans += (i-1) - bit.query(p[i]) - q;
		ans %= mod;
		bit.add(p[i], 1);
	}
	ans *= fact[qcnt], ans %= mod;
	
	if(qcnt >= 2){
		ans += comb(qcnt, 2) * comb(qcnt, 2) % mod * fact[qcnt-2] % mod, ans %= mod;
	}
	
	ans += calc() * fact[qcnt-1] % mod, ans %= mod;
	reverse(p+1, p+n+1);
	for(int i = 1; i <= n; i++){
		rcnt[i] = rcnt[i-1];
		if(!used[i]) rcnt[i]++;
	}
	ans += calc() * fact[qcnt-1] % mod, ans %= mod;
	
	ans *= fact_inv[qcnt], ans %= mod;
	cout << ans << endl;
	return 0;
}
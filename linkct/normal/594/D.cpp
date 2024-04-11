#include <cstdio>
#include <algorithm>
#include <vector>
#define fi first
#define se second
using namespace std;
typedef long long int LL;
typedef pair <int, int> pii;
const int MAXN = 200005, MAXV = 1000005;
const LL MOD = 1000000007LL;

struct Queries{
	int l, r, id;
	bool operator < (const Queries &rhs) const{
		return l < rhs.l;
	}
}q[MAXN];
int n, m, seq[MAXN], low[MAXV], prime[MAXV], maxv, cur[MAXV], pcnt;
LL bit[MAXV], inv[MAXV], ans[MAXN];
bool isComp[MAXV];
vector <pii> next[MAXN];

inline LL getInv(LL base){
	LL ret = 1; int times = MOD - 2;
	while(times){
		if(times & 1) ret = ret * base % MOD;
		base = base * base % MOD;
		times >>= 1;
	}
	return ret;
}
inline void update(int pos, LL val){
	for(; pos <= maxv; pos += pos & -pos)
		bit[pos] = bit[pos] * val % MOD;
}
inline LL query(int pos){
	LL ret = 1LL;
	for(; pos; pos -= pos & -pos)
		ret = ret * bit[pos] % MOD;
	return ret;
}
int main(){
	int i, j, tmp;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &seq[i]);
		if(seq[i] > maxv) maxv = seq[i];
	} inv[1] = bit[1] = 1LL;
	for(i = 2; i <= maxv; ++ i){
		if(!isComp[i]){
			prime[++ pcnt] = i;
			low[i] = i;
		}
		for(j = 1; LL(prime[j]) * i <= maxv; ++ j){
			isComp[i * prime[j]] = true;
			low[i * prime[j]] = prime[j];
			if(i % prime[j] == 0) break;
		}
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		bit[i] = 1LL;
	}
	for(i = n; i >= 1; -- i){
		update(i, seq[i]);
		while(seq[i] != 1){
			tmp = low[seq[i]];
			while(seq[i] % tmp == 0) seq[i] /= tmp;
			next[i].push_back(pii(tmp, cur[tmp]));
			cur[tmp] = i;
		}
	}
	scanf("%d", &m);
	for(i = 1; i <= m; ++ i){
		scanf("%d%d", &q[i].l, &q[i].r);
		q[i].id = i;
	}
	sort(q + 1, q + 1 + m);
	for(i = 1; i <= maxv; ++ i)
		if(cur[i]) update(cur[i], (i - 1) * inv[i] % MOD);
	for(i = 1, j = 1; i <= m; ++ i){
		while(j < q[i].l){
			while(!next[j].empty()){
				if(next[j].back().se) update(next[j].back().se, (next[j].back().fi - 1) * inv[next[j].back().fi] % MOD);
				next[j].pop_back();
			}
			++ j;
		}
		ans[q[i].id] = query(q[i].r) * getInv(query(j - 1)) % MOD;
	}
	for(i = 1; i <= m; ++ i) printf("%I64d\n", ans[i]);
	return 0;
}
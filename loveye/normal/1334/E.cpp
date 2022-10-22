#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
#define int long long
int D,q,C[105][105],cnt[105];
vector<int> siz;
int gcd(int a,int b) {
	return b == 0 ? a : gcd(b,a % b);
}
inline int solve(int x) {
	if(x == 1) return 1;
	int res = 1,sum = 0;
	for(int i = 0;i < (long long)(siz.size());++i) {
		cnt[i] = 0;
		while(x % siz[i] == 0) x /= siz[i],++cnt[i];
		sum += cnt[i];
		res = res * C[sum][cnt[i]] % MOD;
	}
	return res;
}
signed main() {
	scanf("%lld%lld",&D,&q);
	int sx = sqrt(D) + 0.5;
	for(int i = 2;i <= sx;++i) {
		if(D % i == 0) {
			siz.push_back(i);
			do
			{
				D /= i;
			}while(D % i == 0);
		}
	}
	if(D != 1) siz.push_back(D);
	C[0][0] = 1; 
	for(int i = 1;i <= 100;++i) {
		C[i][0] = 1;
		for(int j = 1;j <= i;++j)
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
	}
	while(q--) {
		static int u,v,g;
		scanf("%lld%lld",&u,&v);g = gcd(u,v);
		printf("%lld\n",solve(u/g) * solve(v/g) % MOD);
	}
	return 0;
}
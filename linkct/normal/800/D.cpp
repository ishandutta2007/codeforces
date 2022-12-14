#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005, MOD = 1000000007, LEN = 6;
typedef long long int LL;

int n, cnt[MAXN], base[9], sum[MAXN], ssum[MAXN], ans[MAXN];
LL pow2[MAXN];

inline int getInt(){
	char x; int ret;
	while((x = getchar()) < '0' || x > '9') ;
	ret = x - '0';
	while((x = getchar()) >= '0' && x <= '9')
		ret = ret * 10 - '0' + x;
	return ret;
}
inline void update(int &a, int b){if((a += b) >= MOD) a -= MOD;}
inline void nupdate(int &a, int b){if((a -= b) < 0) a += MOD;}
int main(){
	int i, j; LL answer = 0LL;
	n = getInt();
	pow2[0] = 1LL;
	for(i = 1; i <= n; ++ i){
		if((pow2[i] = pow2[i - 1] << 1) >= MOD)
			pow2[i] -= MOD;
		j = getInt();
		ssum[j] = (2 * ssum[j] + 2LL * j * sum[j] + (pow2[cnt[j]] * j % MOD) * j) % MOD;
		sum[j] = (2 * sum[j] + pow2[cnt[j]] * j) % MOD;
		++ cnt[j];
	}
	base[1] = 1;
	for(i = 2; i <= LEN + 1; ++ i)
		base[i] = base[i - 1] * 10;
	for(i = 1; i <= 6; ++ i)
		for(j = base[LEN + 1] - 1; j >= 0; -- j){
			if(((j / base[i]) % 10) == 9) continue;
			ssum[j] = (ssum[j] * pow2[cnt[j + base[i]]] + ssum[j + base[i]] * pow2[cnt[j]] + 2LL * sum[j] * sum[j + base[i]]) % MOD;
			sum[j] = (sum[j] * pow2[cnt[j + base[i]]] + sum[j + base[i]] * pow2[cnt[j]]) % MOD;
			cnt[j] += cnt[j + base[i]];
		}
	for(i = 6; i; -- i)
		for(j = 0; j < base[LEN + 1]; ++ j)
			if(((j / base[i]) % 10) != 9 && (ssum[j] -= ssum[j + base[i]]) < 0)
				ssum[j] += MOD;
	for(i = 0; i < base[LEN + 1]; ++ i)
		answer ^= LL(ssum[i]) * i;
	printf("%I64d\n", answer);
	return 0;
}
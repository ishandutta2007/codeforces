#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long int ll;
const int MAXK = 5005, MAXN = 300005;

int n, k, seq[MAXN];
ll dp[2][MAXK];

void update(ll &a, ll b){if(a > b) a = b;}
int main(){
	int i, j, t, m;
	ll *now, *past, *tmp;
	scanf("%d%d", &n, &k);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &seq[i]);
	sort(seq + 1, seq + 1 + n);
	t = n % k, m = n / k;
	now = dp[1]; past = dp[0];
	memset(past, 0x3f, sizeof(dp[0]));
	past[0] = 0LL;
	for(i = 0; i < k; ++ i){
		memset(now, 0x3f, sizeof(dp[0]));
		for(j = 0; j <= t; ++ j){
			update(now[j], past[j] - seq[i * m + j + 1] + seq[(i + 1) * m + j]);
			if(j < t) update(now[j + 1], past[j] - seq[i * m + j + 1] + seq[(i + 1) * m + j + 1]);
		}
		tmp = now, now = past, past = tmp;
	}
	printf("%I64d\n", past[t]);
	return 0;
}
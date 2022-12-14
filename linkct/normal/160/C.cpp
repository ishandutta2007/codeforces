#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;
typedef long long int LL;
const int MAXN = 100005;

int n, m, seq[MAXN], cnt[MAXN], val[MAXN]; LL k;

int main(){
	//freopen("sorting.in", "r", stdin);
	//freopen("sorting.out", "w", stdout);
	int i, j;
	assert(scanf("%d%I64d", &n, &k) == 2);
	for(i = 1; i <= n; ++ i){
		assert(scanf("%d", &seq[i]) == 1);
		//assert(seq[i] > 0);
	} sort(seq + 1, seq + 1 + n);
	for(i = 1; i <= n; ++ i)
		if(i == 1 || seq[i] != seq[i - 1]){
			val[++ m] = seq[i];
			cnt[m] = 1;
		}else ++ cnt[m];
	for(i = 1; i <= m; k -= LL(cnt[i ++]) * n)
		if(k <= LL(cnt[i]) * n)
			for(j = 1; j <= m; k -= LL(cnt[i]) * cnt[j ++])
				if(k <= LL(cnt[i]) * cnt[j]){
					printf("%d %d\n", val[i], val[j]);
					return 0;
				}
	return 0;
}
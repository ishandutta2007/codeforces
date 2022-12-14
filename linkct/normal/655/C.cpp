#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

int q[MAXN], head, tail, n, k;
char str[MAXN];

int main(){
	int i, ans, j, pos;
	scanf("%d%d%s", &n, &k, str + 1);
	ans = n;
	for(i = 1; i <= n; ++ i){
		if(str[i] == '1') continue;
		q[++ tail] = i;
		if(tail - head == k + 1){
			pos = lower_bound(q + head + 1, q + tail + 1, (q[head + 1] + q[tail]) / 2) - q;
			for(j = max(pos - 1, head + 1); j <= tail && j <= pos + 3; ++ j)
				ans = min(ans, max(q[j] - q[head + 1], q[tail] - q[j]));
			++ head;
		}
	}
	printf("%d\n", ans);
	return 0;
}
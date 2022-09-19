#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, k, a[300005], cnt[300005], x, y;
void solve()
{
	scanf("%d%d", &n, &k);
	rep1(i, n) scanf("%d", &a[i]);
	
	x = 1; y = n;
	rep1(i, n) cnt[i] = 0;
	rep1(i, n) cnt[a[i]] ++;
	int s = 0, l = 1;
	rep1(i, n) {
		s += cnt[i];
		while((s - cnt[l]) * 2 >= n + k) s -= cnt[l ++];
		if(s * 2 >= n + k && i - l < y - x) {
			x = l; y = i; 
		}
	}
	
	printf("%d %d\n", x, y);
	s = l = 0;
	int pre = 1;
	rep1(i, n) {
		s += a[i] >= x && a[i] <= y ? 1 : -1;
		if(l < k && s > l) {
			l ++;
			printf("%d %d\n", pre, l == k ? n : i);
			pre = i + 1;
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}
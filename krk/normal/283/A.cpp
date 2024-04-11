#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

ll BIT[Maxn];
int n;
ll sum, cnt = 1;

ll Get(int x)
{
	ll res = 0ll;
	for (int i = x; i < Maxn; i += i & -i)
		res += BIT[i];
	return res;
}

void Insert(int x, ll val)
{
	for (int i = x; i > 0; i -= i & -i)
		BIT[i] += val;
}

int main()
{
	scanf("%d", &n);
	while (n--) {
		int t; scanf("%d", &t);
		if (t == 1) {
			int a, x; scanf("%d %d", &a, &x);
			Insert(a, x); sum += a * x;
		} else if (t == 2) {
			int k; scanf("%d", &k);
			cnt++;
			Insert(cnt, k); Insert(cnt - 1, -k); sum += k;
		} else {
			ll val = Get(cnt); sum -= val;
			Insert(cnt, -val); Insert(cnt - 1, val);
			cnt--;
		}
		printf("%.9lf\n", double(sum) / double(cnt));
	}
	return 0;
}
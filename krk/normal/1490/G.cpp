#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

int T;
int n, m;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		vector <lli> seq;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			sum += a;
			if (seq.empty() || sum > seq.back().first)
				seq.push_back(lli(sum, i));
		}
		for (int i = 0; i < m; i++) {
			int a; scanf("%d", &a);
			if (a <= seq.back().first) {
				int ind = lower_bound(seq.begin(), seq.end(), lli(a, 0)) - seq.begin();
				printf("%d", seq[ind].second);
			} else if (sum <= 0) printf("-1");
			else {
				ll fulls = (a - seq.back().first - 1) / sum + 1;
				int ind = lower_bound(seq.begin(), seq.end(), lli(a - fulls * sum, 0)) - seq.begin();
				printf("%I64d", fulls * ll(n) + ll(seq[ind].second));
			}
			printf("%c", i + 1 < m? ' ': '\n');
		}
	}
    return 0;
}
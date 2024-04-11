#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;

int T;
int n;
ii a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i].first);
			a[i].second = i + 1;
			sum += a[i].first;
		}
		sort(a, a + n);
		vector <int> seq;
		int pnt = n - 2;
		sum -= a[n - 1].first;
		while (pnt >= 0 && sum >= a[pnt + 1].first) {
			sum -= a[pnt].first;
			pnt--;
		}
		for (int i = pnt + 1; i < n; i++)
			seq.push_back(a[i].second);
		sort(seq.begin(), seq.end());
		printf("%d\n", int(seq.size()));
		for (int i = 0; i < seq.size(); i++)
			printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
	}
    return 0;
}
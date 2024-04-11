#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef unsigned int uint;

const int Maxn = 70005;
const int Maxb = 32;
const int Maxm = Maxn / Maxb + 1;

int n, s;
ii a[Maxn];
uint dp[2][Maxm];
int fir[Maxn];
bool tk[Maxn];
int got[Maxn], res[Maxn];

int main()
{
	scanf("%d %d", &n, &s);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].first); a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	if (a[n].first > s) printf("-1\n");
	else {
		s -= a[n].first;
		dp[0][0] = 1;
		int cur = 0;
		for (int i = 1; i < n; i++) {
			cur = !cur;
			fill(dp[cur], dp[cur] + Maxm, 0);
			int d = a[i].first % Maxb;
			int c = Maxb - d;
			if (d == 0)
				for (int j = 0, npos = a[i].first; j < Maxm && npos <= s; j++, npos += Maxb)
					dp[cur][npos / Maxb] |= dp[!cur][j];
			else for (int j = 0; j < Maxm; j++) {
					int npos = j * Maxb + a[i].first;
					if (npos <= s)
						dp[cur][npos / Maxb] |= (dp[!cur][j] & uint((1 << c) - 1)) << d;
					npos = j * Maxb + c + a[i].first;
					if (npos <= s)
						dp[cur][npos / Maxb] |= dp[!cur][j] >> c;
			}
			for (int j = 0; j < Maxm; j++) {
				uint ch = ~dp[!cur][j] & dp[cur][j]; dp[cur][j] |= dp[!cur][j];
				if (ch)
					for (int l = 0; l < Maxb; l++)
						if (ch & uint(1) << l && j * Maxb + l <= s) fir[j * Maxb + l] = i;
			}
		}
		if (s && !fir[s]) printf("-1\n");
		else {
			while (s) {
				tk[fir[s]] = true; s -= a[fir[s]].first;
			}
			got[a[1].second] = a[1].first;
			for (int i = 1; i < n; i++) 
				if (!tk[i]) { got[a[i + 1].second] = a[i + 1].first - a[i].first; res[a[i + 1].second] = a[i].second; }
				else got[a[i + 1].second] = a[i + 1].first;
			for (int i = 1; i <= n; i++) {
				printf("%d ", got[i]);
				if (res[i]) printf("%d %d\n", 1, res[i]);
				else printf("0\n");
			}
		}
	}
	return 0;
}
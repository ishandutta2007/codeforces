#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 515;
const int Maxm = 2 * Maxn;
const int Maxw = 1005;

int n, S;
int in[Maxn], out[Maxn], w[Maxn], s[Maxn], v[Maxn];
int srt[Maxn];
int res[Maxn][Maxw];
vector <int> un;
vector <int> inpos[Maxm];
int dp[Maxm];

void calcDP(int myind, int l, int r, int S, int v)
{
	for (int al = 0; al <= S; al++) {
		for (int i = l; i <= r; i++)
			dp[i] = 0;
		dp[l] = v;
		for (int i = l; i < r; i++) {
			dp[i + 1] = max(dp[i + 1], dp[i]);
			for (int k = 0; k < inpos[i].size(); k++) {
				int ind = inpos[i][k];
				if (w[ind] > al || out[ind] > r) continue;
				int add = res[ind][min(al - w[ind], s[ind])];
				dp[out[ind]] = max(dp[out[ind]], dp[i] + add);
			}
		}
		res[myind][al] = dp[r];
	}
	inpos[l].push_back(myind);
}

bool Less(const int &aind, const int &bind)
{
	int difa = out[aind] - in[aind];
	int difb = out[bind] - in[bind];
	if (difa != difb) return difa < difb;
	return in[aind] < in[bind];
}

int main()
{
	scanf("%d %d", &n, &S);
	in[0] = 0; out[0] = 2 * n; w[0] = 0; s[0] = S; v[0] = 0; un.push_back(in[0]); un.push_back(out[0]);
	srt[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d %d %d", &in[i], &out[i], &w[i], &s[i], &v[i]); 
		un.push_back(in[i]); un.push_back(out[i]);
		srt[i] = i;
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 0; i <= n; i++) {
		in[i] = lower_bound(un.begin(), un.end(), in[i]) - un.begin();
		out[i] = lower_bound(un.begin(), un.end(), out[i]) - un.begin();
	}
	sort(srt, srt + n + 1, Less);
	for (int i = 0; i <= n; i++)
		calcDP(srt[i], in[srt[i]], out[srt[i]], s[srt[i]], v[srt[i]]);
	printf("%d\n", res[0][S]);
	return 0;
}
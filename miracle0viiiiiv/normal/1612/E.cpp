#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m[200005], k[200005];
double ans;
vector<int> cw;

PII cnt[200005];
void calc(int x)
{
	rep1(i, 200000) cnt[i] = MP(0, i);
	double ca = 0;
	rep1(i, n) cnt[m[i]].first += min(k[i], x);
	sort(cnt + 1, cnt + 200001);
	reverse(cnt + 1, cnt + 200001);
	rep1(i, x) ca += cnt[i].first;
	ca /= x;
	if(ca > ans) {
		ans = ca;
		cw.clear(); rep1(i, x) cw.push_back(cnt[i].second);
	}
}

int main()
{
	scanf("%d", &n);
	rep1(i, n) scanf("%d%d", &m[i], &k[i]);
	rep1(i, 20) calc(i);
	printf("%d\n", (int)cw.size());
	rep(i, cw.size()) printf("%d ", cw[i]);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int maxn = 105;
const int inf = 4 * maxn;

vector<int> gr[maxn];
vector<vector<pair2<int>>> ans[maxn];
int n;
vector<int> answer;
int sz[maxn];
pair2<int> tmp[2 * maxn];
int k;

inline void upd(int &a, int b)
{
	a = min(a, b);
}

void go(int cur)
{
	sz[cur] = 1;
	ans[cur].resize((int)gr[cur].size() + 1);
	auto &curans = ans[cur][0];
	curans.resize(2);
	curans[0].fi = 0;
	curans[0].se = 0;
	curans[1].fi = 0;
	curans[1].se = 0;
	for (int sid = 0; sid < (int)gr[cur].size(); sid++)
	{
		int t = gr[cur][sid];
		go(t);
		
		auto &curans = ans[cur][sid + 1];
		curans.resize(sz[cur] + sz[t] + 1);
		for (int i = 0; i <= sz[cur] + sz[t]; i++)
		{
			tmp[i] = {inf, inf};
		}
		for (int i = 0; i <= sz[cur]; i++)
		{
			tmp[i].fi = ans[cur][sid][i].fi;
			tmp[i].se = ans[cur][sid][i].se;
		}
		for (int i = 0; i <= sz[cur]; i++)
		{
			for (int j = 0; j <= sz[t]; j++)
			{
				upd(tmp[j + 1].fi, ans[t].back()[j].fi + 1);
				upd(tmp[j + 1].se, ans[t].back()[j].se + 2);
				
				upd(tmp[i + j].fi, ans[cur][sid][i].se + ans[t].back()[j].fi + 1);
				upd(tmp[i + j].fi, ans[cur][sid][i].fi + ans[t].back()[j].se + 2);
				upd(tmp[i + j].se, ans[cur][sid][i].se + ans[t].back()[j].se + 2);
			}
		}
		for (int i = 0; i <= sz[cur] + sz[t]; i++)
		{
			curans[i] = tmp[i];
		}
		
		sz[cur] += sz[t];
		
	}
}

void restore(int cur, int needk, int needret)
{
	//cout << "restore " << cur << ' ' << needk << ' ' << needret << endl;
	answer.pb(cur);
	pair2<int> gonoret = {-1, -1};
	for (int sid = (int)gr[cur].size() - 1; sid >= 0; sid--)
	{
		//if (needk == 1) break;
		int t = gr[cur][sid];
		bool found = false;
		//cout << cur << ' ' << sid << ' ' << needk << ' ' << t << endl;
		for (int i = 1; i < (int)ans[cur][sid].size() && !found; i++)
		{
			int j = needk - i;
			if (j < 0 || j > sz[t]) continue;
			if (j == 0)
			{
				if (needret && ans[cur][sid][i].se == ans[cur][sid + 1][i].se)
				{
					found = true;
					break;
				}
				if (!needret && ans[cur][sid][i].fi == ans[cur][sid + 1][i].fi)
				{
					found = true;
					break;
				}
			} else
			{
				if (needret)
				{
					if (ans[cur][sid][i].se + ans[t].back()[j].se + 2 == ans[cur][sid + 1][needk].se)
					{
						restore(t, j, true);
						answer.pb(cur);
						found = true;
						needk -= j;
					}
				} else
				{
					//cout << "check " << j << ' ' << ans[cur][sid + 1][needk].fi << endl;
					//cout << "opts " << ans[cur][sid][i].fi + ans[t].back()[j].se + 2 << ' ' << ans[cur][sid][i].se + ans[t].back()[j].fi + 1 << endl;
					if (ans[cur][sid][i].fi + ans[t].back()[j].se + 2 == ans[cur][sid + 1][needk].fi)
					{
						restore(t, j, true);
						answer.pb(cur);
						found = true;
						needk -= j;
					} else
					if (ans[cur][sid][i].se + ans[t].back()[j].fi + 1 == ans[cur][sid + 1][needk].fi)
					{
						gonoret = {t, j};
						found = true;
						needk -= j;
						needret = true;
					}
				}
			}
		}
		assert(found);
	}
	assert(needk == 1);
	if (gonoret.fi != -1) restore(gonoret.fi, gonoret.se, false);
}

void solve()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) gr[i].clear();
	for (int i = 0; i < n - 1; i++)
	{
		int x;
		scanf("%d", &x);
		gr[x - 1].pb(i + 1);
	}
	go(0);
	//printf("%d\n", ans[0].back()[k].fi);
	//return;
	answer.clear();
	restore(0, k, false);
	printf("%d ", (int)answer.size() - 1);
	for (auto t : answer) printf("%d ", t + 1);
	printf("\n");
	//fflush(stdout);
}

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T = 0; T < NT; T++)
	{
		solve();
	}
    return 0;
}
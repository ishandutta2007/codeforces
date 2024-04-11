#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 100005;

int n;
int c[Maxn], s[Maxn];
map <int, int> cfreq;
vector <ii> cind;
vector <ii> cubes[Maxn];
ll best[Maxn];
int par[Maxn];
ll res = -Inf;
int bi, bj;
vector <int> seq;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &c[i], &s[i]);
		cfreq[c[i]]++;
	}
	for (map <int, int>::iterator it = cfreq.begin(); it != cfreq.end(); it++)
		cind.push_back(ii(it->second, it->first));
	sort(cind.begin(), cind.end());
	for (int i = 1; i <= n; i++) {
		int ind = lower_bound(cind.begin(), cind.end(), ii(cfreq[c[i]], c[i])) - cind.begin();
		cubes[ind].push_back(ii(s[i], i));
	}
	for (int i = 0; i < cind.size(); i++)
		sort(cubes[i].rbegin(), cubes[i].rend());
	fill(best, best + Maxn, -Inf);
	for (int i = cind.size() - 1; i >= 0; i--) {
		ll sum = 0ll;
		for (int j = 0; j < cubes[i].size(); j++)
			sum += cubes[i][j].first;
		if (best[cubes[i].size()] != -Inf && sum + best[cubes[i].size()] > res) {
			res = sum + best[cubes[i].size()]; bi = i; bj = par[cubes[i].size()];
		}
		if (best[cubes[i].size() + 1] != -Inf && sum + best[cubes[i].size() + 1] > res) {
			res = sum + best[cubes[i].size() + 1]; bi = i; bj = par[cubes[i].size() + 1];
		}
		sum = 0ll;
		for (int j = 0; j < cubes[i].size(); j++) {
			sum += cubes[i][j].first;
			if (sum > best[j + 1]) { best[j + 1] = sum; par[j + 1] = i; }
		}
	}
	printf("%I64d\n", res);
	for (int i = 0; i < cubes[bi].size(); i++) {
		seq.push_back(cubes[bj][i].second); seq.push_back(cubes[bi][i].second);
	}
	if (cubes[bj].size() > cubes[bi].size()) seq.push_back(cubes[bj][cubes[bi].size()].second);
	printf("%d\n", seq.size());
	for (int i = 0; i < seq.size(); i++)
		printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
	return 0;
}
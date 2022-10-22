#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ii, int> iii;
typedef pair <int, ll> ill;

const int Maxn = 2005;
const int Maxq = 1000005;

int n, m, k;
vector <iii> gar[Maxn];
bool on[Maxn];
int q;
vector <ill> mygar[Maxn];
int typ[Maxq], a[Maxq], b[Maxq], c[Maxq], d[Maxq], no[Maxq];
vector <int> req;
char tmp[50];
ll BIT[Maxn][Maxn];

void Insert(int r, int c, ll val)
{
	for (int i = r; i <= n; i += i & -i)
		for (int j = c; j <= m; j += j & -j)
			BIT[i][j] += val;
}

ll Get(int r, int c)
{
	ll res = 0;
	for (int i = r; i > 0; i -= i & -i)
		for (int j = c; j > 0; j -= j & -j)
			res += BIT[i][j];
	return res;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= k; i++) {
		int len; scanf("%d", &len);
		while (len--) {
			int a, b, c; scanf("%d %d %d", &a, &b, &c);
			gar[i].push_back(iii(ii(a, b), c));
		}
		on[i] = true;
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%s", tmp);
		if (tmp[0] == 'S') { scanf("%d", &a[i]); no[i] = -1; }
		else {
			scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
			no[i] = req.size(); req.push_back(i);
		}
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < gar[i].size(); j++)
			Insert(gar[i][j].first.first, gar[i][j].first.second, gar[i][j].second);
		for (int j = 0; j < req.size(); j++)
			mygar[j].push_back(ill(i, Get(c[req[j]], d[req[j]]) - Get(a[req[j]] - 1, d[req[j]]) - 
									  Get(c[req[j]], b[req[j]] - 1) + Get(a[req[j]] - 1, b[req[j]] - 1)));
		for (int j = 0; j < gar[i].size(); j++)
			Insert(gar[i][j].first.first, gar[i][j].first.second, -gar[i][j].second);
	}
	for (int i = 0; i < q; i++)
		if (no[i] == -1) on[a[i]] ^= true;
		else {
			ll sum = 0;
			for (int j = 0; j < mygar[no[i]].size(); j++) {
				ill p = mygar[no[i]][j];
				if (on[p.first]) sum += p.second;
			}
			printf("%I64d\n", sum);
		}
	return 0;
}
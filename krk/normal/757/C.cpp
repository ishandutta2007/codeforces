#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int arg1 = 1000249;
const int arg2 = 2000003;
const int Maxn = 100005;
const int Maxm = 1000005;

int fac[Maxm];
int n, m;
int freq[Maxm];
int seq[Maxm], slen;
vector <ii> my[Maxm]; 
map <ii, int> M;
int res = 1;

int main() 
{
	fac[0] = 1;
	for (int i = 1; i < Maxm; i++)
		fac[i] = ll(i) * fac[i - 1] % mod1;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int hm; scanf("%d", &hm);
		while (hm--) {
			int a; scanf("%d", &a);
			if (freq[a]++ == 0) seq[slen++] = a;
		}
		for (int j = 0; j < slen; j++) {
			my[seq[j]].push_back(ii(i, freq[seq[j]]));
			freq[seq[j]] = 0;
		}
		slen = 0;
	}
	for (int i = 1; i <= m; i++) {
		ii h = ii(0, 0);
		for (int j = 0; j < my[i].size(); j++) {
			h.first = (ll(h.first) * arg1 + my[i][j].first) % mod1;
			h.first = (ll(h.first) * arg1 + my[i][j].second) % mod1;
			h.second = (ll(h.second) * arg2 + my[i][j].first) % mod2;
			h.second = (ll(h.second) * arg2 + my[i][j].second) % mod2;
		}
		M[h]++;
	}
	for (map <ii, int>::iterator it = M.begin(); it != M.end(); it++)
		res = ll(res) * fac[it->second] % mod1;
	printf("%d\n", res);
    return 0;
}
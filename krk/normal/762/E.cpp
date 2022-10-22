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

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;
const int Maxm = 524288;

int n, k;
int X[Maxn], R[Maxn], F[Maxn];
vector <int> un;
vector <ii> seq;
map <int, int> M[Maxm];
ll res;

void Insert(int v, int l, int r, int x, int f)
{
	M[v][f]++;
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) Insert(2 * v, l, m, x, f);
		else Insert(2 * v + 1, m + 1, r, x, f);
	}
}

int Get(int v, int l, int r, int a, int b, int lef, int rig)
{
	if (l == a && r == b) {
		int res = 0;
		map <int, int>::iterator it = M[v].lower_bound(lef);
		while (it != M[v].end() && it->first <= rig) {
			res += it->second;
			it++;
		}
		return res;
	} else {
		int res = 0;
		int m = l + r >> 1;
		if (a <= m) res += Get(2 * v, l, m, a, min(m, b), lef, rig);
		if (m + 1 <= b) res += Get(2 * v + 1, m + 1, r, max(m + 1, a), b, lef, rig);
		return res;
	}
}

int main() 
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &X[i], &R[i], &F[i]);
		un.push_back(X[i]);
		seq.push_back(ii(R[i], i));
	}
	sort(un.begin(), un.end());
	sort(seq.begin(), seq.end());
	for (int i = int(seq.size()) - 1; i >= 0; i--) {
		int ind = seq[i].second;
		int a = lower_bound(un.begin(), un.end(), X[ind] - R[ind]) - un.begin();
		int b = upper_bound(un.begin(), un.end(), X[ind] + R[ind]) - un.begin() - 1;
		int lef = F[ind] - k, rig = F[ind] + k;
		res += Get(1, 0, un.size() - 1, a, b, lef, rig);
		Insert(1, 0, un.size() - 1, lower_bound(un.begin(), un.end(), X[ind]) - un.begin(), F[ind]);
	}
	printf("%I64d\n", res);
    return 0;
}
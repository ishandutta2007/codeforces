#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}
const int MAXN = 120000;

int n;
vector<int> st;
vector<pair<int, int>> vv;
vector<vector<int> > vv1;

vector<int> eds[MAXN];
int a[MAXN];
int pl[MAXN];
int was[MAXN];

void dfs1(int v) {
	was[v] = 1;
	st.push_back(v);
	for (int u: eds[v]) {
		if (!was[u])
			dfs1(u);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		vv.push_back(make_pair(a[i], i));
	}
	sort(vv.begin(), vv.end());
	for (int i = 0; i < n; ++i)
		pl[vv[i].second] = i;
	for (int i = 0; i < n; ++i) {
		int g = pl[i];
		if (g != i)
			eds[g].push_back(i), eds[i].push_back(g);
	}
	for (int i = 0; i < n; ++i) {
		if (was[i])
			continue;
		st.clear();
		dfs1(i);
		vv1.push_back(st);
	}
	printf("%d\n", (int)vv1.size());
	for (int i = 0; i < vv1.size(); ++i) {
		printf("%d ", (int)vv1[i].size());
		for (int j: vv1[i])
			printf("%d ", j + 1);
		printf("\n");
	}
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

int n, m;
map <int, ii> M;
ll res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, c; scanf("%d %d", &a, &c);
		M[a].first = c;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int b, c; scanf("%d %d", &b, &c);
		M[b].second = c;
	}
	for (map <int, ii>::iterator it = M.begin(); it != M.end(); it++)
		res += max(it->second.first, it->second.second);
	cout << res << endl;
	return 0;
}
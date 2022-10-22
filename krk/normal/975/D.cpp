#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

map <ll, int> M;
map <llll, int> M2;
int n, a, b;
ll res;

int main()
{
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 0; i < n; i++) {
		int x, vx, vy; scanf("%d %d %d", &x, &vx, &vy);
		M[ll(a) * vx - ll(vy)]++;
		M2[llll(ll(a) * vx - ll(vy), vx)]++;
	}
	for (map <ll, int>::iterator it = M.begin(); it != M.end(); it++)
		res += ll(it->second) * (it->second - 1);
	for (map <llll, int>::iterator it = M2.begin(); it != M2.end(); it++)
		res -= ll(it->second) * (it->second - 1);
	cout << res << endl;
	return 0;
}
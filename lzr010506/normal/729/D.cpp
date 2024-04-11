#include <bits/stdc++.h>
#define pb push_back
#define FOR(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
using namespace std;
typedef pair<int, int> pii;
vector<pii> r;
vector<int> p, ans;
char s[200005];

int main() 
{
	int n, a, b, k;
	scanf("%d %d %d %d %s", &n, &a, &b, &k, s);
	int pre = 0;
	FOR(i, 0, n - 1)
		if(s[i] == '1')
			r.pb(pii(pre, i - 1)), pre = i + 1;
	if(pre != n) r.pb(pii(pre, n - 1));
	FOR(i, 0, r.size() - 1)
		for(int j = r[i].first + b - 1; j <= r[i].second; j += b)
			p.pb(j);
	FOR(i, 0, p.size() - a) ans.pb(p[i]);
	printf("%d\n", (int)ans.size());
	for(auto o: ans) printf("%d ", o + 1);
	putchar(10);
	return 0;
}
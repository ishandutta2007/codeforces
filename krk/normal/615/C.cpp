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

const int Maxn = 100005;

string s, t;
string rs;
vector <ii> res;
int Z[Maxn];

ii Get(const string &s)
{
	fill(Z, Z + s.length() + 5, 0);
	int l = -1, r = -1;
	for (int i = 1; i < s.length(); i++) {
		if (i <= r) Z[i] = min(Z[i - l], r - i);
		while (i + Z[i] < s.length() && s[Z[i]] == s[i + Z[i]]) Z[i]++;
		if (i + Z[i] - 1 > r) {
			l = i; r = i + Z[i] - 1;
		}
	}
	int p = 0;
	while (s[p] != '#') p++;
	int best = 0, bi = -1;
	for (int i = 1; p + i < s.length(); i++)
		if (Z[p + i] > best) { best = Z[p + i]; bi = i; }
	return ii(best, bi);
}

int main() 
{
	cin >> s >> t;
	rs = s; reverse(rs.begin(), rs.end());
	int cur = 0;
	while (cur < t.length()) {
		ii a = Get(t.substr(cur) + "#" + s);
		ii b = Get(t.substr(cur) + "#" + rs);
		if (a.first > b.first) { res.push_back(ii(a.second, a.second + a.first - 1)); cur += a.first; }
		else if (b.first > 0) { res.push_back(ii(s.length() - b.second + 1, s.length() - b.second + 1 - b.first + 1)); cur += b.first; }
		else { printf("-1\n"); return 0; }
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}
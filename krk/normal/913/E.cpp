#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 1 << 8;

char tmp[15];
string my[Maxn][2];
priority_queue <iii> Q;
ii seq[2 * Maxn];
int slen;
int n;

string Better(const string &a, const string &b)
{
	if (a.length() == 0) return b;
	if (b.length() == 0) return a;
	if (a.length() != b.length()) return a.length() < b.length()? a: b;
	return a < b? a: b;
}

void Update(ii u, const string &cand)
{
	if (cand.length() == my[u.first][u.second].length() && cand < my[u.first][u.second]) my[u.first][u.second] = cand;
	else if (my[u.first][u.second].length() == 0 || cand.length() < my[u.first][u.second].length()) {
		my[u.first][u.second] = cand; Q.push(iii(-int(my[u.first][u.second].length()), u));
	}
}

int main()
{
	my[240][0] = "x"; Q.push(iii(-1, ii(240, 0)));
	my[204][0] = "y"; Q.push(iii(-1, ii(204, 0)));
	my[170][0] = "z"; Q.push(iii(-1, ii(170, 0)));
	while (!Q.empty()) {
		ii v = Q.top().second;
		int d = -Q.top().first; Q.pop();
		string cur = my[v.first][v.second];
		if (cur.length() != d) continue;
		seq[slen++] = v;
		ii u = ii((v.first ^ (Maxn - 1)), 0);
		string cand = d == 1? "!" + cur: "!(" + cur + ")";
		Update(u, cand);
		for (int i = slen - 1; i >= 0; i--) {
			string his = my[seq[i].first][seq[i].second];
			u = ii((seq[i].first | v.first), 1);
			cand = his + "|" + cur;
			Update(u, cand);
			cand = cur + "|" + his;
			Update(u, cand);
			u = ii((seq[i].first & v.first), 0);
			string a = seq[i].second? "(" + his + ")": his;
			string b = v.second? "(" + cur + ")": cur;
			cand = a + "&" + b;
			Update(u, cand);
			cand = b + "&" + a;
			Update(u, cand);
		}
	}
	scanf("%d", &n);
	while (n--) {
		scanf("%s", tmp);
		int mask = 0;
		for (int i = 0; i < 8; i++)
			if (tmp[i] == '1') mask |= 1 << i;
		printf("%s\n", Better(my[mask][0], my[mask][1]).c_str());
	}
	return 0;
}
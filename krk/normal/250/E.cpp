#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, char> ic;

const int Maxn = 105;

int n, m;
set <ic> S[Maxn];
vector <int> fre[Maxn];
ll res;

ll getRes()
{
	ll res = 0ll;
	int i = 1, j = 1, dr = 1;
	while (i < n) {
		int r = lower_bound(fre[i + 1].begin(), fre[i + 1].end(), j) - fre[i + 1].begin();
		if (fre[i + 1][r] == j) { res++; i++; continue; }
		set <ic>::iterator it = S[i].upper_bound(ic(j, '?')), it2; it2 = it--;
		bool found = false;
		while (it->first < fre[i + 1][r - 1] || fre[i + 1][r] < it2->first || it->second == '+' || it2->second == '+')
			if (dr == 1)
				if (fre[i + 1][r] < it2->first) { res += fre[i + 1][r] - j + 1; found = true; j = fre[i + 1][r]; i++; break; }
				else {
					res += it2->first - j;
					j = it2->first - 1; dr = -1; 
					if (it2->second == '+') S[i].erase(it2++);
				}
			else if (it->first < fre[i + 1][r - 1]) { res += j - fre[i + 1][r - 1] + 1; found = true; j = fre[i + 1][r - 1]; i++; break; }
				 else {
				 	res += j - it->first;
				 	j = it->first + 1; dr = 1;
				 	if (it->second == '+') S[i].erase(it--);
				 }
		if (!found) return -1ll;
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		S[i].insert(ic(0, '#')); S[i].insert(ic(m + 1, '#'));
		fre[i].push_back(0);
		for (int j = 1; j <= m; j++) {
			char ch; scanf(" %c", &ch);
			if (ch == '.') fre[i].push_back(j);
			else S[i].insert(ic(j, ch));
		}
		fre[i].push_back(m + 1);
	}
	res = getRes();
	if (res == -1) printf("Never\n");
	else printf("%I64d\n", res);
	return 0;
}
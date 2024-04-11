#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const int lim = 1000000;
const ll Inf = 1000000000000000000ll;

int n, t;
char s[Maxn];
int slen;
int lsth, cnth;
vector <int> spos;
int res = lim;

bool Enough(int x)
{
	ll res = Inf;
	ll cur = 0ll;
	int need = max(0, cnth - x);
	int lst = max(lsth, need? spos[need - 1]: 0);
	vector <int> seq;
	int has = x;
	for (int i = 0; i < slen; i++) {
		cur++;
		if (s[i] == 'S') {
			has++;
			if (!seq.empty() && has >= seq.size()) {
				cur += 2 * (i - seq[0]);
				has -= seq.size(); seq.clear();
			}
		} else if (s[i] == 'H') {
				if (seq.empty()) res = min(res, cur + 2 * (lst - i));
				if (has) has--;
				else seq.push_back(i);
			}
	}
	return seq.empty() && res <= t;
}

int main()
{
	scanf("%d %d", &n, &t);
	scanf("%s", s); slen = strlen(s);
	int lef = 0, rig = lim;
	for (int i = 0; i < slen; i++) {
		if (s[i] == 'H') { lsth = i; cnth++; lef++; }
		else if (s[i] == 'S') { spos.push_back(i); lef--; }
	}
	lef = max(lef, 0);
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (Enough(mid)) { res = mid; rig = mid - 1; }
		else lef = mid + 1;
	}
	printf("%d\n", res == lim? -1: res);
	return 0;
}
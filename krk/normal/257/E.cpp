#include <cstdio>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;
const ll Inf = 1000000000000000000ll;

int n, m;
int t[Maxn], s[Maxn], f[Maxn];
set <ii> inU, wantsU;
set <ii> inD, wantsD;
int flr;
ll tim;
set <ii> Q;
ll res[Maxn];

void Live(int dr, ll ntim)
{
	flr += dr * (ntim - tim); tim = ntim;
	while (!Q.empty() && Q.begin()->first == tim) {
		int ind = Q.begin()->second; Q.erase(Q.begin());
		if (s[ind] == flr)
			if (f[ind] > flr) inU.insert(ii(f[ind], ind));
			else inD.insert(ii(f[ind], ind));
		else if (s[ind] > flr) wantsU.insert(ii(s[ind], ind));
			 else wantsD.insert(ii(s[ind], ind));
	}
	while (!wantsU.empty() && wantsU.begin()->first == flr) {
		int ind = wantsU.begin()->second; wantsU.erase(wantsU.begin());
		if (f[ind] > flr) inU.insert(ii(f[ind], ind));
		else inD.insert(ii(f[ind], ind));
	}
	set <ii>::iterator it;
	while (!wantsD.empty() && wantsD.rbegin()->first == flr) {
		int ind = wantsD.rbegin()->second; it = wantsD.end(); it--; wantsD.erase(it);
		if (f[ind] > flr) inU.insert(ii(f[ind], ind));
		else inD.insert(ii(f[ind], ind));
	}
	while (!inU.empty() && inU.begin()->first == flr) {
		int ind = inU.begin()->second; inU.erase(inU.begin());
		res[ind] = tim;
	}
	while (!inD.empty() && inD.rbegin()->first == flr) {
		int ind = inD.rbegin()->second; it = inD.end(); it--; inD.erase(it);
		res[ind] = tim;	
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &t[i], &s[i], &f[i]);
		Q.insert(ii(t[i], i));
	}
	flr = 1;
	while (!inU.empty() || !wantsU.empty() || !inD.empty() || !wantsD.empty() || !Q.empty()) {
		int dr;
		ll nr = Q.empty()? Inf: Q.begin()->first;
		if (inU.empty() && wantsU.empty() && inD.empty() && wantsD.empty()) dr = 0;
		else if (inU.size() + wantsU.size() >= inD.size() + wantsD.size()) { 
				dr = 1;
				if (!inU.empty()) nr = min(nr, tim + (inU.begin()->first - flr));
				if (!wantsU.empty()) nr = min(nr, tim + (wantsU.begin()->first - flr));
			} else {
				dr = -1;
				if (!inD.empty()) nr = min(nr, tim + (flr - inD.rbegin()->first));
				if (!wantsD.empty()) nr = min(nr, tim + (flr - wantsD.rbegin()->first));
			}
		Live(dr, nr);
	}
	for (int i = 0; i < n; i++)
		printf("%I64d\n", res[i]);
	return 0;
}
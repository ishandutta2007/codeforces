#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, d, S;
ll C, bsiz;
ll dum;
vector <ll> bf1, bf2;
ll res1, res2;

int main()
{
	scanf("%I64d %I64d %I64d", &n, &d, &S);
	while (n--) {
		ll c, f, l; scanf("%I64d %I64d %I64d", &c, &f, &l);
		if (c) { C += c; bsiz++; if (l >= d) bf1.push_back(f); }
		else { if (l < d) dum++; else bf2.push_back(f); }
	}
	sort(bf1.begin(), bf1.end()); sort(bf2.begin(), bf2.end());
	ll used = 0;
	int i = 0;
	while (i < bf2.size() && used + bf2[i] <= S) used += bf2[i++];
	res1 = i; res2 = used;
	if (!bf1.empty() && bf1[0] <= S) {
		ll taken = bsiz; used = bf1[0];
		ll lft = C - bsiz + 1;
		ll take = min(lft, dum); taken += take; lft -= take;
		take = min(lft, (ll)bf2.size()); taken += take; lft -= take;
		int r = bf2.size() - take;
		int i = 0, j = 1;
		while (i < r && j < bf1.size())
			if (bf1[j] < bf2[i] && used + bf1[j] <= S) { used += bf1[j]; j++; r--; taken++; }
			else if (bf1[j] >= bf2[i] && used + bf2[i] <= S) { used += bf2[i]; i++; taken++; }
			else break;
		while (i < r && used + bf2[i] <= S) { used += bf2[i++]; taken++; }
		if (taken > res1 || taken == res1 && used < res2) { res1 = taken; res2 = used; }
	} 
	printf("%I64d %I64d\n", res1, res2);
	return 0;
}
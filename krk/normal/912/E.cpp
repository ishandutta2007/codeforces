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

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 16;
const int Maxm = 8000000;

int n;
int p[Maxn];
ll k;
ll seq1[Maxm], seq2[Maxm];
int slen1, slen2;
map <ll, ll> G[Maxn];

void Gen(int from, int to, ll cur, ll seq[], int &slen)
{
    if (from > to) { seq[slen++] = cur; return; }
    while (cur <= Inf) {
        Gen(from + 1, to, cur, seq, slen);
        if (cur <= Inf / p[from])
            cur *= p[from];
        else break;
    }
}

ll Get(ll x)
{
	ll res = 0;
	for (int i = 0; i < slen2 && seq2[i] <= x; i++)
		res += upper_bound(seq1, seq1 + slen1, x / seq2[i]) - seq1;
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	cin >> k;
	sort(p, p + n);
	int md = min(5, n - 1);
	Gen(0, md, 1, seq1, slen1);
	Gen(md + 1, n - 1, 1, seq2, slen2);
	sort(seq1, seq1 + slen1);
	sort(seq2, seq2 + slen2);
	ll lef = 1, rig = Inf;
	while (lef <= rig) {
		ll mid = (lef + rig) >> 1ll;
		if (Get(mid) >= k) rig = mid - 1;
		else lef = mid + 1;
	}
	cout << rig + 1 << endl;
	return 0;
}
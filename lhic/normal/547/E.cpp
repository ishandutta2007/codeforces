#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;


const ll M1 = 1000003;
const ll M2 = 1000000007;

const ll P = 23917;

const int MAXN = 201000;
const int MAXQ = 501000;

ll hh1[MAXN];
ll hh2[MAXN];

ll ht[M1 + 100];
ll cnt[M1 + 100];

string s[MAXN];
int kk[MAXQ];

vector<int> vv;

vector<int> gom[MAXN];
vector<int> gop[MAXN];

ll pw1[MAXN];
ll pw2[MAXN];

int ans[MAXQ];

int n, q;


void add(ll h1, ll h2) {
//	cout << "add " << h1 << " " << h2 << "\n";
	++h2;
	while (ht[h1] && ht[h1] != h2)
		++h1;
	ht[h1] = h2;
}

int get(ll h1, ll h2) {
	++h2;
//	cout << "get " << h1 << " " << h2 << "\n";
	while (ht[h1] && ht[h1] != h2)
		++h1;
	if (ht[h1])
		return cnt[h1];
	else
		return 0;
}

void pl(ll h1, ll h2) {
	++h2;
//	cout << "+ " << h1 << " " << h2 << "\n";
	while (ht[h1] && ht[h1] != h2)
		++h1;
	if (ht[h1])
		++cnt[h1];
}





int main() {
//	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	pw1[0] = 1, pw2[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		pw1[i] = (pw1[i - 1] * P) % M1, pw2[i] = (pw2[i - 1] * P) % M2;
	//scanf("%d%d", &n, &q);
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	for (int i = 0; i < n; ++i) {
		vv.push_back(s[i].size());
	}
	sort(vv.begin(), vv.end());
	vv.resize(unique(vv.begin(), vv.end()) - vv.begin());

	for (int i = 0; i < q; ++i) {
		int l, r;
		//scanf("%d%d%d", &l, &r, &kk[i]);
		cin >> l >> r >> kk[i];
		--l;
		--r;
		--kk[i];
		--l;
		if (l >= 0)
			gom[l].push_back(i);
		gop[r].push_back(i);
	}

	for (int i = 0; i < n; ++i) {
		int k = s[i].size();
		for (int j = 0; j < k; ++j)
			hh1[i] = (hh1[i] * P + s[i][j]) % M1, hh2[i] = (hh2[i] * P + s[i][j]) % M2;
		add(hh1[i], hh2[i]);
	}

	for (int i = 0; i < n; ++i) {
		int sz = s[i].size();
		for (int k = 0; k < (int)vv.size() && vv[k] <= sz; ++k) {
			int p = vv[k];
			ll h1 = 0;
			ll h2 = 0;
			for (int j = 0; j < p; ++j)
				h1 = (h1 * P + s[i][j]) % M1, h2 = (h2 * P + s[i][j]) % M2;
			pl(h1, h2);
			for (int j = p; j < sz; ++j) {
				h1 = (h1 * P + s[i][j] - s[i][j - p] * pw1[p] + M1 * M1) % M1;
				h2 = (h2 * P + s[i][j] - s[i][j - p] * pw2[p] + M2 * M2) % M2;
				pl(h1, h2);
			}
		}
		for (int j = 0; j < (int)gom[i].size(); ++j)
			ans[gom[i][j]] -= get(hh1[kk[gom[i][j]]], hh2[kk[gom[i][j]]]);
		for (int j = 0; j < (int)gop[i].size(); ++j)
			ans[gop[i][j]] += get(hh1[kk[gop[i][j]]], hh2[kk[gop[i][j]]]);
		
	}
	for (int i = 0; i < q; ++i) {
		printf("%d\n", ans[i]);
	}

	return 0;
}
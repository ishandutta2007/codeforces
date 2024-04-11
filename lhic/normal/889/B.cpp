#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

int was[30];
set<int> eds[30];
set<int> st[30];
string gs;
vector<string> vv;
int n;
char buf[120000];
int en[30];

void no() {
	cout << "NO\n";
	exit(0);
}

void run(int v) {
	gs += (char)('a' + v);
	was[v] = 1;
	if (eds[v].size() >= 2)
		no();
	if (eds[v].size() == 0)
		return;
	run(*eds[v].begin());
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf(" %s", buf);
		int l = strlen(buf);
		for (int j = 0; j < l; ++j)
			en[buf[j] - 'a'] = 1;
		for (int j = 0; j < l - 1; ++j)
			eds[buf[j] - 'a'].insert(buf[j + 1] - 'a'), st[buf[j + 1] - 'a'].insert(buf[j] - 'a');
	}
	for (int i = 0; i < 26; ++i)
		if (st[i].size() >= 2 || eds[i].size() >= 2)
			no();
	for (int i = 0; i < 26; ++i) {
		if (!en[i]) {
			was[i] = 1;
			continue;
		}
		if (was[i])
			continue;
		if (st[i].size())
			continue;
		gs = "";
		run(i);
		vv.push_back(gs);
	}
	for (int i = 0; i < 26; ++i) {
		if (!was[i])
			no();
	}
	sort(vv.begin(), vv.end());
	string ans;
	for (int i = 0; i < vv.size(); ++i)
		ans += vv[i];
	cout << ans << "\n";
	return 0;
}
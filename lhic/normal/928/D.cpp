#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

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

const int MX = 400000;

int cnt[MX];
int go[MX][27];
int fl[MX];

string s;

vector<string> wr;

int cc = 1;

int add(string s) {
	int now = 0;
	int ans = s.size();
	int fs = -1;
	for (int i = 0; i < s.size(); ++i) {
		if (cnt[now] == 1 && fs == -1)
			fs = i;
		int x = s[i] - 'a';
		if (fl[now] && fs != -1)
			ans = min(ans, fs + 1 + (int)s.size() - i);
		if (go[now][x])
			now = go[now][x];
		else
			now = go[now][x] = cc++;
	}
	if (fl[now]) {
		if (fs != -1)
			ans = min(ans, fs + 1);
	}
	else {
		fl[now] = 1;
		now = 0;
		for (int i = 0; i < s.size(); ++i) {
			int x = s[i] - 'a';
			++cnt[now];
			if (go[now][x])
				now = go[now][x];
			else
				now = go[now][x] = cc++;
		}
		++cnt[now];
	}
	return ans;
}

int main() {
	cnt[0] = 2;
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	string buf;
	while (getline(cin, buf)) {
		s += buf + "\n";
	}
	string cur = "";
	int ans = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (isalpha(s[i])) {
			cur += s[i];
		}
		else {
			if (cur != "")
				wr.push_back(cur), cur = "";
			++ans;
		}
	}
	for (auto s: wr) {
		int len = add(s);
		ans += len;
	}
	cout << ans << "\n";
	return 0;
}
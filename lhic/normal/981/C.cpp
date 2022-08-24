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
const int MAXN = 120000;

vector<int> eds[MAXN];
int n;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	vector<int> vs;
	vector<int> bd;
	for (int i = 0; i < n; ++i) {
		if (eds[i].size() == 1)
			vs.push_back(i);
		else if (eds[i].size() > 2)
			bd.push_back(i);
	}
	if (bd.size() > 1) {
		cout << "No\n";
	}
	else if (bd.size() == 0) {
		cout << "Yes\n";
		cout << 1 << "\n";
		cout << vs[0] + 1 << " " << vs[1] + 1 << "\n";  
	}
	else {
		cout << "Yes\n";
		cout << vs.size() << "\n";
		for (int i: vs)
			cout << i + 1 << " " << bd[0] + 1 << "\n";
	}
	return 0;
}
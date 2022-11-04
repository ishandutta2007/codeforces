
// Problem : C. Train Maintenance
// Contest : Codeforces - Codeforces Round #745 (Div. 1)
// URL : https://codeforces.com/contest/1580/problem/C
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005, SQ = 500;
int n, m, x[MX], y[MX], bg[MX], sm[SQ][SQ], acu[MX], t[MX];

int get (int i, int k) {
	if (t[k] == -1) return t[k] = i;
	
	int ret = t[k];
	t[k] = -1;
	return ret;
}

void usm (int i, int k, int f) {
	int sz = x[k] + y[k];
	
	for (int t = (get(i, k) + x[k]) % sz, _ = 0; _ < y[k]; t++, _++) {
		if (t == sz)
			t = 0;
		sm[sz][t] += f;
	}
}

void ubg (int i, int k, int f) {
	for (int t = get(i, k); t + x[k] < MX; t += x[k] + y[k]) {
		bg[t + x[k]] += f;
		if (t + x[k] + y[k] < MX)
			bg[t + x[k] + y[k]] -= f;
		
		if (i) {
			if (t + x[k] < i - 1)
				bg[i - 1] += f;
			if (t + x[k] + y[k] < i - 1)
				bg[i - 1] -= f;
		}
	}
}

void main_() {
	cin >> n >> m;
	
	forn (i, n)
		cin >> x[i] >> y[i];
	
	memset(acu, -1, sizeof(acu));
	memset(t, -1, sizeof(t));
	
	forn (i, m) {
		int op, k;
		cin >> op >> k;
		k--;
		
		if (x[k] + y[k] < SQ) usm(i, k, op == 1 ? 1 : -1);
		else ubg(i, k, op == 1 ? 1 : -1);
		
		int res = 0;
		if (i) bg[i] += bg[i - 1];
		res = bg[i];
		
		for (int j = 2; j < SQ; j++) {
			acu[j]++;
			if (acu[j] == j)
				acu[j] = 0;
			
			res += sm[j][acu[j]];
		}
		
		cout << res << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}
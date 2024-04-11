// Powered by CP Editor (https://cpeditor.org)

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

const int MX = 200005;
int n, m, a[MX], l[MX], r[MX];
int sig[MX], ant[MX];
int ml[MX], mr[MX];
int pre[MX], suf[MX];
map<int, int> mp;
map<int, vi> pos;

void main_() {
	cin >> n >> m;
	
	pos.clear();
	forr (i, 1, n) {
		cin >> a[i];
		pos[a[i]].pb(i);
	}
	
	forn (i, m)
		cin >> l[i] >> r[i];
	
	mp.clear();
	forr (i, 1, n) {
		ant[i] = 0;
		if (mp.count(a[i]))
			ant[i] = mp[a[i]];
		ant[i] = max(ant[i], ant[i - 1]);
		
		mp[a[i]] = i;
	}
	
	sig[n + 1] = n + 1;
	mp.clear();
	for (int i = n; i >= 1; i--) {
		sig[i] = n + 1;
		if (mp.count(a[i]))
			sig[i] = mp[a[i]];
		sig[i] = min(sig[i], sig[i + 1]);
		
		mp[a[i]] = i;
	}
	
	forr (i, 1, n) {
		ml[i] = 0;
		mr[i] = n + 1;
	}
	
	forn (i, m) {
		ml[l[i]] = max(ml[l[i]], r[i]);
		mr[r[i]] = min(mr[r[i]], l[i]);
	}
	
	pre[0] = n + 1;
	forr (i, 1, n) {
		pre[i] = n + 1;
		if (sig[i] <= ml[i])
			pre[i] = sig[i];
		pre[i] = min(pre[i], pre[i - 1]);
	}
	
	if (pre[n] == n + 1) {
		cout << 0 << endl;
		return;
	}
	
	suf[n + 1] = 0;
	for (int i = n; i >= 1; i--) {
		suf[i] = 0;
		if (mr[i] <= ant[i])
			suf[i] = ant[i];
		suf[i] = max(suf[i + 1], suf[i]);
	}
	
	int to = suf[1], res = to, mx = ml[1];
	for (int i = 1; i < pre[n]; i++) {
		mx = max(mx, ml[i]);
		to = max(to, i + 1);
		
		int j = upper_bound(all(pos[a[i]]), mx) - pos[a[i]].begin();
		if (j && pos[a[i]][j - 1] > to)
			to = pos[a[i]][j - 1];
		
		res = min(res, to - i);
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}
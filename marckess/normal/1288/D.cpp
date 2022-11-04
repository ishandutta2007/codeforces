#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 300005;
int n, m;
int a[MX][10];
map<int, int> mp; 
ii res;

ii esPos (int k) {
	mp.clear();
	for (int i = 0; i < n; i++) {
		int mk = 0;
		for (int j = 0; j < m; j++)
			if (a[i][j] >= k)
				mk |= 1 << j;
		mp[mk] = i;
	}

	for (auto it = mp.begin(); it != mp.end(); it++)
		for (auto jt = mp.begin(); jt != mp.end(); jt++) {
			if (__builtin_popcount(it->fi | jt->fi) < m) continue;
			return {it->se, jt->se};
		}

	return {-1, -1};
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	int i = 0, j = 1e9 + 5, rep = 32;
	while (rep--) {
		int m = (i + j + 1) / 2;
		ii p = esPos(m);
		if (p.fi != -1) i = m, res = p;
		else j = m;
	}

	cout << res.fi+1 << " " << res.se+1 << endl;

	return 0;
}
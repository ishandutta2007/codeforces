#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 5005;
int n, s[MX], p[MX];
ll res;

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	p[parent(a)] = parent(b);
}

void solve () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		p[i] = i;
	}
	p[n + 1] = n + 1;
	
	for (int i = n; i >= 1; i--)
		if (s[i] == 1)
			join(i, i + 1);
	
	res = 0;
	while (parent(1) <= n) {
		int u = parent(1);
		
		if (u + s[u] > n) {
			res += u + s[u] - n;
			s[u] = n - u;
		}
		
		if (s[u] == 0) {
			res--;
			break;
		}
		
		if (s[u] == 1)
			join(u, u + 1);
		
		if (parent(1) > n) break;
		
		for (int j = parent(1); j <= n;) {
			int sig = j + s[j];
			
			s[j]--;
			if (!s[j]) s[j] = 1;
			if (s[j] == 1) join(j, j + 1);
			
			if (sig > n) break;
			j = parent(sig);
		}
		
		res++;
	}
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}
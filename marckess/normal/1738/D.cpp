#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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

const int MX = 100005;
int n, k, b[MX], a[MX];
vi pos[MX];

void main_() {
	cin >> n;
	
	forr (i, 0, n + 1)
		pos[i].clear();
	
	k = 0;
	forr (i, 1, n) {
		cin >> b[i];
		if (b[i] > i)
			k = i;
		pos[b[i]].pb(i);
	}
	
	cout << k << endl;
	
	int act = 0;
	if (pos[n + 1].size())
		act = n + 1;
	
	while (act != -1) {
		int nex = -1;
		
		for (int x : pos[act])
			if (pos[x].size())
				nex = x;
			else
				cout << x << " ";
		
		if (nex != -1)
			cout << nex << " ";
		act = nex;
	}
	
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}
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

int n;
map<int, int> mp;

void main_() {
	cin >> n;
	
	mp.clear();
	forn (i, n) {
		int a;
		cin >> a;
		mp[a]++;
	}
	
	int x = 0, y = 0;
	for (auto it : mp) {
		if (it.se == 1)
			x++;
		else
			y++;
	}
	
	if (x) x--, y++;
	
	cout << y + x / 2 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}
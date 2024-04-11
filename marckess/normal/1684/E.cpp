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
int n, k, a[MX];
map<int, int> mp;

void main_() {
	cin >> n >> k;
	mp.clear();
	forn (i, n) {
		cin >> a[i];
		mp[a[i]]++;
	}
	
	int mex = 0, t = 0;
	while (mp.count(mex) || t < k) {
		if (!mp.count(mex))
			t++;
		mex++;
	}
	mex = min(mex, n);
	
	vii v;
	for (auto p : mp)
		if (p.fi > mex)
			v.pb({p.se, p.fi});
	
	int dif = mex + v.size();
	sort(all(v));
	t = 0;
	
	for (auto p : v)
		if (t + p.fi <= k) {
			dif--;
			t += p.fi;
		}
	
	cout << dif - mex << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}
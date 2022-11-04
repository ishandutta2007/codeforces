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

int n;
map<string, string> mp, pre, suf;
map<string, ll> res;

string getpre (string s) {
	if (s.size() <= 3)
		return s;
	return s.substr(0, 3);
}

string getsuf (string s) {
	if (s.size() <= 3)
		return s;
	return s.substr((int)s.size() - 3, 3);
}

int count (string s) {
	int res = 0;
	for (int i = 0; i + 4 <= (int)s.size(); i++)
		res += s.substr(i, 4) == "haha";
	return res;
}

void solve () {
	mp.clear();
	pre.clear();
	suf.clear();
	res.clear();
	
	cin >> n;
	
	forn (i, n) {
		string s, op;
		cin >> s >> op;
		
		if (op == ":=") {
			string val;
			cin >> val;
			
			mp[s] = val;
			pre[s] = getpre(val);
			suf[s] = getsuf(val);
			res[s] = count(val);
		} else {
			string a, b, kk;
			cin >> a >> kk >> b;
			
			string mpa = mp[a];
			string prea = pre[a];
			string sufa = suf[a];
			
			string mpb = mp[b];
			string preb = pre[b];
			string sufb = suf[b];
			
			if (mpa.size() < 5 || mpb.size() < 5)
				mp[s] = mpa + mpb;
			else
				mp[s].clear();
			
			pre[s] = getpre(mpa + preb);
			suf[s] = getsuf(sufa + mpb);
			res[s] = res[a] + res[b] + count(sufa + preb);
			
			if (!mp[s].size())
				mp[s] = pre[s] + suf[s];
		}
		
		if (i + 1 == n)
			cout << res[s] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}

// Problem : B. Frog Traveler
// Contest : Codeforces - Codeforces Round #751 (Div. 1)
// URL : https://codeforces.com/contest/1601/problem/B
// Memory Limit : 512 MB
// Time Limit : 2000 ms
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

const int MX = 300005;
int n, dis[MX], p[MX], a[MX], b[MX];
set<int> st;

void main_() {
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	
	forn (i, n)
		st.insert(i);
	
	queue<int> q;
	q.push(n);
	dis[n] = 0;
	p[n] = -1;
	
	while (q.size()) {
		int u = q.front();
		q.pop();
		
		int r = u + b[u];
		int l = u + b[u] - a[u + b[u]];
		
		auto it = st.lower_bound(l);
		while ((it = st.lower_bound(l)) != st.end()) {
			if (*it > r)
				break;
			
			dis[*it] = dis[u] + 1;
			p[*it] = u;
			q.push(*it);
			st.erase(it);
		} 
	}
	
	if (st.count(0)) cout << -1 << endl;
	else {
		vi res;
		
		int u = 0;
		while (u != -1) {
			res.pb(u);
			u = p[u];
		}
		
		res.pop_back();
		reverse(all(res));
		
		cout << dis[0] << endl;
		for (int r : res)
			cout << r << " ";
		cout << endl;
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
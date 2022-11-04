
// Problem : D. Productive Meeting
// Contest : Codeforces - Codeforces Round #744 (Div. 3)
// URL : https://codeforces.com/contest/1579/problem/D
// Memory Limit : 256 MB
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

void main_() {
	int n;
	priority_queue<ii> pq;
	
	cin >> n;
	forn (i, n) {
		int a;
		cin >> a;
		
		if (a) pq.emplace(a, i);
	}
	
	vii res;
	while (pq.size() >= 2) {
		ii a = pq.top(); pq.pop();
		ii b = pq.top(); pq.pop();
		
		res.pb({a.se, b.se});
		a.fi--, b.fi--;
		
		if (a.fi) pq.push(a);
		if (b.fi) pq.push(b);
	}
	
	cout << res.size() << endl;
	for (ii& r : res)
		cout << r.fi + 1 << " " << r.se + 1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}
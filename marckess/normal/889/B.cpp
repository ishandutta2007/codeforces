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

const int MX = 100005;
int n, ex[MX], col;
vector<string> vs;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	forn (i, n) {
		string s;
		cin >> s;
		vs.pb(s);
		
		sort(all(s));
		s.erase(unique(all(s)), s.end());
		
		if (s.size() < vs.back().size()) {
			cout << "NO" << endl;
			return 0;
		}
	}
	
	for (int i = 'a'; i <= 'z'; i++) {
		priority_queue<ii, vii, greater<ii>> pq;
		 
		 forn (j, vs.size())
		 	for (char c : vs[j])
		 		if (c == i)
		 			pq.emplace(vs[j].size(), j);
		
		while (pq.size() > 1) {
			int a = pq.top().se; pq.pop();
			int b = pq.top().se; pq.pop();
			
			int x;
			forn (j, vs[a].size())
				if (vs[a][j] == i)
					x = j;
			
			int y;
			forn (j, vs[b].size())
				if (vs[b][j] == i)
					y = j;
			
			if (x < y) {
				swap(x, y);
				swap(a, b);
			}
			
			for (int i = x - y, j = 0; j < vs[b].size(); i++, j++) {
				if (i < vs[a].size()) {
					if (vs[a][i] != vs[b][j]) {
						cout << "NO" << endl;
						return 0;
					}
				} else {
					vs[a].pb(vs[b][j]);
				}
			}
			
			col++;
			for (char c : vs[a]) {
				if (ex[c] == col) {
					cout << "NO" << endl;
					return 0;
				}
				ex[c] = col;
			}
			
			pq.emplace(vs[a].size(), a);
			vs[b].clear();
		}
		
		vector<string> aux;
		for (string &s : vs)
			if (s.size())
				aux.pb(s);
		vs = aux;
	}
	
	sort(all(vs));
	for (string &s : vs)
		cout << s;
	cout << endl;
	
	return 0;
}
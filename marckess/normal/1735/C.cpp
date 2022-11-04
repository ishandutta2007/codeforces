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
int n, p[256], cn;
char sig[256];
string s;
set<char> st;

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	p[parent(a)] = parent(b);
}

void main_() {
	cin >> n >> s;
	
	memset(sig, 0, sizeof(sig));
	iota(p, p + 256, 0);
	
	st.clear();
	forr (c, 'a', 'z')
		st.insert(c);
	
	cn = 0;
	for (char c : s) {
		if (!sig[c]) {
			
			if (cn == 25) {
				sig[c] = *st.begin();
			} else {
				for (char d : st)
					if (parent(c) != parent(d)) {
						sig[c] = d;
						join(c, d);
						break;
					}
			}
			
			st.erase(sig[c]);
			cn++;
		}
		
		cout << sig[c];
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
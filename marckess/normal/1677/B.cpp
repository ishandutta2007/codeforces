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

const int MX = 1000005;
int n, m, fil[MX], col[MX], tc;
string s;

void main_() {
	cin >> n >> m >> s;
	
	forn (i, m) {
		fil[i] = 0;
		col[i] = 0;
	}
	tc = 0;
	
	int acu = 0;
	forn (i, n * m) {
		int j = i % m;
		
		if (i - m >= 0)
			if (s[i - m] == '1')
				acu--;
		
		if (s[i] == '1') {
			if (!col[j]) {
				tc++;
				col[j] = 1;
			}
			acu++;
		}
		
		fil[j] += bool(acu);
		
		cout << tc + fil[j] << " ";
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
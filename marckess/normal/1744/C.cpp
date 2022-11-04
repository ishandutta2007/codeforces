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

int n;
char c;
string s;

void main_() {
	cin >> n >> c >> s;
	s += s;
	
	int ant = -1, mx = 0;
	
	forn (i, 2 * n) {
		if (s[i] == c && ant == -1)
			ant = i;
			
		if (s[i] == 'g' && ant != -1) {
			mx = max(mx, i - ant);
			ant = -1;
		}
	}
	
	cout << mx << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}
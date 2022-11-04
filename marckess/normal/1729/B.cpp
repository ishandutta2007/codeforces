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

void main_() {
	int n;
	string s;
	
	cin >> n >> s;
	string t;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '0') {
			t.pb('a' + 10 * (s[i - 2] - '0') + (s[i - 1] - '1'));
			i -= 2;	
		} else {
			t.pb('a' + s[i] - '1');
		}
	}
	reverse(all(t));
	cout << t << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}
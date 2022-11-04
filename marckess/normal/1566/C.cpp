
// Problem : C. MAX-MEX Cut
// Contest : Codeforces - Codeforces Global Round 16
// URL : https://codeforces.com/contest/1566/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
	string a, b;
	cin >> n >> a >> b;
	
	int res = 0;
	forn (i, n) {
		if (a[i] != b[i]) {
			res += 2;
			a[i] = b[i] = 0;
		} else if (a[i] == '0') {
			if (i && a[i - 1] == '1' && b[i - 1] == '1') {
				res += 2;
				a[i] = b[i] = 0;
			} else
				res++;
		} else {
			if (i && a[i - 1] == '0' && b[i - 1] == '0') {
				res++;
				a[i] = b[i] = 0;
			}
		}
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}
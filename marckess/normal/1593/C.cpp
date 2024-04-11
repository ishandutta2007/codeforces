
// Problem : C. Save More Mice
// Contest : Codeforces - Codeforces Round #748 (Div. 3)
// URL : https://codeforces.com/contest/1593/problem/C
// Memory Limit : 256 MB
// Time Limit : 4000 ms
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

const int MX = 1000005;
int n, a[MX], k;

void main_() {
	cin >> n >> k;
	forn (i, k)
		cin >> a[i];
	sort(a, a + k);
	
	ll acu = 0;
	for (int i = k - 1; i >= 0; i--) {
		acu += n - a[i];
		
		if (acu >= n) {
			cout << k - i - 1 << endl;
			return;
		}
	}
	
	cout << k << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}

// Problem : C. Grandma Capa Knits a Scarf
// Contest : Codeforces - Codeforces Round #750 (Div. 2)
// URL : https://codeforces.com/contest/1582/problem/C
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

int n;
string s;

int go (char c) {
	int res = 0;
	
	int i = 0, j = n - 1;
	
	while (i < j) {
		if (s[i] == s[j])
			i++, j--;
		else if (s[i] == c)
			i++, res++;
		else if (s[j] == c)
			j--, res++;
		else
			return 1e9;
	}
	
	return res;
}

void main_() {
	cin >> n >> s;
	
	int res = 1e9;
	for (int i = 'a'; i <= 'z'; i++)
		res = min(res, go(i));
	
	if (res == 1e9) cout << -1 << endl;
	else cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}
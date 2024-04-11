#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> n >> s;
	sort(all(s));
	s.erase(unique(all(s)), s.end());
	if (n > 1 && s.size() == n) cout << "NO" << endl;
	else cout << "YES" << endl;
 
	return 0;
}
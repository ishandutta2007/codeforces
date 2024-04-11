#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

string s;
int a, b, c;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	while (s.back() == 'c') {
		c++;
		s.pop_back();
	}
	while (s.back() == 'b') {
		b++;
		s.pop_back();
	}
	while (s.back() == 'a') {
		a++;
		s.pop_back();
	}

	if (s.size() || !a || !b || !c || (c != a && c != b)) cout << "NO" << endl;
	else cout << "YES" << endl;

	return 0;
}
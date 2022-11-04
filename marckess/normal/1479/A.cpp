#include <bits/stdc++.h>

//#define endl '\n'
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

int n;

int query (int x) {
	cout << "? " << x << endl;
	int r;
	cin >> r;
	return r;
}

int f (int x) {
	int y = query(x);
	int a = x == 1 || query(x - 1) > y;
	int b = x == n || query(x + 1) > y;
	
	if (a && b) {
		cout << "! " << x << endl;
		exit(0);
	}
	if (a) return 1;
	return 0;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	int i = 1, j = n, rep = 20;
	
	f(1);
	f(n);
	
	while (rep--) {
		int m = (i + j) / 2;
		if (f(m)) i = m;
		else j = m;
	}
	
	cout << "! " << i << endl;
	
	return 0;
}
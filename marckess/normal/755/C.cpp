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

const int MX = 10005;
int n, a, p[MX];

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	p[parent(a)] = parent(b);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(p, p+MX, 0);

	cin >> n;
	forr(i, 1, n) {
		cin >> a;
		join(i, a);
	}

	int res = 0;
	forr(i, 1, n)
		res += i == parent(i);
	cout << res << endl;

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 10000005;
int n;
ll x, y, d[MX];

ll obtRes (int n) {
	if (n == 3)	return obtRes(2) + x;
	if (n == 2)	return obtRes(1) + min(x, y);
	if (n == 1)	return obtRes(0) + x;
	if (n == 0)	return 0;

	ll &res = d[n];
	if (res != -1) return res;
	res = n * x;

	if (n % 2 == 0) res = min(res, obtRes(n/2) + y);
	else res = min(res, min(obtRes(n+1), obtRes(n-1)) + x);

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill(d, d+MX, -1);

	cin >> n >> x >> y;
	cout << obtRes(n) << endl;	

	return 0;
}
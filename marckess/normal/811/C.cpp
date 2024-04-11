#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

typedef vector<vi> vvi;
vvi dp;
int n, v[5005];
vi ini(5005, 5005), fin(5005, 0), acu(5005), lar(5005);

void obtSeg () {
	for (int i = 0; i < n; i++) {
		int x = v[i], a = ini[x], b = fin[x];

		if ( a < i ) {
			acu[i] = -1;
			lar[i] = -1;
			continue;
		}

		for (int j = a; j <= b; j++) {
			x = v[j];

			if ( ini[x] < a ) {
				acu[i] = -1;
				b = -1;
				break;
			}
			
			if ( ini[x] == j ) {
				acu[a] ^= x;
			}
			b = max(b, fin[x]);
		}

		lar[i] = b;
	}
}

int obtRes (int act, int ori, int sum) {
	if ( act == n )
		return sum;

	if ( dp[act][ori] > -1 )
		return dp[act][ori];

	if ( acu[act] == -1 )
		return dp[act][ori] = sum + obtRes(act+1, act+1, 0);

	int res = sum + obtRes(act+1, act+1, 0);
	if ( act != ori )
		res = max (res, sum + obtRes(act, act, 0));
	res = max (res, obtRes(lar[act] + 1, ori, sum ^ acu[act]));

	return dp[act][ori] = res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		ini[v[i]] = min (i, ini[v[i]]);
		fin[v[i]] = i;
	}
	dp = vvi(n+2, vi(n+2, -1));

	obtSeg();
	obtRes(0, 0, 0);

	cout << dp[0][0] << endl;

	return 0;
}
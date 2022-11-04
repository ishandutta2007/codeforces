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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	ll s, v1, v2, t1, t2;

	cin >> s >> v1 >> v2 >> t1 >> t2;

	v1 *= s;
	v2 *= s;

	v1 += 2*t1;
	v2 += 2*t2;

	if ( v1 == v2 )
		cout << "Friendship" << endl;
	else if ( v1 < v2 )
		cout << "First" << endl;
	else
		cout << "Second" << endl;

	return 0;
}
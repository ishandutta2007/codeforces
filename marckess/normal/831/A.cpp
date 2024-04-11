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

int n, a[105], i = 1;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int j = 1; j <= n; j++)
		cin >> a[j];

	while ( i < n && a[i] < a[i+1] )
		i++;
	while ( i < n && a[i] == a[i+1] )
		i++;
	while ( i < n && a[i] > a[i+1] )
		i++;

	if ( i == n )
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
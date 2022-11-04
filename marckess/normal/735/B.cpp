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

int n, a[100000], n1, n2;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> n1 >> n2;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n, greater<int>());

	if (n1 > n2)
		swap(n1, n2);

	ld res = 0;
	for (int i = 0; i < n1; i++)
		res += ld(a[i]) / n1;
	for (int i = n1; i < n1 + n2; i++)
		res += ld(a[i]) / n2;

	cout << fixed << setprecision(6) << res << endl;

	return 0;
}
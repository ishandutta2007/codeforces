#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
#define MOD(n,k) ((((n) % (k)) + (k)) % (k))
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, h[100005];

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i];

	vi res(n+5), izq(n+5), der(n+5);

	for (int i = 1; i <= n; i++)
		res[i] = izq[i] = min(h[i], izq[i-1] + 1);
	for (int i = n; i >= 1; i--)
		res[i] = min(res[i], (der[i] = min(h[i], der[i+1] + 1)));

	cout << *max_element(res.begin(), res.end()) << endl;

	return 0;
}
#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define fill_to_n(a,n,k) iota(a,a+n,k)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, p[100005], e[100005] = {0}, mx = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];

	for (int i = n - 1; i >= 0; i--) {
		e[p[i]] = e[p[i]+1] + 1;
		mx = max(mx, e[p[i]]);
	}

	cout << n - mx << endl;

	return 0;
}
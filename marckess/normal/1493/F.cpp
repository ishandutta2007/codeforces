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

const int MX = 1005;
int n, m, bs[MX];

int query (int h, int w, int i1, int j1, int i2, int j2) {
	cout << "? " << h << " " << w << " " << i1 << " " << j1 << " " << i2 << " " << j2 << endl;
	int r;
	cin >> r;
	return r;
}

bool goV (int j, int k) {
	if (j == k) return 1;
	
	int sz = j / k;
	
	if (query(k * (sz / 2), m, 1, 1, j - k * (sz / 2) + 1, 1))
		return goV(j - k * (sz / 2), k);
	
	return 0;
}

bool goH (int j, int k) {
	if (j == k) return 1;
	
	int sz = j / k;
	
	if (query(n, k * (sz / 2), 1, 1, 1, j - k * (sz / 2) + 1))
		return goH(j - k * (sz / 2), k);
	
	return 0;
}

int numDiv (int n) {
	int res = 0;
	for (int i = 1; i <= n; i++)
		res += n % i == 0;
	return res;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 2; i < MX; i++)
		if (!bs[i])
			for (int j = i * i; j < MX; j += i)
				bs[j] = 1;
		
	cin >> n >> m;
	
	int res = 1, j = n;
	for (int i = n; i > 1; i--)
		while (!bs[i] && j % i == 0)
			if (goV(j, j / i))
				j /= i;
			else
				break;
	
	res *= numDiv(n / j);
	
	j = m;
	for (int i = m; i > 1; i--)
		while (!bs[i] && j % i == 0)
			if (goH(j, j / i))
				j /= i;
			else
				break;
	
	res *= numDiv(m / j);
	
	cout << "! " << res << endl;
	
	return 0;
}
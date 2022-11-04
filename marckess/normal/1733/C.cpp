#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, a[MX];

void op (int i, int j) {
	cout << i + 1 << " " << j + 1 << endl;
	if ((a[i] + a[j]) % 2 == 1)
		a[j] = a[i];
	else
		a[i] = a[j];
}

void main_() {
	cin >> n ;
	forn (i, n)
		cin >> a[i];
	
	cout << n - 1 << endl;
	if (n > 1) op(0, n - 1);
	forr (i, 1, n - 2)
		if ((a[0] + a[i]) % 2 == 1)
			op(0, i);
		else
			op(i, n - 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}
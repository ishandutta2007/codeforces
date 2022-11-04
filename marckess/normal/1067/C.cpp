#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;
int mx[] = {1, 0, -1, 0};
int my[] = {0, 1, 0, -1};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	n--;

	cout << "0 0" << endl;
	for (int i = 0, j = 0; i < n; i++) {
		if (i % 4 == 0) j++;
		cout << j * mx[i%4] << " " << j * my[i%4] << endl; 
	}

	return 0;
}
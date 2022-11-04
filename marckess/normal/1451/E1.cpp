#include <bits/stdc++.h>

//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n;
int a[MX], res[MX];

int query (int i, int j, string op) {
	cout << op << " " << i << " " << j << endl;
	int r;
	cin >> r;
	if (r == -1) exit(0);
	return r;
}

void find (int i) {
	for (int j = i - 1; j >= 1; j--)
		res[j] = res[j + 1] ^ a[j];
	
	for (int j = i; j < n; j++)
		res[j + 1] = res[j] ^ a[j];
}

void ans () {
	cout << "!";
	for (int i = 1; i <= n; i++)
		cout << " " << res[i] << " ";
	exit(0);
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++)
		a[i] = query(i, i + 1, "XOR");
		
	for (int i = 1; i < n; i++)
		if (!a[i]) {
			res[i] = query(i, i + 1, "AND");
			find(i);
			ans();
		}
	
	map<int, int> mp;
	for (int i = 1, acu = 0; i < n; i++) {
		if (mp.count(acu ^ a[i])) {
			res[i + 1] = query(mp[acu ^ a[i]], i + 1, "AND");
			find(i + 1);
			ans();
		}
		mp[acu] = i;
		acu ^= a[i];
	}
	
	int mk = n - 1;
	for (int i = 1, acu = 0; i < n; i++) {
		acu ^= a[i];
		if (acu == (mk - 1)) {
			res[1] |= 1 & query(1, i + 1, "AND");
		}
		if (acu == 1) {
			res[1] |= (mk - 1) & query(1, i + 1, "AND");
		}
	}
	
	find(1);
	ans();
	
	return 0;
}
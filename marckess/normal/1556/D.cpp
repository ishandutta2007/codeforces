
// Problem : D. Take a Guess
// Contest : Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1556/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
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

const int MX = 10005;
int n, k, a[MX], o[MX], x[MX], v[MX];

int query (string op, int a, int b) {
	cout << op << " " << a << " " << b << endl;
	int res;
	cin >> res;
	return res;
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	
	for (int i = 2; i <= n; i++) {
		a[i] = query("and", 1, i);
		o[i] = query("or", 1, i);
		x[i] = a[i] ^ o[i];
	}
	
	a[0] = query("and", 2, 3);
	o[0] = query("or", 2, 3);
	
	forn (j, 30) {
		if ((a[2] & (1 << j)) || (a[3] & (1 << j)))
			v[1] |= (1 << j);
		
		if (o[2] & (1 << j))
			if (~o[0] & (1 << j))
				v[1] |= (1 << j);
	}
	
	//cout << v[1] << " ";
	for (int i = 2; i <= n; i++) {
		v[i] = x[i] ^ v[1];
		//cout << v[i] << " ";
	}
	//cout << endl;
	
	sort(v + 1, v + n + 1);
	cout << "finish " << v[k] << endl;
	
	return 0;
}
#include <bits/stdc++.h>

#define endl '\n'
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

const int MX = 300005;
int n, q, a[MX], in[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(in, -1, sizeof(in));
	
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (in[a[i]] == -1)
			in[a[i]] = i;
	}
	
	while (q--) {
		int t;
		cin >> t;
		
		cout << in[t] << " ";
		
		for (int i = 1; i <= 50; i++)
			if (i != t && in[i] != -1 && in[i] < in[t])
				in[i]++;
		in[t] = 1;
	}
	cout << endl;
    
	return 0;
}
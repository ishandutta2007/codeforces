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

const int MX = 200005;
int n, a[MX];
set<int> st;

void f (int n) {
	if (n < 0) return;
	auto it = st.lower_bound(n);
	
	int j = *it - n;
	for (int i = j, k = n; i <= n; i++, k--)
		a[i] = k;
	
	f(j - 1);
}

void main_() {
	cin >> n;
	f(n - 1);
	
	forn (i, n)
		cout << a[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	forn (i, MX) {
		st.insert(i * i);
		if (i * i > MX)
			break;
	}
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}
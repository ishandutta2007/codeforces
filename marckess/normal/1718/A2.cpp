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
int n, a[MX], dp[MX];
map<int, int> mp;

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
		
	mp.clear();
	mp[0] = 0;
	
	int acu = 0;
	forn (i, n) {
		dp[i] = (a[i] == 0) + (i ? dp[i - 1] : 0);
		
		acu ^= a[i];
		if (mp.count(acu))
			dp[i] = max(dp[i], mp[acu] + 1);
		
		mp[acu] = max(mp[acu], dp[i]);
	}
	
	cout << n - dp[n - 1] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}
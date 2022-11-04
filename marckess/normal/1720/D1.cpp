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

const int MX = 300005;
struct Node {
	int go[2], dp[2];
	
	Node () {
		memset(go, 0, sizeof(go));
		memset(dp, 0, sizeof(dp));
	}
};

int n, a[MX], sz = 1;
vector<Node> t;

void maxi (int &a, int b) {
	a = max(a, b);
}

int go (int pos, int i, int a, int b, int mx, int h) {
	if (b == -1) {
		maxi(t[pos].dp[h], mx + 1);
		return mx + 1;
	}
	
	int nex = (i & (1 << b)) == (a & (1 << b));
	
	if (t[pos].go[1 - nex])
		mx = max(mx, t[t[pos].go[1 - nex]].dp[bool(i & (1 << b))]);
	
	if (!t[pos].go[nex])
		t[pos].go[nex] = sz++;
	
	int res = go(
		t[pos].go[nex], i, a, b - 1, mx, bool(a & (1 << b))
	);
	
	maxi(t[pos].dp[h], res);
	return res;
}

void main_() {
	cin >> n;
	
	t = vector<Node>(n * 32, Node());
	sz = 1;
	
	int res = 0;
	forn (i, n) {
		cin >> a[i];
		res = max(res, go(0, i, a[i], 29, 0, 0));
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}
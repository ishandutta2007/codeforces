#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int maxv = 5e5 + 1;

int cnt[maxv] = {}, mcnt[maxv] = {}; // min count
int mmcnt = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, c;
	cin >> n >> c;
	vi A(n);
	REP(i, n) cin >> A[i];

	int ret = 0;

	REP(i, n) {
		int v = A[i];

		mcnt[v] = min(mcnt[v], cnt[v] - cnt[c]);

		cnt[v]++;
		// if (v == c) ret = max(ret, mmcnt);

		// cerr << i << ": " << cnt[v] << " / " << cnt[c] << " / " << mcnt[v] << endl;
		ret = max(ret, cnt[v] - cnt[c] - mcnt[v]);
		// mmcnt = max(mmcnt, -mcnt[v]);
	}

	ret += cnt[c];
	cout << ret << endl;
	return 0;
}
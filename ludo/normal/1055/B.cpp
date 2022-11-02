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

const int maxn = 1e5;

int n, m;
int QT[maxn], QP[maxn];

ll H[maxn], l, QD[maxn];

int ANS[maxn], nans = 0;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> l;
	REP(i, n) cin >> H[i];
	REP(i, m) {
		cin >> QT[i];
		if (QT[i] == 0) nans++;
		else {
			cin >> QP[i] >> QD[i];
			H[--QP[i]] += QD[i]; // do it now.
		}
	}

	if (nans == 0) return 0; // no queries

	int ret = 0;
	for (int i = 0; i < n; ) { 
		if (H[i] <= l) { i++; continue; }
		int j = i + 1;
		while (j < n && H[j] > l) j++;
		ret++;
		i = j;
	}

	int curit = nans;
	while (m--) {
		// process query m
		if (QT[m] == 0) {
			ANS[--curit] = ret;
			continue;
		}

		// lower hair at QP[m]
		int at = QP[m];
		if (H[at] > l && H[at] - QD[m] <= l) {
			
			bool lhigh = at > 0 && H[at-1] > l;
			bool rhigh = at+1<n && H[at+1] > l;

			if (lhigh && rhigh) {
				// split into two
				ret++;
			} else if (!lhigh && !rhigh) ret--; // singleton is gone
		}
		H[at] -= QD[m];
	}

	REP(i, nans) printf("%d\n", ANS[i]);

	return 0;
}
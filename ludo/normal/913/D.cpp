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

const int maxn = 2e5 + 10;

int n, a[maxn], t[maxn];
ll T;

vi map_a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> T;
	REP(i, n) cin >> a[i] >> t[i];
	REP(i, n) map_a[a[i]].pb(i);

	set<int> current;
	int timesum = 0;
	priority_queue<ii> pq;

	for (int k = n; k > 0; k--) {
		for (int idx : map_a[k]) {
			int time = t[idx];
			// consider to add time to pq.
			timesum += time;
			current.insert(idx);
			pq.emplace(time, idx);
		}

		while ((int) pq.size() > k || timesum > T) {
			timesum -= pq.top().x;
			current.erase(pq.top().y);
			pq.pop();
		}

		// cerr << k << ": " << pq.size() << " " << timesum << endl;
		if (pq.size() == k) {
			break;
		}
	}

	cout << current.size() << endl;
	cout << current.size() << endl;
	for (int i : current) cout << (i + 1) << " ";
	cout << endl;

	return 0;
}
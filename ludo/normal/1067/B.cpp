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

int N, indeg[maxn];
vi E[maxn];
bool removed[maxn] = {};

bool hedgehog(vi &leaves, int k)
{
	if (k <= 0)
		return k == 0 && leaves.size() == 1 && indeg[leaves.front()] == 0;

	if (leaves.size() < 3) return false;

	vi nextLeaves;

	// strip away all the leaves
	for (int l : leaves)
		if (indeg[l] != 1) return false;
/*
	for (int l : leaves) cerr << l << " ";
	cerr << endl;
*/
	for (int l : leaves) {
		removed[l] = true;
		for (int v : E[l]) {
			if (removed[v]) continue;
			nextLeaves.pb(v);
			indeg[v]--;
			break; // v is unique for this l
		}
	}

	sort(all(nextLeaves));

	/*
	for (int l : nextLeaves) cerr << l << " ";
	cerr << endl;
	*/

	for (int i = 0, n = nextLeaves.size(), cnt = 0; i < n; i++) {
		cnt++;
		if (i + 1 == n || nextLeaves[i] != nextLeaves[i + 1]) {
			// cerr << i << " -> " << cnt << endl;
			if (cnt < 3) return false;
			cnt = 0;
		}
	}
	nextLeaves.resize(unique(all(nextLeaves)) - nextLeaves.begin());

	return hedgehog(nextLeaves, k - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cin >> N >> k;
	if (N < 4 || k > 100) {
		cout << "No" << endl;
		return 0;
	}

	REP(i, N - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		E[a].pb(b); indeg[a]++;
		E[b].pb(a); indeg[b]++;
	}

	vi leaves;
	REP(i, N)
		if (indeg[i] == 1)
			leaves.pb(i);

	bool ans = hedgehog(leaves, k);

	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
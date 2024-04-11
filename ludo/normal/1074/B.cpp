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

const int maxn = 1001;

int N;
vi E[maxn];

int query(char ch, int x)
{
	cout << ch << " " << x << endl;
	cout.flush();
	int y;
	cin >> y;
	return y;
}


void run()
{
	cin >> N;
	REP(i, N + 1) E[i].clear();

	REP(i, N - 1) {
		int a, b;
		cin >> a >> b;
		E[a].pb(b);
		E[b].pb(a);
	}

	int k1, k2;

	cin >> k1; vi T1(k1); for (int &i : T1) cin >> i;
	cin >> k2; vi T2(k2); for (int &i : T2) cin >> i;

	int his = query('B', T2[0]);

	vector<bool> aremine(N + 1, false), arehis(N + 1, false);
	for (int i : T1) aremine[i] = true;
	for (int i : T2) arehis[i] = true;

	vector<bool> vis(N + 1, false);
	queue<int> q;
	q.push(his);
	int mine = -1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (aremine[cur]) {
			mine = cur;
			break;
		}
		for (int nxt : E[cur]) {
			if (!vis[nxt]) vis[nxt] = true, q.push(nxt);
		}
	}

	assert(mine > 0);
	int myloc = query('A', mine);

	if (arehis[myloc]) {
		cout << "C " << mine << endl;
		cout.flush();
	} else {
		cout << "C -1" << endl;
		cout.flush();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ntc;
	cin >> ntc;
	while (ntc--)
		run();
	return 0;
}
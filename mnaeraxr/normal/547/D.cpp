#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)4e5 + 10;

vector<pii> ady[MAXN];
int pnt[MAXN];
int color[MAXN], curColor;
int degree[MAXN];

void dfs(int s){
	for (;pnt[s] < (int)ady[s].size(); ++pnt[s]){
		auto cur = ady[s][pnt[s]];
		if (!color[cur.second]){
			color[cur.second] = curColor;
			curColor *= -1;
			degree[s]--; degree[cur.first]--;
			dfs(cur.first);
			break;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		int u, v; cin >> u >> v;
		v += 200000;
		ady[u].push_back(MP(v, i));
		ady[v].push_back(MP(u, i));
		degree[u]++; degree[v]++;
	}

	curColor = 1;
	for (int i = 0; i < MAXN; ++i){
		if ( degree[i] & 1)
			dfs(i);
	}
	for (int i = 0; i < MAXN; ++i){
		if (degree[i])
			dfs(i);
	}

	for (int i = 0; i < n; ++i){
		assert(abs(color[i]) == 1);
		cout << (color[i] > 0 ? 'r' : 'b');
	}
	cout << endl;

	return 0;
}
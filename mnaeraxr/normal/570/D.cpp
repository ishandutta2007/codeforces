#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 500100;

vi tree[maxn];
vector<pii> lst[maxn];
int pos[maxn], pnt;
int le[maxn], ri[maxn], __tm__;
int hei[maxn];
char s[maxn];
int tot[maxn][26];

void bfs(){
	queue<int> q;
	q.push(1);
	pnt = 0;
	while (!q.empty()){
		auto cur = q.front(); q.pop();
		pos[cur] = pnt++;
		tot[ pos[cur] ][s[cur - 1] - 'a']++;
		for (auto c : tree[cur])
			q.push(c);
	}
}

void dfs(int c, int h){
	hei[c] = h;
	le[c] = __tm__++;
	lst[h].push_back({le[c], pos[c]});
	for (auto x : tree[c])
		dfs(x, h + 1);
	ri[c] = __tm__++;
	lst[h].push_back({ri[c], pos[c]});
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;	
	for (int i = 2; i <= n; ++i){
		int f; cin >> f;
		tree[f].push_back(i);
	}

	cin >> s;

	bfs();
	__tm__ = 0;
	dfs(1, 1);

	for (int i = 1; lst[i].size(); ++i)
		sort(lst[i].begin(), lst[i].end());

	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 26; ++j)
			tot[i][j] += tot[i - 1][j];

	while (m--){
		int u, h;
		cin >> u >> h;

		if (h <= hei[u]){
			cout << "Yes\n";
		}
		else{
			int l1 = upper_bound(lst[h].begin(), lst[h].end(), pii(le[u], 0)) - lst[h].begin();
			int l2 = upper_bound(lst[h].begin(), lst[h].end(), pii(ri[u], 0)) - lst[h].begin();
			if (l1 == l2){
				cout << "Yes\n";
			}
			else{
				l1 = lst[h][l1].second - 1;
				l2 = lst[h][l2 - 1].second;
				int t = 0;
				for (int i = 0; i < 26 && t < 2; ++i){
					int val = tot[l2][i] - tot[l1][i];
					if (val & 1) ++t;
				}
				if (t == 2) cout << "No\n";
				else cout << "Yes\n";
			}
		}
	}

	return 0;
}
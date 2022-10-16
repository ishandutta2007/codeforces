#include<bits/stdc++.h>

#define endl '\n'
#define ll long long
using namespace std;

typedef long long int64;
typedef pair<int,int64> pii;
typedef multiset<int64> ms;

const int maxn = 200000 + 10;

int64 val[maxn], D[maxn];
vector<pii> adj[maxn];

void fix(pair<ms,int64> &M){
	ms &S = M.first;
	while (!S.empty() && *S.begin() < M.second)
		S.erase(*S.begin());
}

void merge(pair<ms,int64> &A, pair<ms,int64> &B){
	for (auto v : B.first)
		A.first.insert(v + A.second - B.second);
}

void print(pair<ms,int> A){
	cout << A.second << endl;
	for (auto u : A.first) cout << u << " ";
	cout << endl << endl;
}

pair<ms,int64> dfs(int s){
	pair<ms,int64> ans;

	for (auto e : adj[s]){
		auto cur = dfs(e.first);
		cur.second += e.second;

		fix(cur);

		if (ans.first.size() < cur.first.size()){
			ans.first.swap(cur.first);
			swap(ans.second, cur.second);
		}

		merge(ans, cur);

		cur.first.clear();
	}

	D[s] = ans.first.size();

	ans.first.insert(val[s] + ans.second);

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> val[i];

	for (int i = 2; i <= n; ++i){
		int p;
		int64 d;
		cin >> p >> d;

		adj[p].push_back(pii(i, d));
	}

	dfs(1);

	for (int i = 1; i <= n; ++i)
		cout << D[i] << " ";

	cout << endl;
}
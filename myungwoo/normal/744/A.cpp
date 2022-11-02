#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair<int, int> pii;

int N, M, K;
bool S[1001], V[1001];
vector <int> con[1001];

int dfs(int n, bool &special)
{
	V[n] = 1;
	if (S[n]) special = 1;
	int ret = 1;
	for (int t: con[n]) if (!V[t]){
		ret += dfs(t, special);
	}
	return ret;
}

int main()
{
	scanf("%d%d%d", &N, &M, &K);
	for (int i=1;i<=K;i++){
		int nd; scanf("%d", &nd);
		S[nd] = 1;
	}
	for (int i=1;i<=M;i++){
		int a, b; scanf("%d%d", &a, &b);
		con[a].pb(b); con[b].pb(a);
	}
	vector <pii> arr;
	for (int i=1;i<=N;i++) if (!V[i]){
		bool special = 0;
		int sz = dfs(i, special);
		arr.pb({sz, special});
	}
	int ans = 0, t = -1;
	for (int i=0;i<sz(arr);i++) if (arr[i].sc){
		if (t < 0 || arr[t].fr < arr[i].fr) t = i;
	}
	for (int i=0;i<sz(arr);i++) if (!arr[i].sc){
		arr[t].fr += arr[i].fr;
	}
	for (int i=0;i<sz(arr);i++) if (arr[i].sc){
		ans += (arr[i].fr)*(arr[i].fr-1)/2;
	}
	cout << ans-M << endl;
}
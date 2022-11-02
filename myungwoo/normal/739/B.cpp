#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;

int T, N;
int A[MAXN], ans[MAXN];
int par[MAXN], parv[MAXN]; lld D[MAXN];
vector <int> con[MAXN];

vector <lld> arr;
vector <int> val;

void dfs(int n)
{
	int t = lower_bound(all(arr), D[n]-A[n]) - arr.begin();
	val[sz(val)-1]++; val[t-1]--;
	arr.pb(D[n]); val.pb(0);
	for (int t: con[n]){
		int v = parv[t];
		D[t] = D[n] + v;
		dfs(t);
	}
	ans[n] = val.back();
	arr.pop_back(); val.pop_back();
	val[sz(val)-1] += ans[n];
}

int main()
{
	//for (scanf("%d", &T);T--;){
		scanf("%d", &N);
		for (int i=1;i<=N;i++)
			scanf("%d", A+i);
		for (int i=1;i<=N;i++)
			con[i].clear();
		for (int i=2;i<=N;i++){
			scanf("%d%d", par+i, parv+i);
			con[par[i]].pb(i);
		}
		arr = {-(lld)1e18}, val = {0};
		dfs(1);
//		static int ts = 0;
//		printf("#%d", ++ts);
		for (int i=1;i<=N;i++)
			printf("%d ", ans[i]);
		puts("");
//	}
}
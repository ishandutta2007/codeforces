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

#define MAXN 100005

int N;
int par[MAXN];
int S[MAXN];
double D[MAXN];
vector <int> con[MAXN];

void dfs(int n)
{
	S[n] = 1;
	for (int t: con[n]){
		dfs(t);
		S[n] += S[t];
	}
}

void dy(int n)
{
	int sum = S[n]-1;
	for (int t: con[n]){
		D[t] = D[n] + 1 + (sum - S[t]) / 2.;
		dy(t);
	}
}

int main()
{
	scanf("%d", &N);
	for (int i=2;i<=N;i++) scanf("%d", par+i), con[par[i]].pb(i);
	dfs(1);
	D[1] = 1; dy(1);
	for (int i=1;i<=N;i++) printf("%.7f ", D[i]); puts("");
}
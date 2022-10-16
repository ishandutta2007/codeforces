#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int64> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)2e5 + 10;
const int64 MOD = (int64)1e9 + 7;

int parent[MAXN];
vi ady[MAXN], P[MAXN], S[MAXN];
int64 dp[MAXN], top[MAXN];

void dfs1(int s){
	dp[s] = 1;
	P[s].push_back(1);
	for (auto child : ady[s]){
		dfs1(child);
		dp[s] *= 1 + dp[child];
		dp[s] %= MOD;
		P[s].push_back(dp[child] + 1);
		S[s].push_back(dp[child] + 1);
	}
	S[s].push_back(1);

	for (int i = 1; i < SZ(P[s]); ++i) P[s][i] = (P[s][i] * P[s][i - 1]) % MOD;
	for (int i = SZ(S[s]) - 2; i >= 0; --i) S[s][i] = (S[s][i] * S[s][i + 1]) % MOD;
}

void dfs2(int s){
	for (int i = 0; i < SZ(ady[s]); ++i){
		int child = ady[s][i];
		top[child] = P[s][i] * S[s][i + 1] % MOD * top[s] % MOD + 1;
		top[child] %= MOD;
		dp[child] = dp[child] * top[child] % MOD;
		dfs2(child);
	}
}

int main()
{
	int n; cin >> n;
	for (int i = 2; i <= n; ++i){
		cin >> parent[i];
		ady[parent[i]].push_back(i);
	}

	dfs1(1);
	top[1] = 1;
	dfs2(1);

	for (int i = 1; i <= n; ++i)
		cout << dp[i] << " ";
	cout << endl;
}
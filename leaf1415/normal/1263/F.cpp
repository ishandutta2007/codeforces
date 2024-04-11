#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define inf 1e9

using namespace std;
typedef pair<int, int> P;

int n, a, b;
vector<int> G[2005], G2[2005];
int x[1005], y[1005];
int l[2005], r[2005], l2[2005], r2[2005];
int sum[4005][4005], sum2[4005][4005];
int dp[1005];

int id;
void dfs(int v, vector<int> G[], int l[], int r[])
{
	l[v] = id++;
	for(int i = 0; i < G[v].size(); i++){
		dfs(G[v][i], G, l, r);
	}
	r[v] = id++;
}

int label[2005];
int dfs2(int v, vector<int> G[])
{
	if(label[v]) return label[v];
	vector<P> vec;
	for(int i = 0; i < G[v].size(); i++){
		int res = dfs2(G[v][i], G);
		vec.push_back(P(res, G[v][i]));
	}
	sort(vec.begin(), vec.end());
	G[v].clear();
	for(int i = 0; i < vec.size(); i++) G[v].push_back(vec[i].second);
	return vec.front().first;
}

void calc(vector<int> G[], int l[], int r[], int sum[4005][4005], int x[], int V)
{
	for(int i = 1; i <= V; i++) label[i] = 0;
	for(int i = 1; i <= n; i++) label[x[i]] = i;
	dfs2(1, G);
	
	id = 1;
	dfs(1, G, l, r);
	r[0] = 0, l[2001] = id;
	for(int i = 2; i <= V; i++) sum[l[i]][r[i]]++;
	for(int i = 1; i < 4005; i++){
		for(int j = 1; j < 4005; j++){
			sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
}

int get(int sum[4005][4005], int L, int R, int x[], int l[], int r[])
{
	L = r[x[L-1]]+1, R = l[x[R+1]]-1;
	return sum[4001][R] - sum[L-1][R];
}

int main(void)
{
	cin >> n;
	cin >> a;
	int p;
	for(int i = 2; i <= a; i++){
		cin >> p;
		G[p].push_back(i);
	}
	for(int i = 1; i <= n; i++) cin >> x[i];
	x[n+1] = 2001;
	
	cin >> b;
	for(int i = 2; i <= b; i++){
		cin >> p;
		G2[p].push_back(i);
	}
	for(int i = 1; i <= n; i++) cin >> y[i];
	
	calc(G, l, r, sum, x, a);
	calc(G2, l2, r2, sum2, y, b);
	
	for(int i = 0; i <= n; i++) dp[i] = -inf;
	dp[0] = 0;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j <= n; j++){
			dp[j] = max(dp[j], dp[i] + get(sum, i+1, j, x, l, r));
			dp[j] = max(dp[j], dp[i] + get(sum2, i+1, j, y, l2, r2));
		}
	}
	cout << dp[n] << endl;
	
	return 0;
}
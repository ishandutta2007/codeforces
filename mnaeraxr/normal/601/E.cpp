#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 30000 + 100;

const int64 PP = 10000019;
const int64 mod = 1000000007;

int B[maxn], E[maxn], V[maxn], W[maxn];

vector<int> st[4 * maxn];

void push(int p, int b, int e, int x, int y, int v){
	if (x <= b && e <= y) st[p].push_back(v);
	else{
		int m = (b + e) >> 1, l = p << 1, r = l | 1;
		if (x < m) push(l, b, m, x, y, v);
		if (m < y) push(r, m, e, x, y, v);
	}
}

vector<int> question;
int current = 0;

int dp[20][maxn], n, k;

void solve(int p, int b, int e, int lv){
	for (int i = 0; i <= k; ++i) dp[lv][i] = dp[lv - 1][i];	
	
	for (auto idx : st[p]){
		int v = V[idx], w = W[idx];
		
		for (int i = k; i >= w; --i)
			dp[lv][i] = max(dp[lv][i], dp[lv][i - w] + v);
	}
	
	if (b + 1 == e){
		if (question[current] == b){
			current++;
			int64 answer = 0;
	
			for (int i = k; i; --i)
				answer = (answer * PP % mod + dp[lv][i]) % mod;
			
			cout << answer << endl;
		}
	}
	else{
		int m = (b + e) >> 1, l = p << 1, r = l | 1;
		solve(l, b, m, lv + 1);
		solve(r, m, e, lv + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	
	for (int i = 1; i <= n; ++i){
		B[i] = 0, E[i] = oo;
		cin >> V[i] >> W[i];
	}
	
	int t = n;
	int q; cin >> q;
	
	for (int i = 1; i <= q; ++i){
		int typ; cin >> typ;
		
		if (typ == 1){
			t++;
			B[t] = i, E[t] = oo;
			cin >> V[t] >> W[t];
		}
		else if (typ == 2){
			int u; cin >> u;
			E[u] = i + 1;
		}
		else{
			question.push_back(i);
		}
	}
	
	question.push_back(oo);
	
	q++;
	
	for (int i = 1; i <= t; ++i){
		E[i] = min(E[i], q);
		push(1, 0, q, B[i], E[i], i);
	}	
	
	solve(1, 0, q, 1);
	
	return 0;
}
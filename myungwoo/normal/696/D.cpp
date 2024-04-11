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

int N, K; lld L;
int A[201];

struct NODE{
	int v, f, to[26];
} nodes[202];

struct MATRIX{
	lld dp[202][202];

	MATRIX operator * (const MATRIX &ot)const{
		MATRIX ret = {0,};
		for (int i=1;i<=K;i++) for (int j=1;j<=K;j++){
			ret.dp[i][j] = -4e18;
			for (int k=1;k<=K;k++) ret.dp[i][j] = max(ret.dp[i][j], dp[i][k]+ot.dp[k][j]);
		}
		return ret;
	}
} D[47], V;

int main()
{
	scanf("%d%lld", &N, &L); K = 1;
	for (int i=1;i<=N;i++) scanf("%d", A+i);
	for (int i=1;i<=N;i++){
		char buf[201] = {0, }; scanf("%s", buf);
		int idx = 1;
		for (int j=0;buf[j];j++){
			NODE &now = nodes[idx];
			if (!now.to[buf[j]-'a'])
				now.to[buf[j]-'a'] = ++K;
			idx = now.to[buf[j]-'a'];
		}
		NODE &now = nodes[idx];
		now.v += A[i];
	}
	queue <int> que;
	for (int i=0;i<26;i++) if (nodes[1].to[i]){
		int nd = nodes[1].to[i];
		nodes[nd].f = 1;
		que.push(nd);
	}
	while (!que.empty()){
		int q = que.front(); que.pop();
		int f = nodes[q].f;
		nodes[q].v += nodes[nodes[q].f].v;
		for (int i=0;i<26;i++) if (nodes[q].to[i]){
			int nd = nodes[q].to[i];
			int nf = f;
			while (nf > 1 && !nodes[nf].to[i]) nf = nodes[nf].f;
			if (nodes[nf].to[i]) nf = nodes[nf].to[i];
			nodes[nd].f = nf;
			que.push(nd);
		}
	}

	for (int i=1;i<=K;i++) for (int j=1;j<=K;j++)
		V.dp[i][j] = D[0].dp[i][j] = i == j ? 0 : -4e18;
	for (int i=1;i<=K;i++){
		for (int j=0;j<26;j++){
			int n = i;
			while (n > 1 && !nodes[n].to[j]) n = nodes[n].f;
			if (nodes[n].to[j]) n = nodes[n].to[j];
			D[0].dp[i][n] = max(D[0].dp[i][n], (lld)nodes[n].v);
		}
	}
	for (int i=1;i<47;i++) D[i] = D[i-1]*D[i-1];
	for (int i=0;i<47;i++) if ((L>>i)&1){
		V = V*D[i];
	}
	lld ans = 0;
	for (int i=1;i<=K;i++) ans = max(ans, V.dp[1][i]);
	printf("%lld\n", ans);
}
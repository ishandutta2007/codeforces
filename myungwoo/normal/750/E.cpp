#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair<int, int> pii;

#define MAXN 200005

int N, Q;
int A[MAXN];

struct DP{
	int v[6][6];

	void init(int t) {
		for (int i=0;i<6;i++){
			v[i][i] = 0;
			for (int j=i+1;j<6;j++) v[i][j] = 1e9;
		}
		if (t == 2){
			v[0][0] = 1; v[0][1] = 0;
		}else if (t == 0){
			v[1][1] = 1; v[1][2] = 0;
		}else if (t == 1){
			v[2][2] = 1; v[2][3] = 0;
		}else if (t == 7){
			v[3][3] = 1; v[3][4] = 0;
		}else if (t == 6){
			v[3][3] = v[4][4] = 1;
			v[3][5] = v[4][5] = 0;
		}
	}

	DP operator * (const DP &ot)const{
		DP ret = {0,};
		for (int i=0;i<6;i++) for (int j=i;j<6;j++){
			ret.v[i][j] = 1e9;
			for (int k=i;k<=j;k++)
				ret.v[i][j] = min(ret.v[i][j], v[i][k] + ot.v[k][j]);
		}
		return ret;
	}
};

struct NODE{
	DP dp;
	NODE *left, *right;
} *root;

NODE *make_tree(int s, int e)
{
	NODE *ret = new NODE();
	if (s == e){ ret->dp.init(A[s]); return ret; }
	int m = s+e >> 1;
	ret->left = make_tree(s, m);
	ret->right = make_tree(m+1, e);
	ret->dp = ret->left->dp * ret->right->dp;
	return ret;
}

void combine(NODE *now, int s, int e, int l, int r, DP &dp)
{
	if (e < l || s > r) return;
	if (l <= s && e <= r){
		dp = dp * now->dp;
		return;
	}
	int m = s+e >> 1;
	combine(now->left, s, m, l, r, dp);
	combine(now->right, m+1, e, l, r, dp);
}

int main()
{
	scanf("%d%d", &N, &Q);
	for (int i=1;i<=N;i++) scanf("%1d", A+i);
	root = make_tree(1, N);
	while (Q--){
		int a, b; scanf("%d%d", &a, &b);
		DP dp = {0,};
		for (int i=0;i<6;i++) for (int j=0;j<6;j++)
			dp.v[i][j] = i == j ? 0 : 1e9;
		combine(root, 1, N, a, b, dp);
		int ans = dp.v[0][4];
		printf("%d\n", ans < 1e9 ? ans : -1);
	}
}
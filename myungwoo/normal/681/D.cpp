#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

int N, M, K;
int A[MAXN];
int num[MAXN], out[MAXN], dep[MAXN], par[MAXN];
bool V[MAXN];
vector <int> con[MAXN], ans;

void dfs(int n)
{
	num[n] = ++K;
	for (int t: con[n]){
		dep[t] = dep[n]+1; dfs(t);
	}
	out[n] = K;
}

struct NODE{
	NODE(int v=0): v(v), left(0), right(0) {}
	int v;
	NODE *left, *right;
} *root;

NODE *make_tree(int s, int e)
{
	NODE *ret = new NODE();
	if (s == e) return ret;
	int m = (s+e)>>1;
	ret->left = make_tree(s, m);
	ret->right = make_tree(m+1, e);
	return ret;
}

void reg(NODE *now, int s, int e, int l, int r, int v)
{
	if (e < l || s > r) return;
	if (l <= s && e <= r){
		now->v = v;
		return;
	}
	int m = (s+e) >> 1;
	reg(now->left, s, m, l, r, v);
	reg(now->right, m+1, e, l, r, v);
}

int chk(NODE *now, int s, int e, int n)
{
	if (e < n || s > n) return 0;
	int ret = 0;
	if (now->v) ret = now->v;
	if (s == e) return ret;
	int m = (s+e) >> 1;
	int a = chk(now->left, s, m, n), b = chk(now->right, m+1, e, n);
	if (!ret || dep[ret] > dep[a]) ret = a;
	if (!ret || dep[ret] > dep[b]) ret = b;
	return ret;
}

int main()
{
	dep[0] = 2e9;
	scanf("%d%d", &N, &M);
	for (int i=0;i<M;i++){
		int a, b;
		scanf("%d%d", &a, &b); con[a].pb(b); par[b] = a;
	}
	for (int i=1;i<=N;i++) scanf("%d", A+i);
	for (int i=1;i<=N;i++) if (!par[i]) dfs(i);
	vector <int> arr;
	for (int i=1;i<=N;i++) arr.pb(i);
	sort(all(arr), [](const int &a, const int &b){
		return dep[A[a]] > dep[A[b]];
	});
	root = make_tree(1, N);
	int prev = 0;
	for (int n: arr){
		if (prev != A[n]){
			reg(root, 1, N, num[prev], out[prev], prev);
			prev = A[n];
		}
		int v = chk(root, 1, N, num[n]);
		if (v && v != A[n]){ puts("-1"); return 0; }
		if (V[A[n]]) continue;
		V[A[n]] = 1, ans.pb(A[n]);
//		reg(root, 1, N, num[A[n]], out[A[n]], A[n]);
	}
	for (int i=1;i<=N;i++) if (!V[A[i]]){
		V[A[i]] = 1; ans.pb(A[i]);
	}
	printf("%d\n", sz(ans));
	for (int t: ans) printf("%d\n", t);
}
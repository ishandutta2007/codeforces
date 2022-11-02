#include <vector>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define same(a, b) (fabs((a)-(b)) < eps)
#define set(arr, with) memset(arr, with, sizeof(arr));
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<int, lld> pil;
typedef pair<lld, int> pli;
typedef pair<lld, lld> pll;

#define MAXN 100005

int N, Q;
int X[MAXN], Y[MAXN], W[MAXN], S[MAXN], H[MAXN];
vector <int> con[MAXN];

void dfs(int n)
{
	S[n] = 1;
	for (int t: con[n]){
		if (H[t]) continue;
		H[t] = H[n]+1;
		dfs(t);
		S[n] += S[t];
	}
}

inline lld get(int x, int y)
{
	if (H[x] > H[y]) swap(x, y);
	int a = N-S[y], b = S[y];
	return (lld)a*b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int i, j, k;
	cin >> N;
	for (i=1;i<N;i++){
		cin >> X[i] >> Y[i] >> W[i];
		con[X[i]].pb(Y[i]);
		con[Y[i]].pb(X[i]);
	}
	H[1] = 1; dfs(1);
	lld sum = 0;
	for (i=1;i<N;i++){
		int x = X[i], y = Y[i], w = W[i];
		lld c = get(x, y);
		sum += c * W[i];
	}
	lld count = (lld) N * (N-1) / 2;
	for (cin >> Q;Q--;){
		cin >> i >> k;
		int x = X[i], y = Y[i], w = W[i];
		lld c = get(x, y);
		sum -= c * (w-k);
		W[i] = k;
		printf("%.10lf\n", sum * 3 / (double)count);
	}
}
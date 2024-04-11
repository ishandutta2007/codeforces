#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 500500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
int tree[4 * maxn];

void Build(int v, int tl, int tr) {
	if (tl == tr) {
		tree[v] = a[tl];
		return;
	}
	int new_v = v << 1;
	int mid = (tl + tr) >> 1;
	Build(new_v, tl, mid);
	Build(new_v + 1, mid + 1, tr);
	tree[v] = __gcd(tree[new_v], tree[new_v + 1]);
}

void Update(int v, int tl, int tr, int pos, int x) {
	if (tl == tr) {
		tree[v] = x;
		return;
	}
	int new_v = v << 1;
	int mid = (tl + tr) >> 1;
	if (pos <= mid)
		Update(new_v, tl, mid, pos, x);
	else
		Update(new_v + 1, mid + 1, tr, pos, x);
	tree[v] = __gcd(tree[new_v], tree[new_v + 1]);
}

int SolveR(int v, int tl, int tr, int l, int r, int x) {
	if (tl == tr)
		if (tree[v] % x == 0)
			return l;
		else
			return l - 1;
	if (tl == l && tr == r && tree[v] % x == 0)
		return tr;
	int new_v = v << 1;
	int mid = (tl + tr) >> 1;
	if (l > mid)
		return SolveR(new_v + 1, mid + 1, tr, l, r, x);
	int pos = SolveR(new_v, tl, mid, l, min(r, mid), x);
	if (pos == mid)
		return SolveR(new_v + 1, mid + 1, tr, mid + 1, r, x);
	return pos;
}

int SolveL(int v, int tl, int tr, int l, int r, int x) {
	if (tl == tr)
		if (tree[v] % x == 0)
			return l;
		else
			return l + 1;
	if (tl == l && tr == r && tree[v] % x == 0)
		return tl;
	int new_v = v << 1;
	int mid = (tl + tr) >> 1;
	if (r <= mid)
		return SolveL(new_v, tl, mid, l, r, x);
	int pos = SolveL(new_v + 1, mid + 1, tr, max(l, mid + 1), r, x);
	if (pos == mid + 1)
		return SolveL(new_v, tl, mid, l, mid, x);
	return pos;
}


int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i)
    	scanf ("%d", &a[i]);
    Build(1, 1, n);
    int q;
    scanf ("%d", &q);
    while (q--) {
    	int type;
    	scanf ("%d", &type);
    	if (type == 1) {
    		int l, r, x;
    		scanf ("%d%d%d", &l, &r, &x);
    		int L = SolveR(1, 1, n, l, n, x);
    		int R = SolveL(1, 1, n, 1, r, x);
    		// cout << L << ' ' << R << endl;
    		if (L >= R - 2)
    			puts("YES");
    		else
    			puts("NO");
    	}
    	if (type == 2) {
    		int pos, x;
    		scanf ("%d%d", &pos, &x);
    		Update(1, 1, n, pos, x);
    	}
    }
    return 0;
}
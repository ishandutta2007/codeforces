#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl '\n'

const int maxn = 200100;

int f[maxn], c[maxn];
int nxt[maxn], prv[maxn];

int root(int a){
	return f[a] == a ? a : f[a] = root(f[a]);
}

bool join(int a, int b){
	a = root(a); b = root(b);
	if (a == b) return false;
	if (c[a] > c[b]) swap(a, b);
	c[b] += c[a];
	f[a] = b;
	return true;
}

int getprev(int a){
	int cur = a;
	while (prv[cur] != cur)
		cur = prv[cur];
	while (a != cur)
	{
		int tmp = prv[a];
		prv[a] = cur;
		a = tmp;
	}
	return prv[a];
}

int getnext(int a){
	a = getprev(a);
	int v = nxt[a];
	if (root(v) == root(a)){
		nxt[a] = getnext(v);
		prv[v] = a;
	}
	return nxt[a];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	for (int i = 0; i <= n; ++i)
	{
		prv[i] = f[i] = i;
		nxt[i] = i + 1;
		c[i] = 1;
	}

	while (q--){
		int m, u, v;
		cin >> m >> u >> v;
		if (m == 1){
			join(u, v);
		}
		else if (m == 2){
			for (int i = u; i <= v; i = getnext(i))
				join(u, i);
		}
		else
			cout << (root(u) == root(v) ? "YES" : "NO") << endl;
	}

	return 0;
}
#include <bits/stdc++.h>

//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <bitset>

using namespace std;

#define bits(mask, ci, cm) assert(mask >= 0); for(int _= mask,cm=_&-_,ci=__lg(cm);_;_^= cm,cm=_&-_,ci=__lg(cm))

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 14;
const int max2n = 1 << maxn;

int64 dp[maxn][max2n];
bool m[maxn][max2n];
int adj[maxn];
pair<pii, int> lca[maxn * maxn];
int totn, totq;

void end(int64 ans = 0){
	cout << ans << endl;
	exit(0);
}

void print(int root, int mask, int spa = 0){
	for (int i = 0; i < spa; ++i) cout << " ";
	cout << root << " " << bitset<4>(mask) << endl;
}

void myassert(bool b, int r, int mask){
	if (!b){
		cout << "ERROR FOUND" << endl;
		print(r, mask);
		exit(0);
	}
}

int64 solve(int root, int mask, int num){
//	print(root, mask, num);
	myassert(mask & (1 << root), root, mask);

	if ((mask & (mask - 1)) == 0)
		return 1;

	if (m[root][mask]) return dp[root][mask];
	m[root][mask] = true;
	int64 &ans = dp[root][mask];

	int rmask = mask ^ (1 << root);
	int root_mask = 1 << root;
	int pmask = 1 << __lg(rmask); // pivot mask

	int fmask = rmask ^ pmask;
//	cout << "BEGIN: " << endl;
	for (int smask = fmask; ; smask = (smask - 1) & fmask){
//		cout << smask << " HERE" << endl;

		int ssmask = smask | pmask;
		int compmask = mask ^ ssmask;

		bool ok = true;
		int tn = -1;

		bits(ssmask, ci, cm){
			if ((adj[ci] & (ssmask | root_mask)) != adj[ci])ok = false;
			if (adj[ci] & root_mask){
				if (tn == -1) tn = ci;
				else ok = false;
			}
			if (!ok) break;
		}

		// checking lca conditions
		for (int i = 0; i < totq && ok; ++i){
			int am = 1 << lca[i].first.first;
			int bm = 1 << lca[i].first.second;
			int ci = lca[i].second;
			int cm = 1 << lca[i].second;
			if ((am & ssmask) && (bm & ssmask))if ((ssmask & cm) == 0) ok = false;
			if ((am & compmask) && (bm & compmask))if ((compmask & cm) == 0) ok = false;
			if ((am & ssmask) && (bm & compmask))if (ci != root) ok = false;
			if ((am & compmask) && (bm & ssmask))if (ci != root) ok = false;
		}

		if (ok){
			if (tn != -1){
				ans = ans + solve(tn, ssmask, num + 1) * solve(root, compmask, num + 1);
			}
			else{
				bits(ssmask, ci, cm) if (ci != root){
					int64 first = solve(ci, ssmask, num + 1);
					int64 second = solve(root, compmask, num + 1);
					ans = ans + first * second;
				}
			}
		}

		if (smask == 0) break;
	}

//	print(root, mask, num);
//	for (int i = 0; i < num; ++i) cout << " ";
//	cout << "ans: " << ans << endl;
	return ans;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;
	totn = n, totq = q;

	for (int i = 0; i < m; ++i){
		int u, v; cin >> u >> v;
		--u; --v;
		adj[u] |= 1 << v;
		adj[v] |= 1 << u;
	}

	for (int i = 0; i < q; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b; --c;
		lca[i] = make_pair(pii(a, b), c);
	}


	cout << solve(0, (1 << n) - 1, 0) << endl;

	return 0;
}

/*
6 1 0
3 5
 */
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1000000000 + 10;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>,
        rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct BIT{
	ordered_set tree;

	void update(int idx){
		tree.insert( idx );
	}

	int query(int idx){
		return tree.order_of_key(idx + 1);
	}
};

struct station{
	int x, r, f;

	bool operator <(const station &s){
		return r > s.r;
	}
};

int main(){
	map<int,BIT> X;

	int n, k;
	scanf("%d%d", &n, &k);

	vector<station> S(n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d%d", &S[i].x, &S[i].r, &S[i].f);
	}

	sort(S.begin(), S.end());

	int64 answer = 0;

	for (int i = 0; i < n; ++i){
		for (int d = -k + S[i].f; d <= S[i].f + k; ++d){
			if (!X.count(d)) continue;

			BIT &b = X[d];
			int cur = b.query(S[i].x + S[i].r) - b.query(S[i].x - S[i].r - 1);
			answer += cur;
		}

		X[ S[i].f ].update( S[i].x );
	}

	printf("%lld\n", answer);

	return 0;
}
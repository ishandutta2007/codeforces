#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long int64;

const int maxn = 100100;

struct line{
	int64 m, n, p;
	int64 eval(int64 x){
		return m * x + n;
	}
};

line stck[maxn];
int top;

int64 a[maxn], ac[maxn];
int64 ans[maxn];
pair<pii,int> queries[maxn];

bool bad(line a, line b, line c){
	return (b.n - c.n) * (c.m - a.m) <= (a.n - c.n) * (c.m - b.m);
}

int main()
{
	top = -1;
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int q; cin >> q;

	for (int i = 0; i < q; ++i){
		cin >> queries[i].first.second >> queries[i].first.first;
		queries[i].second = i;
	}

	sort(queries, queries + q);

	for (int i = 1, p = 0; i <= n; ++i){
		ac[i] = ac[i - 1] + a[i];
		while (top >= 0 && stck[top].m >= a[i]) --top;
		while (top > 0 && bad(stck[top], stck[top - 1], (line){a[i], i * a[i] - ac[i], i}))
			--top;
		stck[++top] = {a[i], i * a[i] - ac[i], i};

		for (;p < q && queries[p].first.first == i; ++p){	
			int64 x = queries[p].first.second - queries[p].first.first;
			int lo = -1, hi = top;
			while (lo + 1 < hi){
				// cout << ":: " << lo << " " << hi << endl;
				int mid = (lo + hi) / 2;
				if (stck[mid].p <= queries[p].first.first - queries[p].first.second) lo = mid;
				else{
					if (stck[mid + 1].eval(x) <= stck[mid].eval(x)) lo = mid;
					else hi = mid;
				}
			}
			// cout << ":: " << lo << " " << hi << endl;
			ans[queries[p].second] = ac[i] + stck[hi].eval(x);
			// for (int kk = 0; kk <= top; ++kk)
			// 	cout << stck[kk].m << " " << stck[kk].n << " " << stck[kk].p << endl;

			// cout << hi << " " << x << endl;
		}
	}	
	for (int i = 0; i < q; ++i)
		cout << ans[i] << endl;
}
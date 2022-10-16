#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxd = 1000010;
const int maxn = 500010;

int last[maxd];
int bit[maxn];

void update(int idx, int v){
	while (idx < maxn){
		bit[idx] += v;
		idx += idx & -idx;
	}
}

int query(int idx){
	int ans = 0;
	while (idx){
		ans += bit[idx];
		idx -= idx & -idx;
	}
	return ans;
}

int iquery(int a, int b){
	return query(b) - query(a - 1);
}

void compare(pii &a, pii b){
	if (b.second - b.first > a.second - a.first)
		a = b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	pii ans = pii(1, 1);

	for (int i = 1; i <= n; ++i){
		int cur; cin >> cur;

		if (last[cur]) update(last[cur], -1);
		last[cur] = i;
		update(last[cur], 1);

		if (query(i) <= k) compare(ans, pii(1, i));
		else{
			int lo = 1, hi = n;
			while (lo + 1 < hi){
				int mid = (lo + hi) / 2;
				if (iquery(mid, n) <= k) hi = mid;
				else lo = mid;
			}
			compare(ans, pii(hi, i));
		}
	}


	cout << ans.first << " " << ans.second << endl;

	return 0;
}
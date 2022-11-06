#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long
#define eb emplace_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define N 3000
#define MOD 998244353



int main() {
	int n, x, y, sz1, sz2;
	int p2[20];
	vector<int>a[20];
	vector<pii>ans;
	p2[0] = 1;
	rep(i, 19)p2[i + 1] = p2[i] * 2;
  cin>>n;
	x = 0;
	y = 0;
	for (int i = 19; i >= 0; i--) {
		if (p2[i] <= n) {
			rep(j, p2[i]) {
				a[y].push_back(x + j);
			}
			rep(j, i) {
				rep(ii, p2[i - j-1]) {
					rep(jj, p2[j]) {
						ans.push_back({ x + (ii*p2[j + 1]) + jj, x + (ii*p2[j + 1]) + p2[j] + jj });
					}
				}
			}
			n -= p2[i];
          x+=p2[i];
			y++;
		}
	}
	while(y > 2) {
		sz1 = a[y - 1].size();
		sz2 = a[y - 2].size();
		if (sz1 == sz2) {
			rep(i, sz1) {
				ans.push_back({a[y-1][i],a[y-2][i]});
				a[y - 2].push_back(a[y - 1][i]);
			}
			a[y - 1].clear();
			y--;
		}
		else {
			sz2 = a[0].size();
			sz2--;
			rep(i, sz1) {
				ans.push_back({ a[y - 1][i],a[0][sz2 - i] });
				a[y - 1].push_back(a[0][sz2 - i]);
				a[0].pop_back();
			}
		}
	}
	sz1 = ans.size();
	cout << sz1 << endl;
	rep(i, sz1) {
		cout << (ans[i].first)+1 << " " << (ans[i].second)+1 << endl;
	}
	return 0;
}
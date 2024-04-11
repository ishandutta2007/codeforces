#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007  //998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;



int main() {
	int n, m;
	int l, r;
	int x, y, z;
	int ss;
	int a[32][32];
	vector<pair<pii, int> >ans;
	cin >> l >> r;
	rep(i, 32) {
		rep(j, 32)a[i][j] = MOD;
		a[i][i] = 0;
	}
	ss = r - l + 1;
	y = 1;
	rep(i, 31) {
		if (ss <= y) {
			ss--;
			a[0][i + 1] = 1;
			z = 1;
			x = 2;
			rep2(j, 1, i) {
				if (ss%x != 0) {
					a[j][i + 1] = z;
					z += (x / 2);
					ss -= (x / 2);
				}
				x *= 2;
			}
			break;
		}
		else {
			x = 1;
            a[0][i+1]=1;
			rep2(j,1, i) {
				a[j][i + 1] = x;
				x *= 2;
			}
		}
		y *= 2;
	}
	n = 0;
	rep(i, 32) {
		rep2(j, i + 1, 31) {
			if (a[i][j] < MOD) {
				n = max(n, j+1);
				if (i == 0)ans.pb({ {i + 1,j + 1},a[i][j] + l - 1 });
				else ans.pb({ {i + 1,j + 1},a[i][j] });
			}
		}
	}
	m = ans.size();
  cout<<"YES"<<endl;
	cout << n << " " << m << endl;
	rep(i, m) {
		cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << endl;
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;


ll inv[5] = {0, 1, 3, 2, 4};
void swapRows(ll mat[505][1005], int i, int j, int w, int q)
{
	for(int k = 1; k <= w+q; k++) swap(mat[i][k], mat[j][k]);
}
void GaussianElimination(ll mat[505][1005], int w, int h, ll q)
{
	int r = 1, d;
	for(int i = 1; i <= w && r <= h; i++){
		if(mat[i][r] == 0){
			int max_val = 0, max_j;
			for(int j = r+1; j <= h; j++){
				if(mat[j][i] > max_val){
					max_val = mat[j][i];
					max_j = j;
				}
			}
			if(max_val == 0) goto end;
			swapRows(mat, r, max_j, w, q);
		}

		d = inv[mat[r][i]];
		for(int j = 1; j <= w+q; j++) mat[r][j] *= d, mat[r][j] %= 5;

		for(int j = 1; j <= h; j++){
			if(j == r) continue;
			if(mat[j][i] == 0) continue;
			ll x = mat[j][i];
			for(int k = 1; k <= w+q; k++){
				(mat[j][k] += 5 - mat[r][k]*x%5) %= 5;
			}
		}
		r++;
		end:;
	}
}

ll n, m, Q;
string s[505], t[305];
ll mat[505][1005];
ll beki[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	beki[0] = 1;
	rep(i, 1, 1000) beki[i] = beki[i-1] * 5 % mod;

	cin >> n >> m;
	rep(i, 1, n) cin >> s[i];
	cin >> Q;
	rep(i, 1, Q) cin >> t[i];

	rep(i, 1, n){
		rep(j, 0, m-1){
			mat[j+1][i] = s[i][j]-'a';
		}
	}
	rep(i, 1, Q){
		rep(j, 0, m-1){
			mat[j+1][n+i] = t[i][j]-'a';
		}
	}

	/*rep(i, 1, m){
		rep(j, 1 ,n+Q) cout << mat[i][j] << " "; cout << endl;
	}
	cout << endl;*/

	GaussianElimination(mat, n, m, Q);

	ll pos = m+1;
	rep(i, 1, m){
		bool flag = false;
		rep(j, 1, n) if(mat[i][j]) flag = true;
		if(!flag){
			pos = i;
			break;
		}
	}

	/*rep(i, 1, m){
		rep(j, 1,n+Q) cout << mat[i][j] << " "; cout << endl;
	}*/

	rep(q, 1, Q){
		ll ans = beki[n-(pos-1)];
		rep(j, pos, m){
			if(mat[j][n+q]) ans = 0;
		}
		cout << ans << endl;
	}

	return 0;
}
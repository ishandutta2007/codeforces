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

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

int n;
int a[705];
bool can[705][705];
bool ldp[705][705], rdp[705][705];

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n){
		rep(j, 1, n){
			can[i][j] = (gcd(a[i], a[j]) > 1);
		}
	}
	
	rep(i, 1, n-1) ldp[i][i] = can[i][i+1];
	rep(i, 2, n) rdp[i][i] = can[i-1][i];
	
	rep(len, 2, n){
		for(int l = 1; l+len-1 <= n; l++){
			int r = l+len-1;
			if(r <= n-1){
				rep(k, l, r){
					if(!can[r+1][k]) continue;
					if(k > l && !ldp[l][k-1]) continue;
					if(k < r && !rdp[k+1][r]) continue;
					ldp[l][r] = true;
					break;
				}
			}
			if(l >= 2){
				rep(k, l, r){
					if(!can[l-1][k]) continue;
					if(k > l && !ldp[l][k-1]) continue;
					if(k < r && !rdp[k+1][r]) continue;
					rdp[l][r] = true;
					break;
				}
			}
		}
	}
	
	bool ans = false; llint l = 1, r = n;
	rep(k, 1, n){
		if(k > l && !ldp[l][k-1]) continue;
		if(k < r && !rdp[k+1][r]) continue;
		ans = true;
	}
	rep(k, l, r){
		if(k > l && !ldp[l][k-1]) continue;
		if(k < r && !rdp[k+1][r]) continue;
		ans = true;
	}
	
	if(ans) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
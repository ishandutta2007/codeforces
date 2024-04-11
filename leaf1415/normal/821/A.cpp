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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size()-1; (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
ll a[55][55];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) rep(j, 1, n) cin >> a[i][j];
	
	rep(i, 1, n) rep(j, 1, n){
		if(a[i][j] == 1) continue;
		bool flag = false;
		rep(k, 1, n) rep(l, 1, n){
			if(a[i][j] == a[i][k] + a[l][j]) flag = true;
		}
		if(!flag){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES"<< endl;
	
	return 0;
}
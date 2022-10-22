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
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
ll a[5005], b[5005];
ll p[5005], q[5005];
ll ans[5005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 0, n-1){
		cout << "? " << 0 << " " << i << endl;
		cin >> a[i];
	}
	rep(i, 0, n-1){
		cout << "? " << i << " " << 0 << endl;
		cin >> b[i];
	}
	
	ll cnt = 0;
	rep(i, 0, n-1){
		p[0] = i;
		rep(j, 0, n-1) q[j] = p[0] ^ a[j];
		rep(j, 1, n-1) p[j] = q[0] ^ b[j];
		bool flag = true;
		rep(j, 0, n-1) if(p[q[j]] != j) flag = false;
		if(flag){
			if(cnt == 0) rep(j, 0, n-1) ans[j] = p[j];
			cnt++;
		}
	}
	
	cout << "!" << endl;
	cout << cnt << endl;
	rep(i, 0, n-1) cout << ans[i] << " "; cout << endl;
	
	return 0;
}
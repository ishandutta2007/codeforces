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
typedef pair<P, llint> T;

ll n, Q, m;
ll a[200005];
ll t[200005], l[200005], r[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q >> m;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, Q) cin >> t[i] >> l[i] >> r[i];
	
	ll b;
	rep(i, 1, m){
		cin >> b;
		for(int j = Q; j >= 1; j--){
			if(l[j] > b || r[j] < b) continue;
			if(t[j] == 1){
				if(l[j] == b) b = r[j];
				else b--;
			}
			else b = r[j]-(b-l[j]);
		}
		cout << a[b] << " ";
	}
	cout << endl;
	
	return 0;
}
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
typedef long long ll;
typedef pair<llint, llint> P;

ll n, m, c;
ll a[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> c;

	ll l = 0, r = n+1, x, p;
	rep(i, 1, m){
		if(l >= r-1) break;
		cin >> x;
		if(x <= c/2){
			p = l+1;
			rep(j, 1, l){
				if(a[j] > x){
					p = j;
					break;
				}
			}
			if(p == l+1) l++;
			a[p] = x;
		}
		else{
			p = r-1;
			for(int j = n; j >= r; j--){
				if(a[j] < x){
					p = j;
					break;
				}
			}
			if(p == r-1) r--;
			a[p] = x;
		}
		cout << p << endl;
	}

	return 0;
}
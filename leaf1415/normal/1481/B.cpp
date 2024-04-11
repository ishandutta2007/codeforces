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
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll T;
ll n, k;
ll h[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> k;
		rep(i, 1, n) cin >> h[i];
		
		ll p;
		rep(i, 1, k){
			p = n;
			rep(i, 1, n-1){
				if(h[i] < h[i+1]){
					h[i]++;
					p = i;
					break;
				}
			}
			if(p >= n){
				cout << -1 << endl;
				goto end;
			}
			if(i == k){
				cout << p << endl;
				goto end;
			}
		}
		end:;
	}
	
	return 0;
}
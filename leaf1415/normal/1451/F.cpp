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

ll T;
ll n, m;
ll a[105][105];
ll sum[205];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, 1, n){
			rep(j, 1, m){
				cin >> a[i][j];
			}
		}
		rep(i, 1, n+m) sum[i] = 0;
		
		rep(i, 1, n){
			rep(j, 1, m){
				sum[i+j] ^= a[i][j];
			}
		}
		
		rep(i, 1, n+m){
			if(sum[i]){
				cout << "Ashish" << endl;
				goto end;
			}
		}
		cout << "Jeel" << endl;
		end:;
	}
	
	return 0;
}
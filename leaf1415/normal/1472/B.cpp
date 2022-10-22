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
ll n;
ll a[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		ll cnt = 0, cnt2 = 0;
		rep(i, 1, n){
			cin >> a[i];
			if(a[i] == 1) cnt++;
			else cnt2++;
		}
		
		rep(i, 0, cnt2){
			rep(j, 0, cnt){
				if(2*i+j == 2*(cnt2-i)+(cnt-j)){
					cout << "YES" << endl;
					goto end;
				}
			}
		}
		cout << "NO" << endl;
		end:;
		
	}
	
	return 0;
}
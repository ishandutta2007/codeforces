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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
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
vector<ll> vec;
ll x;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	rep(i, 1, 20000) vec.push_back(i*i*i);
	
	cin >> T;
	while(T--){
		cin >> x;
		for(auto y : vec){
			if(y >= x) break;
			if(*lower_bound(all(vec), x-y) == x-y){
				cout << "Yes" << endl;
				goto end;
			}
		}
		cout << "No" << endl;
		end:;
	}
	
	return 0;
}
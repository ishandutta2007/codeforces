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

ll Q;
vector<ll> vec, svec;

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> Q;
	
	ll t, x, sum = 0;
	while(Q--){
		cin >> t;
		if(t == 1){
			cin >> x;
			vec.push_back(x);
			sum += x;
			svec.push_back(sum);
		}
		else{
			if(vec.size() == 1){
				printf("%.11f\n", 0.0);
				continue;
			}
			ll ub = (int)vec.size()-1, lb = 0, mid;
			while(ub-lb>1){
				mid = (ub+lb)/2;
				if(svec[mid]+vec.back() >= vec[mid] * (mid+2)) lb = mid;
				else ub = mid;
			}
			printf("%.11f\n", vec.back() - (double)(svec[lb]+vec.back())/(lb+2));
		}
	}
	
	return 0;
}
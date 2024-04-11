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
typedef pair<P, llint> E;


llint L, R;
vector<E> vec;

int main(void)
{
	cin >> L >> R;
	
	ll n, s, rem;
	if(L == 1) s = 1, rem = R-1, n = 22;
	else{
		vec.push_back(E(P(1, 2), L-1));
		R -= L-1;
		s = 2, rem = R-1, n = 23;
	}
	
	vec.push_back(E(P(s, n), 1));
	for(int i = 19; i >= 0; i--){
		if(rem & (1<<i)){
			rem -= (1<<i);
			vec.push_back(E(P(s, n-(i+1)), 1+rem));
		}
	}
	
	rep(i, 1, 20){
		vec.push_back(E(P(n-i, n), 1));
		rep(j, 1, i-1) vec.push_back(E(P(n-i, n-j), 1<<(j-1)));
	}
	
	cout << "YES" << endl;
	cout << n << " " << vec.size() << endl;
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i].first.first << " " << vec[i].first.second << " " << vec[i].second << endl;
	}
	
	return 0;
}
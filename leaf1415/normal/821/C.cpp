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
stack<ll> stk;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	ll id = 0, ans = 0;
	string s; ll x;
	rep(i, 1, 2*n){
		cin >> s;
		if(s == "add"){
			cin >> x;
			stk.push(x);
		}
		else{
			id++;
			if(stk.size() == 0) continue;
			if(stk.top() != id){
				while(stk.size()) stk.pop();
				ans++;
			}
			else stk.pop();
		}
	}
	cout << ans << endl;
	
	return 0;
}
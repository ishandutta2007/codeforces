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
typedef pair<llint, llint> P;

llint n;
llint a[150005], b[150005];
bool prime[100005];

set<llint> S;

void calc(llint x)
{
	rep(i, 2, 100000){
		if(prime[i]) continue;
		while(x % i == 0){
			S.insert(i);
			x /= i;
		}
	}
	if(x > 1) S.insert(x);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	rep(i, 2, 100000){
		if(prime[i]) continue;
		for(int j = 2*i; j < 100005; j+=i) prime[j] = true;
	}
	
	cin >> n;
	rep(i, 1, n) cin >> a[i] >> b[i];
	calc(a[1]), calc(b[1]);
	S.erase(1);
	
	for(auto x: S){
		bool flag = true;
		rep(i, 1, n){
			if(a[i] % x && b[i] % x){
				flag = false;
				break;
			}
		}
		if(flag){
			cout << x << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	
	return 0;
}
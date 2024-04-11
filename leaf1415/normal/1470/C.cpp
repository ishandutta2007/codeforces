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

ll n, k;
ll B = 350;

ll query(ll x)
{
	ll res;
	cout << "?" << " " << (x%n+n)%n+1 << endl;
	cin >> res;
	return res;
}

void output(ll x)
{
	cout << "!" << " " << (x%n+n)%n+1 << endl;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	
	ll res;
	rep(i, 1, B) query(0);
	
	if(n <= 100){
		rep(i, 0, n-1){
			ll pre, cur;
			pre = query(i), cur = query(i-1);
			if(pre > k && pre > cur){
				output(i-1);
				return 0;
			}
		}
	}
	
	
	ll p;
	rep(i, 0, B-1){
		if(query(n/B*i) != k){
			p = n/B*i;
			break;
		}
	}
	while(query(p) < k) p += B;
	
	while(1){
		ll pre, cur;
		pre = query(p);
		cur = query(p-10);
		if(pre > cur) break;
		p -= 10;
	}
	
	while(1){
		ll pre, cur;
		pre = query(p);
		cur = query(p-1);
		if(pre > cur){
			output(p-1);
			return 0;
		}
		p--;
	}
	
	
	return 0;
}
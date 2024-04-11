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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint T;
bool prime[10005];
vector<llint> pvec, fvec;

llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

llint get(llint p)
{
	llint ret = 1;
	while(ret*p <= 1000000000) ret *= p;
	return ret;
}

llint calc(llint x, llint p)
{
	llint ret = 0;
	while(x % p == 0) x /= p, ret++;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i = 2; i < 10005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 10005; j+=i) prime[j] = true;
	}
	for(int i = 2; i < 10005; i++){
		if(!prime[i]) pvec.push_back(i);
	}
	
	cin >> T;
	for(int t = 0; t < T; t++){
		
		fvec.clear();
		llint ans = 1, pos = 0, res;
		for(int i = 0; i < 22; i++){
			if(i <= 15){
				vector<llint> tmp;
				llint mul = 1;
				while(mul <= 1000000000000000000LL / pvec[pos]){
					mul *= pvec[pos];
					tmp.push_back(pvec[pos]);
					pos++;
				}
				cout << "? " << mul << endl;
				cin >> res;
				
				for(int j = 0; j < tmp.size(); j++){
					if(gcd(tmp[j], res) > 1) fvec.push_back(tmp[j]);
				}
			}
			else{
				llint mul = 1;
				pos = 2*(i-16);
				if(pos < fvec.size()) mul *= get(fvec[pos]);
				if(pos+1 < fvec.size()) mul *= get(fvec[pos+1]);
				cout << "? " << mul << endl;
				cin >> res;
				
				if(pos < fvec.size()) ans *= calc(res, fvec[pos]) + 1;
				if(pos+1 < fvec.size()) ans *= calc(res, fvec[pos+1]) + 1;
			}
		}
		if(ans <= 3) ans = max(ans+7, ans*2);
		else ans *= 2;
		cout << "! " << ans << endl;
	}
	
	return 0;
}
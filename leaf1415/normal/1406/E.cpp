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

llint n;
bool prime[100005];
vector<llint> pvec, pvec2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i = 2; i < 405; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 100005; j+=i) prime[j] = true;
	}
	for(int i = 2; i <= 316; i++) if(!prime[i]) pvec.push_back(i);
	for(int i = 317; i <= n; i++) if(!prime[i]) pvec2.push_back(i);
	
	llint ans = 1, res;
	for(int i = 0; i < pvec.size(); i++){
		llint p = pvec[i];
		if(p > n) continue;
		
		cout << "B " << p << endl;
		cin >> res;
		
		llint mul = 1;
		while(mul * p <= n){
			cout << "A " << mul*p << endl;
			cin >> res;
			if(res == 0) break;
			mul *= p;
		}
		ans *= mul;
	}
	
	llint cnt;
	cout << "A " << 1 << endl;
	cin >> cnt;
	
	for(int i = 0; i < pvec2.size(); i += 100){
		
		for(int j = 0; j < 100 && i+j < pvec2.size(); j++){
			llint p = pvec2[i+j];
			cout << "B " << p << endl;
			cin >> res;
			cnt -= res;
		}
		
		cout << "A " << 1 << endl;
		cin >> res;
		
		if(cnt < res){
			for(int j = 0; j < 100 && i+j < pvec2.size(); j++){
				llint p = pvec2[i+j];
				cout << "A " << p << endl;
				cin >> res;
				if(res == 1){
					ans *= p;
					goto end;
				}
			}
		}
	}
	end:;
	
	cout << "C " << ans << endl;
	
	return 0;
}
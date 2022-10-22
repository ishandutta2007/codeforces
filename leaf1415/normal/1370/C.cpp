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
llint n;
bool prime[100005];
vector<llint> pvec;

bool check(llint x)
{
	for(int i = 0; i < pvec.size(); i++){
		llint p = pvec[i];
		if(p*p > x || p >= x) break;
		if(x % p == 0) return true;
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i = 2; i < 1005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 100005; j+=i) prime[j] = true;
	}
	for(int i = 2; i < 100005; i++){
		if(!prime[i]) pvec.push_back(i);
	}
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		
		if(n == 2){
			cout << "Ashishgup" << endl;
			continue;
		}
		
		if((n&(n-1)) == 0 || (n%2 == 0 && !check(n/2) && n/2%2)){
			cout << "FastestFinger" << endl;
			continue;
		}
		
		cout << "Ashishgup" << endl;
	}
	
	return 0;
}
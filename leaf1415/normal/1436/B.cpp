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

llint T;
llint n;
vector<llint> vec;
bool prime[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i = 2; i < 1005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 100005; j+=i) prime[j] = true;
	}
	for(int i = 2; i < 100005; i++) if(!prime[i]) vec.push_back(i);
	
	cin >> T;
	while(T--){
		cin >> n;
		
		bool flag = false;
		for(int i = 2; i < n; i++){
			if(n % i == 0) flag = true;
		}
		
		llint p = lower_bound(vec.begin(), vec.end(), n) - vec.begin();
		while(!prime[vec[p]-(n-1)]) p++;
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j) cout << vec[p]-(n-1) << " ";
				else cout << 1 << " ";
			}
			cout << endl;
		}
	}
	
	return 0;
}
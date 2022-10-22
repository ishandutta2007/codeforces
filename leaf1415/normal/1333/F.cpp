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

int n;
int a[500005];
int prime[500005];
bool used[500005];
vector<int> pvec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i = 2; i < 1005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 500005; j+=i){
			if(prime[j] == 0) prime[j] = i;
		}
	}
	
	int cnt = 1;
	used[1] = true;
	for(int i = 2; i <= n; i++){
		if(!prime[i]){
			pvec.push_back(i);
			used[i] = true;
			cnt++;
		}
	}
	a[1] = cnt;
	
	for(int i = 2; i <= n; i++){
		if(prime[i] == 0) prime[i] = n+1;
	}
	
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < pvec.size(); j++){
			int p = pvec[j];
			if(p > prime[i] || p > i || p > n/i) break;
			//cout << i << " " << p << endl;
			if(!used[p*i]) cnt++;
			used[p*i] = true;
		}
		a[i] = cnt;
	}
	
	//for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
	
	for(int i = 2; i <= n; i++){
		int p = lower_bound(a+1, a+n+1, i) - a;
		cout << p << " ";
	}
	cout << endl;
	
	return 0;
}
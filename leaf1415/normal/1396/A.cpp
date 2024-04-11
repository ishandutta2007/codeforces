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
llint a[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	if(n == 1){
		cout << 1 << " " << 1 << endl;
		cout << 0 << endl;
		cout << 1 << " " << 1 << endl;
		cout << 0 << endl;
		cout << 1 << " " << 1 << endl;
		cout << -a[1] << endl;
		return 0;
	}
	
	cout << 1 << " " << n << endl;
	for(int i = 1; i <= n; i++){
		cout << (n-1-a[i])*n << " ";
		a[i] += (n-1-a[i])*n;
	}
	cout << endl;
	
	cout << 1 << " " << n-1 << endl;
	for(int i = 1; i <= n-1; i++){
		cout << -a[i] << " ";
	}
	cout << endl;
	
	cout << n << " " << n << endl;
	cout << -a[n] << endl;
	
	return 0;
}
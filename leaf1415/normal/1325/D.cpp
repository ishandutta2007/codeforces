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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)

using namespace std;

llint u, v;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> u >> v;
	if(u == 0 && v == 0){
		cout << 0 << endl;
		return 0;
	}
	if(u == v){
		cout << 1 << endl;
		cout << u << endl;
		return 0;
	}
	if(u > v || u%2 != v%2){
		cout << -1 << endl;
		return 0;
	}
	
	llint z = (v-u)/2, a = 0, b = 0;
	rep(i, 0, 62){
		if(u&(1LL<<i)) a |= 1LL<<i;
		else{
			if(z&(1LL<<i)) a |= 1LL<<i, b |= 1LL<<i;
		}
	}
	if(a+b == v && a^b == u){
		cout << 2 << endl;
		cout << a << " " << b << endl;
		return 0;
	}
	cout << 3 << endl;
	cout << z << " " << z << " " << u << endl;
	
	return 0;
}
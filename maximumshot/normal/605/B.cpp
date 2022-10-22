#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
  
using namespace std;
  
#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 
  
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
  
const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = acos(-1.0);

bool solve() {
  
	int n, m;

	cin >> n >> m;

	vec< tuple< int, int, int > > a;
	// {w, id}

	for(int w, t, i = 0;i < m;i++) {
		cin >> w >> t;
		a.push_back(mt(w, t ^ 1, i));
	}

	sort(ALL(a));

	int mx = 1;
	
	vec< pair< int, int > > can, ans(m);
	int was = 0;

	for(auto it : a) {
		int i, ty;
		tie(ignore, ty, i) = it;
		if(ty ^ 1) {
			ans[i] = mp(1, ++mx);
			for(int j = 2;j < mx && was < 200000;j++, was++) 
				can.push_back(mp(j, mx));
		}else {
			if(can.empty()) {
				cout << -1 << '\n';
				return true;
			}else {
				ans[i] = can.back();
				can.pop_back();
			}
		}
	}

	for(int i = 0;i < m;i++) cout << ans[i].first << ' ' << ans[i].second << '\n'; 

	return true;
}
  
int main() {
      
	//while(solve());
    solve();    
  
    return 0;
}
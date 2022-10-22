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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size()-1; (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll T;
ll x, y;
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> x >> y;
		cin >> s;
		
		if(x < 0){
			x *= -1;
			for(auto &c : s){
				if(c == 'L') c = 'R';
				else if(c == 'R') c = 'L';
			}
		}
		if(y < 0){
			y *= -1;
			for(auto &c : s){
				if(c == 'U') c = 'D';
				else if(c == 'D') c = 'U';
			}
		}
		
		for(auto c : s) {
			if(c == 'R') x--;
			if(c == 'U') y--;
		}
		if(x <= 0 && y <= 0) outl("YES");
		else outl("NO");
	}
	
	return 0;
}
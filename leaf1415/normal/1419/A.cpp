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
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		cin >> s;
		
		bool odd = false, even = false;
		for(int i = 0; i < s.size(); i++){
			if(i%2 == 0 && s[i]%2) odd = true;
			if(i%2 && s[i]%2 == 0) even = true;
		}
		if(n%2){
			if(odd) cout << 1 << endl;
			else cout << 2 << endl;
		}
		else{
			if(even) cout << 2 << endl;
			else cout << 1 << endl;
		}
	}
	
	return 0;
}
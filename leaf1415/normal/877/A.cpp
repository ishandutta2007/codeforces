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
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

string s;

ll calc(string t)
{
	ll ret = 0;
	rep(i, 0, (int)s.size()-1){
		if(i+(int)t.size()-1 >= s.size()) break;
		if(s.substr(i, t.size()) == t) ret++;
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	
	ll ans = 0;
	ans += calc("Danil");
	ans += calc("Olya");
	ans += calc("Slava");
	ans += calc("Ann");
	ans += calc("Nikita");
	
	if(ans == 1) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}
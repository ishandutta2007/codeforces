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


ll n;
string s, t[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	cin >> n;
	rep(i, 1, n) cin >> t[i];
	
	rep(i, 1, n) if(s == t[i]){
		cout << "YES" << endl;
		return 0;
	}
	
	bool flag = false, flag2 = false;
	rep(i, 1, n){
		if(t[i][0] == s[1]) flag = true;
		if(t[i][1] == s[0]) flag2 = true;
	}
	if(flag && flag2) cout << "YES"<< endl;
	else cout << "NO" << endl;
	
	return 0;
}
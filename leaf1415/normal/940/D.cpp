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
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
ll a[100005];
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	rep(i, 1, n) cin >> a[i];
	cin >> s;
	s = "#" + s;

	ll l = -1e9, L = 1e9, r = -1e9, R = 1e9;

	rep(i, 5, n){
		if(s.substr(i-4, 4) == "1111" && s[i] == '0'){
			rep(j, 0, 4) chmin(R, a[i-j]-1);
		}
		if(s.substr(i-4, 4) == "0000" && s[i] == '1'){
			rep(j, 0, 4) chmax(l, a[i-j]+1);
		}
	}
	cout << l << " " << R << endl;

	return 0;
}
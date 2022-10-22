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
typedef pair<ll, string> Q;

ll n;
Q q[105];

bool check(int i, int j)
{
	string s = q[i].second, t = q[j].second;
	for(int k = 0; k+s.size()-1 < t.size(); k++){
		if(t.substr(k, s.size()) == s) return true;
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	rep(i, 1, n) cin >> q[i].second, q[i].first = q[i].second.size();
	sort(q+1, q+n+1);

	rep(i, 1, n-1){
		if(!check(i, i+1)){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	rep(i, 1, n) cout << q[i].second << endl;

	return 0;
}
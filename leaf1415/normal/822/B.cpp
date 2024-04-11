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

ll n, m;
string s, t;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> s >> t;
	
	vector<ll> vec;
	rep(i, 1, s.size()) vec.push_back(i);
	rep(i, 0, (int)t.size()-(int)s.size()){
		vector<ll> tmp;
		rep(j, 0, (int)s.size()-1){
			if(s[j] != t[i+j]) tmp.push_back(j+1);
		}
		if(vec.size() > tmp.size()) vec = tmp;
	}
	cout << vec.size() << endl;
	for(auto x : vec) cout << x << " "; cout << endl;
	
	return 0;
}
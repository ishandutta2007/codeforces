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
typedef pair<llint, llint> P;

llint n;
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	if(n == 1){
		cout << "Yes" << endl;
		return 0;
	}
	
	llint cnt[26] = {};
	rep(i, 0, n-1){
		cnt[s[i]-'a']++;
	}
	rep(i, 0, 25){
		if(cnt[i] >= 2){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	
	return 0;
}
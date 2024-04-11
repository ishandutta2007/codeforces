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

string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	reverse(all(s));

	ll cnt = 0;
	for(auto c : s){
		if(c == '0') cnt++;
		else{
			if(cnt >= 6){
				cout << "yes" << endl;
				return 0;
			}
		}
	}
	cout << "no" << endl;

	return 0;
}
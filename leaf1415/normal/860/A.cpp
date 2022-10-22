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

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	ll cnt = 0; bool flag = false;
	string ans;
	rep(i, 0, (int)s.size()-1){
		if(s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o'){
			flag = false;
			cnt = 0;
			ans += s[i];
			continue;
		}
		cnt++;
		if(cnt >= 2 && s[i] != s[i-1]) flag = true;
		if(cnt >= 3 && flag){
			ans += " ";
			flag = false;
			cnt = 1;
		}
		ans += s[i];
	}
	cout << ans << endl;
	
	return 0;
}
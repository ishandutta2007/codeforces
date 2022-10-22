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

llint k;
string s = "codeforces";
llint cnt[10];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> k;
	for(int i = 0; ; i++){
		cnt[i%10]++;
		llint mul = 1;
		for(int j = 0; j < 10; j++){
			mul *= cnt[j];
		}
		if(mul >= k) break;
	}
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < cnt[i]; j++) cout << s[i];
	}
	cout << endl;
	
	return 0;
}
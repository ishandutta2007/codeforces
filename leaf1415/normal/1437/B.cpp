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

llint T;
llint n;
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		cin >> s;
		
		llint cnt0 = 0, cnt1 = 0;
		for(int i = 1; i < s.size(); i++){
			if(s[i-1] == '0' && s[i] == '0') cnt0++;
			if(s[i-1] == '1' && s[i] == '1') cnt1++;
		}
		cout << max(cnt0, cnt1) << endl;
	}
	
	return 0;
}
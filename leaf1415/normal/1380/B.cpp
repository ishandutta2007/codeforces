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

llint T;
string s, S = "RSP";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> s;
		llint cnt[3] = {};
		for(int i = 0; i < s.size(); i++){
			if(s[i] == 'R') cnt[0]++;
			if(s[i] == 'S') cnt[1]++;
			if(s[i] == 'P') cnt[2]++;
		}
		P p = P(-1, -1);
		for(int i = 0; i < 3; i++) p = max(p, P(cnt[i], i));
		
		for(int i = 0; i < s.size(); i++) cout << S[(p.second+2)%3];
		cout << endl;
	}
	
	return 0;
}
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
llint n;
string s, t;
vector<llint> ans;

llint flip(char c)
{
	return 1-(c-'0')+'0';
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int z = 0; z < T; z++){
		cin >> n >> s >> t;
		
		ans.clear();
		for(int i = n-1; i >= 0; i--){
			if(t[i] == s[0]){
				ans.push_back(1);
				s[0] = flip(s[0]);
			}
			ans.push_back(i+1);
			reverse(s.begin(), s.begin()+i+1);
			for(int j = 0; j <= i; j++) s[j] = flip(s[j]);
		}
		
		cout << ans.size() << " ";
		for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	}
	
	return 0;
}
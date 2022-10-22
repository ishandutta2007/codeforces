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
llint n, m;
string s;
llint b[55], ans[55];
llint cnt[26];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> s;
		n = s.size();
		s = "#" + s;
		
		cin >> m;
		for(int i = 1; i <= m; i++) cin >> b[i];
		
		for(int i = 0; i < 26; i++) cnt[i] = 0;
		for(int i = 1; i <= n; i++) cnt[s[i]-'a']++;
		
		for(int i = 1; i <= m; i++) ans[i] = -1;
		llint pos = 25;
		while(1){
			vector<llint> vec;
			for(int i = 1; i <= m; i++){
				if(b[i] == 0 && ans[i] == -1) vec.push_back(i);
			}
			if(vec.size() == 0) break;
			
			llint x = vec.size();
			while(cnt[pos] < x) pos--;
			
			for(int i = 0; i < vec.size(); i++){
				llint p = vec[i];
				ans[p] = pos;
				for(int j = 1; j <= m; j++) b[j] -= abs(j-p);
			}
			pos--;
		}
		for(int i = 1; i <= m; i++) cout << (char)(ans[i]+'a');
		cout << endl;
	}
	
	return 0;
}
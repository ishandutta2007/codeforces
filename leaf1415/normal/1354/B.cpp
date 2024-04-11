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
string s;
llint lpos[200005][3], rpos[200005][3];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> s;
		llint n = s.size();
		for(int i = 0; i < s.size(); i++) s[i]--;
		s = "#" + s;
		
		for(int i = 0; i <= n; i++){
			for(int j = 0; j < 3; j++){
				lpos[i][j] = -inf;
				rpos[i][j] = inf;
			}
		}
		for(int i = 2; i <= n; i++){
			for(int j = 0; j < 3; j++){
				lpos[i][j] = lpos[i-1][j];
			}
			lpos[i][s[i-1]-'0'] = i-1;
		}
		for(int i = n-1; i >= 1; i--){
			for(int j = 0; j < 3; j++){
				rpos[i][j] = rpos[i+1][j];
			}
			rpos[i][s[i+1]-'0'] = i+1;
		}
		
		/*for(int i = 1; i <= n; i++){
			for(int j = 0; j < 3; j++){
				cout << lpos[i][j] << " ";
			}
			cout << endl;
		}
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < 3; j++){
				cout << rpos[i][j] << " ";
			}
			cout << endl;
		}*/
		
		llint ans = inf;
		for(int i = 2; i < n; i++){
			llint x = s[i]-'0', y = (x+1)%3, z = (x+2)%3;
			
			ans = min(ans, rpos[i][z] - lpos[i][y] + 1);
			ans = min(ans, rpos[i][y] - lpos[i][z] + 1);
			//cout << ans << endl;
		}
		if(ans > inf/2) ans = 0;
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}
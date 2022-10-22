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
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		cin >> s;
		
		vector<llint> vec; llint cnt = 0;
		for(int i = 0; i < n; i++){
			if(i == 0 || s[i-1] == s[i]) cnt++;
			else{
				vec.push_back(cnt);
				cnt = 1;
			}
		}
		vec.push_back(cnt);
		
		queue<int> Q;
		for(int i = 0; i < vec.size(); i++){
			if(vec[i] >= 2) Q.push(i);
		}
		
		llint ans = 0, pos = 0;
		while(1){
			
			while(Q.size() && (Q.front() < pos || vec[Q.front()] <= 1)) Q.pop();
			if(Q.size() == 0){
				if(pos >= vec.size()) break;
				pos++;
			}
			else{
				llint x = Q.front();
				vec[x]--;
			}
			
			ans++;
			
			while(pos < vec.size() && vec[pos] == 0) pos++;
			if(pos == vec.size()) break;
			pos++;
			
		}
		cout << ans << endl;
	}
	
	return 0;
}
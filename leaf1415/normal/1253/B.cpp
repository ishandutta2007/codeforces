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

llint n;
llint a[100005];
vector<llint> ans;
set<llint> inS, outS;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint cnt = 0;
	for(int i = 1; i <= n; i++){
		cnt++;
		if(a[i] > 0){
			if(outS.count(a[i])){
				cout <<-1 << endl;
				return 0;
			}
			inS.insert(a[i]);
			outS.insert(a[i]);
		}
		else{
			a[i] *= -1;
			if(inS.count(a[i]) == 0){
				cout << -1 << endl;
				return 0;
			}
			inS.erase(a[i]);
			if(inS.size() == 0){
				ans.push_back(cnt);
				cnt = 0;
				inS.clear();
				outS.clear();
			}
		}
	}
	if(inS.size() > 0){
		cout << -1 << endl;
		return 0;
	}
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}
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
vector<llint> vec[4];
llint r[100005];

vector<P> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		vec[a[i]].push_back(i);
	}
	if(vec[1].size() + vec[3].size() > n){
		cout << -1 << endl;
		return 0;
	}
	
	llint id = 1;
	for(int i = 0; i < vec[3].size(); i++){
		r[vec[3][i]] = id++;
		ans.push_back(P(r[vec[3][i]], vec[3][i]));
	}
	for(int i = 0; i < vec[1].size(); i++){
		r[vec[1][i]] = id++;
		ans.push_back(P(r[vec[1][i]], vec[1][i]));
	}
	
	vector<llint> tmp;
	for(int i = 0; i < vec[1].size(); i++) tmp.push_back(vec[1][i]);
	for(int i = 0; i < vec[2].size(); i++) tmp.push_back(vec[2][i]);
	for(int i = 0; i < vec[3].size(); i++) tmp.push_back(vec[3][i]);
	sort(tmp.rbegin(), tmp.rend());
	
	vector<llint> rem, rem2, rem3;
	for(int i = 0; i < tmp.size(); i++){
		llint col = tmp[i];
		if(a[col] == 1) rem.push_back(col);
		if(a[col] == 2){
			if(rem.size() == 0){
				cout << -1 << endl;
				return 0;
			}
			llint c = rem.back();
			ans.push_back(P(r[c], col));
			rem.pop_back();
			rem2.push_back(col);
		}
		if(a[col] == 3){
			llint c;
			if(rem3.size() == 0){
				if(rem2.size() == 0){
					if(rem.size() == 0){
						cout << -1 << endl;
						return 0;
					}
					c = rem.back();
					rem.pop_back();
				}
				else{
					c = rem2.back();
					rem2.pop_back();
				}
			}
			else{
				c = rem3.back();
				rem3.pop_back();
			}
			ans.push_back(P(r[col], c));
			rem3.push_back(col);
		}
	}
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << endl;
	
	return 0;
}
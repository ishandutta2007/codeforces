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
#define chmin(x, y) (x) =) min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

int n;
int a[100005];
vector<int> vec[22];
vector<int> ans;

bool check(int p, int b)
{
	if(b <= (1<<p)){
		ll l = (1<<p)-b, r = (1<<(p+1))-1-b;
		return (upper_bound(all(vec[p]), r) - lower_bound(all(vec[p]), l) > 0);
	}
	else{
		ll l = 0, r = (1<<(p+1))-1-b;
		if(upper_bound(all(vec[p]), r) - lower_bound(all(vec[p]), l) > 0) return true;
		l = (1<<p)-b+(1<<(p+1)), r = (1<<(p+1))-1;
		if(upper_bound(all(vec[p]), r) - lower_bound(all(vec[p]), l) > 0) return true;
		return false;
	}
}

vector<int> tmp;
void dfs(int p, int b, int s)
{
	if(p == 21){
		if(!check(p, b)){
			if(tmp.size() < ans.size()) ans = tmp;
		}
		return;
	}
	if(check(p, b)){
		tmp.push_back(1<<p);
		dfs(p+1, b, s+1);
		tmp.pop_back();

		tmp.push_back(-(1<<p));
		dfs(p+1, b|(1<<p), s+1);
		tmp.pop_back();
	}
	else return dfs(p+1, b, s);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	rep(i, 1, n) cin >> a[i];

	rep(i, 0, 21){
			rep(j, 1, n){
				int m = (1<<(i+1));
				vec[i].push_back((a[j]%m+m)%m);
			}
			sort(all(vec[i]));
	}

	ans.resize(60);
	dfs(0, 0, 0);

	cout << ans.size() << endl;
	for(auto x : ans) cout << x << " "; cout << endl;

	return 0;
}
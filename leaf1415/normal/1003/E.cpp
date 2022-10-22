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

llint n, d, k;
vector<P> ans;

llint id;
bool dfs(int dep, int par)
{
	if(ans.size() >= n-1) return true;
	int v = id++;
	ans.push_back(P(par, v));
	
	if(dep == 0) return (ans.size() >= n-1);
	rep(i, 1, k-1){
		if(dfs(dep-1, v)) return true;
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> d >> k;
	if(n == 1){
		cout << "NO" << endl;
		return 0;
	}
	if(k == 1){
		if(n == 2 && d == 1){
			cout << "YES" << endl;
			cout << 1 << " " << 2 << endl;
		}
		else cout << "NO" << endl;
		return 0;
	}
	d++;
	
	id = d+1;
	rep(i, 1, d-1) ans.push_back(P(i, i+1));
	rep(i, 2, d-1){
		if(ans.size() >= n-1) break;
		rep(j, 1, k-2){
			if(ans.size() >= n-1) break;
			dfs(min(abs(1-i), abs(d-i))-1, i);
		}
	}
	
	if(ans.size() == n-1){
		cout << "YES" << endl;
		for(auto p : ans) cout << p.first << " " << p.second << "\n";
		flush(cout);
	}
	else cout << "NO" << endl;
	
	return 0;
}
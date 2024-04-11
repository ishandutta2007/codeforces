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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
typedef pair<P, llint> T;

ll n;
ll l[200005], r[200005];
vector<ll> lvec[1200005], rvec[1200005];
bool used[200005];
vector<ll> comp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n){
		cin >> l[i] >> r[i];
		comp.push_back(l[i]);
		comp.push_back(r[i]);
		comp.push_back(l[i]+1);
		comp.push_back(r[i]+1);
		comp.push_back(l[i]-1);
		comp.push_back(r[i]-1);
	}
	sort(all(comp));
	comp.erase(unique(all(comp)), comp.end());
	rep(i, 1, n) l[i] = lower_bound(all(comp), l[i]) - comp.begin();
	rep(i, 1, n) r[i] = lower_bound(all(comp), r[i]) - comp.begin();
	
	rep(i, 1, n){
		lvec[l[i]].push_back(i);
		rvec[r[i]].push_back(i);
	}
	
	ll m = comp.size(); set<ll> S;
	rep(i, 0, m-1){
		for(auto x : lvec[i]) S.insert(x);
		if(S.size() == 1) used[*S.begin()] = true;
		for(auto x : rvec[i]) S.erase(x);
	}
	
	rep(i, 1, n){
		if(!used[i]){
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	
	return 0;
}
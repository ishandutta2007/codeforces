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
#define mod 998244353

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;
typedef pair<P, llint> T;

llint n, k;
vector<llint> vec[3005];
llint num[3005], sum[3005];
stack<vector<llint> > stk;

llint ans = -inf;
void calc(llint l, llint r)
{
	if(l == r){
		llint sum = 0;
		rep(i, 0, vec[l].size()){
			chmax(ans, sum + stk.top()[k-i]);
			if(i < vec[l].size()) sum += vec[l][i];
		}
		return;
	}
	
	llint m = (l+r)/2;
	vector<llint> tmp = stk.top();
	rep(i, l, m){
		for(int j = k; j >= 0; j--){
			if(j-num[i] >= 0) chmax(tmp[j], tmp[j-num[i]]+sum[i]);
		}
	}
	stk.push(tmp);
	calc(m+1, r);
	stk.pop();
	
	tmp = stk.top();
	rep(i, m+1, r){
		for(int j = k; j >= 0; j--){
			if(j-num[i] >= 0) chmax(tmp[j], tmp[j-num[i]]+sum[i]);
		}
	}
	stk.push(tmp);
	calc(l, m);
	stk.pop();
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	llint t, x;
	rep(i, 1, n){
		cin >> t;
		rep(j, 1, t){
			cin >> x;
			vec[i].push_back(x);
		}
		if(t > k) vec[i].resize(k);
		num[i] = vec[i].size();
		for(auto x: vec[i]) sum[i] += x;
	}
	
	stk.push(vector<llint>(k+1));
	rep(i, 1, k) stk.top()[i] = -inf;
	calc(1, n);
	cout << ans << endl;
	
	return 0;
}
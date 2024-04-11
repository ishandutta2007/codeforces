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

int T;
int n, m;
int w[1005], h[1005];
vector<int> wpos, wneg, hpos, hneg;
bool used[1005];

bool calc(int w[], vector<int> &pos, vector<int> &neg)
{
	pos.clear(), neg.clear();
	int sum = 0;
	rep(i, 1, n) sum += w[i];
	if(sum % 2) return false;
	sum /= 2;
	
	vector<int> dp(sum+1);
	rep(i, 1, sum) dp[i] = -1;
	
	rep(i, 0, n-1){
		for(int j = sum; j >= 0; j--){
			if(dp[j] < 0) continue;
			if(j+w[i+1] <= sum && dp[j+w[i+1]] < 0) dp[j+w[i+1]] = i+1;
		}
	}
	if(dp[sum] < 0) return false;
	
	rep(i, 1, n) used[i] = false;
	
	int j = sum;
	while(j > 0){
		used[dp[j]] = true;
		j -= w[dp[j]];
	}
	rep(i, 1, n){
		if(used[i]) pos.push_back(w[i]);
		else neg.push_back(w[i]);
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> w[i];
		cin >> m;
		rep(i, 1, m) cin >> h[i];
		
		if(n != m){
			cout << "No" << endl;
			continue;
		}
		
		if(!calc(w, wpos, wneg) || !calc(h, hpos, hneg)){
			cout << "No" << endl;
			continue;
		}
		cout << "Yes" << endl;
		
		if(wpos.size() > wneg.size()) swap(wpos, wneg);
		if(hpos.size() < hneg.size()) swap(hpos, hneg);
		
		sort(wpos.rbegin(), wpos.rend());
		sort(wneg.rbegin(), wneg.rend());
		sort(all(hpos));
		sort(all(hneg));
		
		for(auto x:wneg) wpos.push_back(-x);
		for(auto x:hneg) hpos.push_back(-x);
		
		llint x = 0, y = 0;
		rep(i, 0, 2*n-1){
			cout << x << " " << y << "\n";
			if(i % 2 == 0) x += wpos[i/2];
			else y += hpos[i/2];
		}
	}
	flush(cout);
	
	return 0;
}
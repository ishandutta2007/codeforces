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
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint s[100005], e[100005];
bool can[100005][2][2];
bool dp[100005][2];
llint g[205];

bool calc(llint s, llint e)
{
	if(s == e) return false;
	if(s > e) return true;
	if(e % 2) return s % 2 == 0;
	
	if(s <= e/4) return calc(s, e/4);
	if(s <= e/2) return true;
	return s%2 != e%2;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s[i] >> e[i];
	
	/*llint E = 10;
	for(int i = E-1; i >= 1; i--){
		set<llint> S;
		S.insert(g[i+1]);
		if(2*i <= E) S.insert(g[2*i]);
		while(S.count(g[i])) g[i]++;
	}
	for(int i = 1; i <= E; i++) cout << i << " : " << g[i] << endl;*/
	
	for(int i = 1; i <= n; i++){
		if(calc(s[i], e[i])) can[i][0][1] = true;
		else can[i][1][1] = true;
		
		if(calc(s[i], min(e[i]/2, e[i]-1))) can[i][0][0] = true;
		else can[i][1][0] = true;
	}
	
	dp[0][0] = true;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2; j++){
			if(!dp[i][j]) continue;
			for(int k = 0; k < 2; k++){
				if(can[i+1][j][k]) dp[i+1][k] = true;
			}
		}
	}
	
	/*for(int i = 0; i <= n; i++){
		for(int j = 0; j < 2; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	if(dp[n][1]) cout << 1 << " ";
	else cout << 0 << " ";
	
	if(dp[n][0]) cout << 1 << " ";
	else cout << 0 << " ";
	
	return 0;
}
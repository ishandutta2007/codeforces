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
#define inf 1e9
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 998244353

using namespace std;
typedef pair<llint, llint> P;

struct CHT{
	deque<P> deq;
	
	void init(){
		deq.clear();
	}
	//assume a1 >= a2 >= a3
	bool check(P p1, P p2, P p3)
	{
		llint a1 = p1.first, b1 = p1.second;
		llint a2 = p2.first, b2 = p2.second;
		llint a3 = p3.first, b3 = p3.second;
		return (a2-a1)*(b3-b2) >= (b2-b1)*(a3-a2);
	}
	llint calc(P p, llint x){
		return p.first * x + p.second;
	}
	
	void add(llint a, llint b){ //slopes must be monotone decreasing
		P p = make_pair(a, b);
		while(deq.size() >= 2 && check(deq[(int)deq.size()-2], deq[(int)deq.size()-1], p)) deq.pop_back();
		deq.push_back(p);
	}
	llint query(llint x){ //queries must be monotone increasing
		if(deq.size() == 0) return -inf;
		while(deq.size() >= 2 && calc(deq[0], x) >= calc(deq[1], x)) deq.pop_front();
		return calc(deq.front(), x);
	}
};


llint n;
llint a[85], s[85];
llint dp[85][4005][85];
vector<llint> vec;
CHT cht[4005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint cnt = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 1){
			vec.push_back(cnt);
			cnt = 0;
		}
		else cnt++;
	}
	vec.push_back(cnt);
	
	llint m = (int)vec.size(), z = n-(m-1);
	for(int i = 0; i < vec.size(); i++) s[i+1] = s[i] + vec[i];
	
	//for(int i = 1; i <= m; i++) cout << s[i] << " "; cout << endl;
	
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n*(n-1)/2; j++){
			for(int k = 0; k <= z; k++){
				dp[i][j][k] = -inf;
			}
		}
	}
	dp[0][0][0] = 0;
	
	for(int i = 1; i <= m; i++){
		for(int j = 0; j <= n*(n-1)/2; j++) cht[j].init();
		
		for(int k = 0; k <= z; k++){
			for(int j = 0; j <= n*(n-1)/2; j++){
				if(j-abs(k-s[i]) >= 0){
					cht[j-abs(k-s[i])].add(-k, -dp[i-1][j-abs(k-s[i])][k]+k*k);
					dp[i][j][k] = -cht[j-abs(k-s[i])].query(k);
				}
			}
		}
	}
	/*for(int i = 1; i <= m; i++){
		for(int j = 0; j <= n*(n-1)/2; j++){
			for(int k = 0; k <= z; k++){
				cout << i << " " << j << " " << k << " " <<dp[i][j][k] << endl;
			}
		}
	}*/
	
	llint ans = 0;
	for(int j = 0; j <= n*(n-1)/2; j++){
		ans = max(ans, dp[m][j][z]);
		cout << ans << " ";
	}
	cout << endl;
	
	return 0;
}
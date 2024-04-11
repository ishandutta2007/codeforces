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

struct SWAG{
	llint size;
	stack<P> head, tail;
	SWAG(){init();}
	
	llint getElement(){ //e
		return -inf;
	}
	llint ope(llint x, llint y){  //(x * y)
		return max(x, y);
	}
	void init(){
		size = 0;
		while(head.size()) head.pop();
		while(tail.size()) tail.pop();
	}
	void push(llint x){
		size++;
		if(tail.size() == 0){
			tail.push(P(x, x));
			return;
		}
		tail.push(P(x, ope(tail.top().second, x)));
	}
	void pop(){
		if(size == 0) return;
		if(head.size() == 0){
			llint sum = getElement();
			while(tail.size()){
				llint x = tail.top().first;
				sum = ope(x, sum);
				head.push(P(x, ope(x, sum)));
				tail.pop();
			}
		}
		head.pop();
		size--;
	}
	llint query(){
		llint ret = getElement();
		if(head.size()) ret = ope(ret, head.top().second);
		if(tail.size()) ret = ope(ret, tail.top().second);
		return ret;
	}
};

llint n, k, x;
llint a[200005];
llint dp[5005][5005];
SWAG swag;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> x;
	rep(i, 1, n) cin >> a[i];
	
	rep(i, 0, x){
		rep(j, 0, n){
			dp[i][j] = -inf;
		}
	}
	dp[0][0] = 0;
	
	rep(i, 1, x){
		swag.init();
		rep(j, 1, n){
			swag.push(dp[i-1][j-1]);
			dp[i][j] = swag.query() + a[j];
			if(j >= k) swag.pop();
		}
	}
	
	llint ans = -1;
	rep(i, n-k+1, n) chmax(ans, dp[x][i]);
	cout << ans << endl;
	
	return 0;
}
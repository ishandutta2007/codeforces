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


struct DoubleQueueMedian{
	set<llint> leftQ, rightQ;
	llint lsum, rsum, lnum, rnum;
	llint light;
	
	DoubleQueueMedian(){
		init();
	}
	void init(){
		leftQ.clear(), rightQ.clear();
		lsum = rsum = lnum = rnum = 0;
		light = 0;
	}
	void adjust(){
		while(rightQ.size() < light){
			rightQ.insert(*leftQ.rbegin());
			rsum += *leftQ.rbegin();
			lsum -= *leftQ.rbegin();
			
			auto it = leftQ.end(); it--;
			leftQ.erase(it);
		}
		while(rightQ.size() > light){
			leftQ.insert(*rightQ.begin());
			lsum += *rightQ.begin();
			rsum -= *rightQ.begin();
			rightQ.erase(rightQ.begin());
		}
	}
	void add(llint x, llint y)
	{
		light += y;
		if(leftQ.size() && *leftQ.rbegin() >= x){
			leftQ.insert(x);
			lsum += x;
		}
		else{
			rightQ.insert(x);
			rsum += x;
		}
		adjust();
	}
	void erase(llint x, llint y)
	{
		light -= y;
		if(leftQ.size() && *leftQ.rbegin() >= x){
			leftQ.erase(x);
			lsum -= x;
		}
		else{
			rightQ.erase(x);
			rsum -= x;
		}
		adjust();
	}
};

llint n;
llint t[200005], d[200005];
set<llint> S;
DoubleQueueMedian dq;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	llint sum = 0;
	for(int i = 1; i <= n; i++){
		cin >> t[i] >> d[i];
		if(t[i] == 1){
			if(d[i] >= 0) S.insert(d[i]);
			else S.erase(-d[i]);
		}
		sum += d[i];
		if(d[i] >= 0) dq.add(d[i], t[i]);
		else dq.erase(-d[i], t[i]);
		
		llint ans = sum + dq.rsum;
		if(dq.light > 0 && *S.begin() == *dq.rightQ.begin()){
			ans -= *dq.rightQ.begin();
			if(dq.leftQ.size()) ans += *dq.leftQ.rbegin();
		}
		//cout << sum << " " << dq.rsum << endl;
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}
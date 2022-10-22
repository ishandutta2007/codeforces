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

struct BIT{
	int size;
	vector<llint> bit;
	BIT(){size = 0;}
	BIT(int s){
		size = s;
		bit.resize(size+1);
		init();
	}
	void init(){
		for(int i = 1; i <= size; i++) bit[i] = 0;
	}
	llint query(int i){
		llint ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&(-i);
		}
		return ret;
	}
	void add(int i, llint x){
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};


llint n, p;
llint a[100005];
llint cnt[300005], *pt;
vector<llint> ans;
BIT bit(100005);

bool check(llint x)
{
	for(int i = 1; i <= n; i++){
		if(a[i] > x+i-1) return false;
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> p;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	
	pt = cnt+150005;
	
	llint ub = a[n], lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	
	llint x = ub;//a[n]-(n-1);
	for(int i = n; i >= 1; i--){
		llint num = min(n, x+(n-1)-a[i]+1) - (n-i);
		bit.add(i, num), bit.add(i+1, -num);
		pt[num]++;
		//cout << i << " " << num << endl;
	}
	if(pt[p] == 0) ans.push_back(x);
	
	//for(int i = 1; i <= n; i++) cout << bit.query(i) << " "; cout << endl;
	
	llint pos = 0;
	while(pos < n && bit.query(pos+1) == pos+1){
		pos++;
		pt[pos]--;
	}
	
	for(int i = 1; i <= n && pos < p; i++){
		bit.add(pos+1, 1);
		pt--;
		while(pos < n && bit.query(pos+1) == pos+1){
			pos++;
			pt[pos]--;
		}
		if(pos < p && pt[p] == 0) ans.push_back(x+i);
		else break;
	}
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}
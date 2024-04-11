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
		if(i == 0) return;
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};


llint n, Q;
llint a[100005], cnt[100005];
BIT bit(100005);

llint get(llint x)
{
	return bit.query(100000) - bit.query(x-1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cnt[a[i]]++;
	for(int i = 1; i <= 100000; i++) bit.add(cnt[i], 1);
	
	cin >> Q;
	char c; llint x;
	for(int q = 0; q < Q; q++){
		cin >> c >> x;
		if(c == '+'){
			bit.add(cnt[x], -1);
			cnt[x]++;
			bit.add(cnt[x], 1);
		}
		else{
			bit.add(cnt[x], -1);
			cnt[x]--;
			bit.add(cnt[x], 1);
		}
		
		if(get(8) >= 1 || (get(6) >= 1 && get(2) >= 2) || (get(4) >= 1 && get(2) >= 3) || get(4) >= 2) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	flush(cout);
	
	return 0;
}
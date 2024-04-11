#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <utility>
#define llint long long
#define mod 1000000007

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
			ret %= mod;
			i -= i&(-i);
		}
		return ret;
	}
	void add(int i, llint x){
		while(i <= size){
			bit[i] += x;
			bit[i] %= mod;
			i += i&(-i);
		}
	}
};

llint n;
llint a[500005];
P p[500005];
BIT bit(500005), bit2(500005);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) p[i] = make_pair(a[i], i);
	sort(p+1, p+n+1);
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		llint mul = 0, cnt = (bit2.query(n)-bit2.query(p[i].second));
		//cout << "*" << cnt << endl;
		mul = (cnt*(n+1)%mod + (mod - bit.query(n)) + bit.query(p[i].second)) % mod * p[i].second % mod, mul %= mod;
		//cout << mul << endl;
		mul += bit.query(p[i].second) * (n - p[i].second + 1) % mod, mul %= mod;
		mul += p[i].second % mod * (n-p[i].second+1) % mod, mul %= mod;
		//cout << mul << endl;
		ans += p[i].first * mul % mod, ans %= mod;
		bit.add(p[i].second, p[i].second);
		bit2.add(p[i].second, 1);
	}
	cout << ans << endl;
	
	return 0;
}
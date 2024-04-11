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
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
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

ll n, r, k;
ll a[500005], b[500005];
BIT bit(500005);

bool check(ll x)
{
	ll rem = k;
	
	bit.init();
	rep(i, 1, n) b[i] = a[i];
	
	ll sum = 0;
	rep(i, 1, min(n, 1+r)) sum += b[i];
	
	rep(i, 1, n){
		if(sum < x){
			ll d = x-sum;
			b[min(n, i+r)] += d;
			sum += d, rem -= d;
			if(rem < 0) return false;
		}
		if(i+r+1 <= n) sum += b[i+r+1];
		if(i-r >= 1) sum -= b[i-r];
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> r >> k;
	rep(i, 1, n) cin >> a[i];
	
	ll ub = 1.1e18, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) lb = mid;
		else ub = mid;
	}
	cout << lb << endl;
	
	return 0;
}
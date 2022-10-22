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

struct BIT2D{
	int hsize, wsize;
	vector<vector<llint> > bit;
	BIT2D(){hsize = wsize = 0;}
	BIT2D(int h, int w){
		hsize = h, wsize = w;
		bit.resize(wsize+1);
		rep(i, 1, wsize) bit[i].resize(hsize+1);
		init();
	}
	void init(){
		for(int y = 1; y <= hsize; y++){
			for(int x = 1; x <= wsize; x++){
				bit[x][y] = 0;
			}
		}
	}
	llint query(int x, int y){
		llint ret = 0;
		for(int i = x; i > 0; i -= i&(-i)){
			for(int j = y; j > 0; j -= j&(-j)){
				ret += bit[i][j];
			}
		}
		return ret;
	}
	void add(int x, int y, llint val){
		if(x == 0 || y == 0) return;
		for(int i = x; i <= wsize; i += i&(-i)){
			for(int j = y; j <= hsize; j += j&(-j)){
				bit[i][j] += val;
			}
		}
	}
};

ll n;
ll a[100005];
vector<ll> vec[100005];
BIT bit(100005);

ll getnext(ll i, ll pos)
{
	ll p = upper_bound(all(vec[i]), pos) - vec[i].begin();
	if(p >= vec[i].size()) p = 0;
	return p;
}

ll getnum(ll p, ll np)
{
	//cout << p << " " << np << endl;
	if(p <= np) return bit.query(np) - bit.query(p);
	return bit.query(n) - bit.query(p) + bit.query(np);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i], vec[a[i]].push_back(i), bit.add(i, 1);
	
	ll pos = 0, ans = 0;
	rep(i, 1, 100000){
		if(vec[i].size() == 0) continue;
		ll idx = getnext(i, pos), npos = vec[i][idx];
		ans += getnum(pos, npos), pos = npos;
		
		idx--; if(idx < 0) idx = (int)vec[i].size()-1;
		npos = vec[i][idx];
		ans += getnum(pos, npos), pos = npos;
		
		for(auto x : vec[i]) bit.add(x, -1);
	}
	cout << ans << endl;
	
	return 0;
}
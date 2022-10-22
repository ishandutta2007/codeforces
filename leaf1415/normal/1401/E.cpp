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
typedef pair<llint, P> E;

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

llint n, m;
llint L = 1000000;
vector<P> lvec, rvec, dvec, uvec;
BIT bit(1000005);

llint calc(vector<P> &xvec, vector<P> &yvec)
{
	vector<E> vec;
	for(int i = 0; i < xvec.size(); i++) vec.push_back(E(xvec[i].first, P(0, xvec[i].second)));
	for(int i = 0; i < yvec.size(); i++) vec.push_back(E(yvec[i].second, P(1, yvec[i].first)));
	sort(vec.rbegin(), vec.rend());
	
	llint ret = 0;
	bit.init();
	for(int i = 0; i < vec.size(); i++){
		llint t = vec[i].second.first, h = vec[i].second.second;
		if(t == 0) ret += bit.query(h);
		else bit.add(h, 1);
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	llint ans = 1;
	llint l, r, y;
	for(int i = 1; i <= n; i++){
		cin >> y >> l >> r;
		if(r < L) lvec.push_back(P(y, r));
		else rvec.push_back(P(y, L - l));
		if(l == 0 && r == L) ans++;
	}
	llint x, d, u;
	for(int i = 1; i <= m; i++){
		cin >> x >> d >> u;
		if(u < L) dvec.push_back(P(x, u));
		else uvec.push_back(P(x, L - d));
		if(d == 0 && u == L) ans++;
	}
	
	ans += calc(dvec, lvec);
	for(int i = 0; i < dvec.size(); i++) dvec[i].first = L - dvec[i].first;
	ans += calc(dvec, rvec);
	
	for(int i = 0; i < lvec.size(); i++) lvec[i].first = L - lvec[i].first;
	for(int i = 0; i < rvec.size(); i++) rvec[i].first = L - rvec[i].first;
	
	
	ans += calc(uvec, lvec);
	for(int i = 0; i < uvec.size(); i++) uvec[i].first = L - uvec[i].first;
	ans += calc(uvec, rvec);
	
	cout << ans << endl;
	
	return 0;
}
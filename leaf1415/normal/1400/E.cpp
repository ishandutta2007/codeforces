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

struct SparseTable{
	int size;
	vector<vector<P> > vec;
	SparseTable(){}
	SparseTable(int size){
		this->size = size;
		vec.resize(size+1);
		for(int i = 0; i <= size; i++) vec[i].resize(1<<size);
		for(int i = 0; i < (1<<size); i++) vec[0][i] = P(inf, inf);  //
	}
	void set(int i, P val){
		vec[0][i] = val;
	}
	void calc(){
		for(int i = 1; i <= size; i++){
			for(int j = 0; j < (1<<size); j++){
				if(j+(1<<(i-1)) < (1<<size)){
					vec[i][j] = min(vec[i-1][j], vec[i-1][j+(1<<(i-1))]); //
				}
			}
		}
	}
	P query(int l, int r)
	{
		int k = 0;
		for(int i = 0; r-l+1 >= (1<<i); i++) k = i;
		return min(vec[k][l], vec[k][r-(1<<k)+1]); //
	}
};


llint n;
llint a[5005];
SparseTable sp(13);

llint calc(llint l, llint r, llint h)
{
	//cout << l << " " << r << endl;
	if(l > r) return 0;
	llint ret = 0;
	
	llint pre = l-1, mn = sp.query(l, r).first;
	ret += mn-h;
	
	while(pre+1 <= r && sp.query(pre+1, r).first == mn){
		llint nx = sp.query(pre+1, r).second;
		ret += calc(pre+1, nx-1, mn);
		pre = nx;
	}
	ret += calc(pre+1, r, mn);
	
	ret = min(ret, r-l+1);
	//cout << l << " " << r << " " << ret << endl;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++) sp.set(i, P(a[i], i));
	sp.calc();
	
	llint ans = 0, pre = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 0){
			ans += calc(pre+1, i-1, 0);
			pre = i;
		}
	}
	ans += calc(pre+1, n, 0);
	
	cout << ans << endl;
	
	return 0;
}
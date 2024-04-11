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
typedef pair<P, llint> T;

struct SparseTable{
	int size;
	vector<vector<P> > vec;
	SparseTable(){}
	SparseTable(int size){
		this->size = size;
		vec.resize(size+1);
		for(int i = 0; i <= size; i++) vec[i].resize(1<<size);
		for(int i = 0; i < (1<<size); i++) vec[0][i] = P(-inf, -inf);  //
	}
	void set(int i, P val){
		vec[0][i] = val;
	}
	void calc(){
		for(int i = 1; i <= size; i++){
			for(int j = 0; j < (1<<size); j++){
				if(j+(1<<(i-1)) < (1<<size)){
					vec[i][j] = max(vec[i-1][j], vec[i-1][j+(1<<(i-1))]); //
				}
			}
		}
	}
	P query(int l, int r)
	{
		int k = 0;
		for(int i = 0; r-l+1 >= (1<<i); i++) k = i;
		return max(vec[k][l], vec[k][r-(1<<k)+1]); //
	}
};

ll n;
P p[3005];
ll d[3005];
ll a[3005];
SparseTable sp(13);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> p[i].first, p[i].second = i;
	sort(p+1, p+n+1);
	reverse(p+1, p+n+1);
	
	p[n+1].first = 0;
	rep(i, 1, n) d[i] = p[i].first - p[i+1].first;
	
	rep(i, 1, n) sp.set(i, P(d[i], i));
	sp.calc();
	
	//rep(i, 1, n) cout << p[i].first << " "; cout << endl;
	
	T ans = T(P(-1, 0), 0); ll ans_i, ans_j, ans_k;
	rep(i, 1, n){
		rep(j, 1, n){
			if(i+j >= n || i*2 < j || i > j*2) continue;
			ll l = max(1LL, max((i+1)/2, (j+1)/2)), r = min(n-(i+j), min(2*i, 2*j));
			if(l > r) continue;
			P res = sp.query(i+j+l, i+j+r); ll k = res.second-(i+j);
			T tmp = T(P(d[i], d[i+j]), d[i+j+k]);
			if(ans < tmp) ans = tmp, ans_i = i, ans_j = j, ans_k = k;
		}
	}
	assert(ans.first.first >= 0);
	//cout << ans.first.first << " " << ans.first.second << " " << ans.second << endl;
	//cout << ans_i << " " << ans_j << " " << ans_k << endl;
	
	rep(i, 1, n) a[i] = -1;
	rep(i, 1, ans_i) a[p[i].second] = 1;
	rep(i, ans_i+1, ans_i+ans_j) a[p[i].second] = 2;
	rep(i, ans_i+ans_j+1, ans_i+ans_j+ans_k) a[p[i].second] = 3;
	rep(i, 1, n) cout << a[i] << " "; cout << endl;
	
	return 0;
}
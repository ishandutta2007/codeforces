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

struct GaussianElimination{
	vector<llint> vec;
	int dim;
	
	GaussianElimination(){
		init();
	}
	void init(){
		dim = 0;
		vec.clear();
	}
	void add(llint x)
	{
		vec.push_back(x);
		int n = vec.size();
		
		int r = 0, p = -1;
		for(int i = 59; i >= 0 && r < n-1; i--){ //
			if((vec[r]&(1LL<<i)) == 0){
				if((vec[n-1]&(1LL<<i)) == 0 || p != -1) goto end;
				if(p == -1) p = r;
			}
			else if(vec[n-1]&(1LL<<i)) vec[n-1] ^= vec[r];
			r++;
			end:;
		}
		if(p != -1){
			llint tmp = vec[n-1];
			for(int i = n-1; i >= p+1; i--) vec[i] = vec[i-1];
			vec[p] = tmp;
		}
		if(vec[dim]) dim++;
	}
	
	bool check(llint x)
	{
		int n = vec.size();
		
		int r = 0;
		for(int i = 59; i >= 0 && r < n; i--){
			if((x & (1LL<<i)) == 0){
				if(vec[r] & (1LL<<i)) r++;
				continue;
			}
 			if((vec[r]&(1LL<<i)) == 0) return false;
			x ^= vec[r];
			r++;
		}
		return x == 0;
	}
};

int n, Q;
int a[100005];
int l[100005], x[100005];
ll qans[100005];
vector<P> vec[100005];
ll beki[100005];
GaussianElimination ge;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	beki[0] = 1;
	rep(i, 1, 100004) beki[i] = beki[i-1] * 2 % mod;
	
	cin >> n >> Q;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, Q){
		cin >> l[i] >> x[i];
		vec[l[i]].push_back(P(x[i], i));
	}
	
	rep(i, 1, n){
		ge.add(a[i]);
		for(auto p : vec[i]){
			int x = p.first, id = p.second;
			if(ge.check(x)) qans[id] = beki[i-ge.dim];
		}
	}
	
	rep(i, 1, Q) cout << qans[i] << "\n";
	flush(cout);
	
	return 0;
}
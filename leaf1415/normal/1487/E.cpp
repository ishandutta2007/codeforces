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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

struct SparseTable{
	int size;
	vector<vector<llint> > vec;
	SparseTable(){}
	SparseTable(int size){
		this->size = size;
		vec.resize(size+1);
		for(int i = 0; i <= size; i++) vec[i].resize(1<<size);
		for(int i = 0; i < (1<<size); i++) vec[0][i] = inf;  //
	}
	void set(int i, llint val){
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
	llint query(int l, int r)
	{
		if(l > r) return inf;
		int k = 0;
		for(int i = 0; r-l+1 >= (1<<i); i++) k = i;
		return min(vec[k][l], vec[k][r-(1<<k)+1]); //
	}
};


ll n[5];
ll a[5][150005];
vector<ll> vec[5][150005];
ll dp[5][150005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	rep(i, 1, 4) cin >> n[i];
	rep(i, 1, 4) rep(j, 1, n[i]) cin >> a[i][j];
	
	ll m, u, v;
	rep(i, 2, 4){
		cin >> m;
		rep(j, 1, m){
			cin >> u >> v;
			vec[i][v].push_back(u);
		}
	}
	
	rep(i, 1, n[1]) dp[1][i] = a[1][i];
	
	rep(i, 2, 4){
		SparseTable sp(18);
		rep(j, 1, n[i-1]) sp.set(j, dp[i-1][j]);
		sp.calc();
		
		rep(j, 1, n[i]){
			vec[i][j].push_back(0), vec[i][j].push_back(n[i-1]+1);
			sort(all(vec[i][j]));
			ll cost = inf;
			rep(k, 1, (int)vec[i][j].size()-1){
				chmin(cost, sp.query(vec[i][j][k-1]+1, vec[i][j][k]-1));
			}
			cost += a[i][j];
			dp[i][j] = cost;
		}
	}
	
	ll ans = inf;
	rep(i, 1, n[4]) chmin(ans, dp[4][i]);
	if(ans > inf/2) ans = -1;
	cout << ans << endl;
	
	return 0;
}
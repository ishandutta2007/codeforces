#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#define llint long long
#define mod 998244353
#define inf 1000000000000000000

using namespace std;
typedef pair<llint, llint> P;

struct SparseTable{
	int size;
	vector<vector<P> > vec;
	SparseTable();
	SparseTable(int size){
		this->size = size;
		vec.resize(size+1);
		for(int i = 0; i <= size; i++) vec[i].resize(1<<size);
		for(llint i = 0; i < (1<<size); i++) vec[0][i] = make_pair(inf, i);  //
	}
	void set(llint i, P val){
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
	P query(llint l, llint r)
	{
		int k = 0;
		for(int i = 0; r-l+1 >= (1<<i); i++) k = i;
		return min(vec[k][l], vec[k][r-(1<<k)+1]); //
	}
};

llint n, m;
llint a[505];
llint dp[505][505];
SparseTable sp(10);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(llint i = 1; i <= n; i++) sp.set(i, make_pair(a[i], i));
	sp.calc();
	
	for(int i = 0; i <= n+1; i++){
		for(int j = 0; j <= n+1; j++){
			dp[i][j] = 1;
		}
	}
	for(int len = 2; len <= n; len++){
		for(int l = 1; l+len-1 <= n; l++){
			int r = l+len-1;
			int p = sp.query(l, r).second;
			//cout << p << endl;
			llint tmp = 0, tmp2 = 0;
			for(int k = l; k <= p; k++) tmp += dp[l][k-1] * dp[k][p-1] % mod, tmp %= mod;
			for(int k = p+1; k <= r+1; k++) tmp2 += dp[p+1][k-1] * dp[k][r] % mod, tmp2 %= mod;
			//cout << l << " " << r << " " << tmp << " " << tmp2 << endl;
			dp[l][r] = tmp * tmp2 % mod;
		}
	}
	/*for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << dp[1][n] << endl;
	
	return 0;
}
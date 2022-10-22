#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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
#define inf 1e9
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 998244353

using namespace std;
typedef pair<int, int> P;

int T;
int n;
int a[20], sum[1<<15];
int pos[1<<15][16];
int dp[16][16][1<<15];
P pre[16][16][1<<15];
int dest[20], bit[20];
vector<int> vec;
vector<P> ans;

void zeta_transform(int a[], int n)
{
	int S = 1<<n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < S; j++){
			if((j&(1<<i))) a[j] += a[j^(1<<i)];
		}
	}
}

int get(int x)
{
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] == x) return i;
	}
}

void add(int x, int y)
{
	int X = get(x), Y = get(y);
	ans.emplace_back(P(X, Y));
	vec.erase(vec.begin() + X);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i = 0; i < (1<<15); i++){
		int x = -1;
		for(int j = 14; j >= 0; j--){
			if(i&(1<<j)) x = j;
			pos[i][j] = x;
		}
	}
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		
		int N = 1<<n;
		for(int i = 0; i < N; i++) sum[i] = 0;
		for(int i = 0; i < n; i++) sum[1<<i] = a[i];
		zeta_transform(sum, n);
		
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				for(int k = 0; k < N; k++){
					dp[i][j][k] = inf;
				}
			}
		}
		dp[0][0][0] = 0;
		
		int p, S;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(int k = 0; k < N; k++){
					if(dp[i][j][k] > inf/2) continue;
					S = (N-1)-k;
					for(int l = S; l; l=(l-1)&S){
						p = pos[l][j];
						if(p == -1) continue;
						if(sum[l] > dp[i][j][k]){
							if(dp[i+1][p+1][k|l] > sum[l]){
								dp[i+1][p+1][k|l] = sum[l];
								pre[i+1][p+1][k|l] = P(j, k);
							}
						}
					}
				}
			}
		}
		
		int I, J, K, m;
		for(int i = n; i >= 0; i--){
			for(int j = 0; j <= n; j++){
				if(dp[i][j][N-1] < inf){
					I = i, J = j, K = N-1;
					goto end;
				}
			}
		}
		end:;
		
		//cout << I << " " << J << " " << K << endl;
		
		m = I;
		while(I > 0){
			dest[I] = J-1;
			P p = pre[I][J][K];
			bit[I] = K - p.second;
			J = p.first, K = p.second, I--;
		}
		
		vec.clear();
		for(int i = 0; i < n; i++) vec.emplace_back(i);
		
		ans.clear();
		for(int i = 1; i <= m; i++){
			int p = dest[i];
			for(int j = 0; j < n; j++){
				if(j == p) continue;
				if(bit[i]&(1<<j)) add(j, p);
			}
		}
		
		cout << ans.size() << "\n";
		for(int i = 0; i < ans.size(); i++) cout << ans[i].first+1 << " " << ans[i].second+1 << "\n";
	}
	flush(cout);
	
	return 0;
}
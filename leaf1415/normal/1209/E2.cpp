#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint Q;
llint h, w;
llint a[12][13], b[12][2005];
llint dp[13][1<<12];
llint val[2005][1<<12];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int t = 0; t < Q; t++){
		cin >> h >> w;
		for(int i = 0; i < h; i++){
			for(int j = 1; j <= w; j++){
				cin >> b[i][j];
			}
		}
		vector<P> vec;
		for(int i = 0; i < h; i++){
			for(int j = 1; j <= w; j++){
				vec.push_back(make_pair(b[i][j], j));
			}
		}
		sort(vec.rbegin(), vec.rend());
		
		set<llint> S;
		for(int i = 0; i < vec.size(); i++){
			if(S.size() >= min(h, w)) break;
			S.insert(vec[i].second);
		}
		
		w = min(h, w); int id = 1;
		for(auto it = S.begin(); it != S.end(); it++){
			for(int i = 0; i < h; i++) a[i][id] = b[i][*it];
			id++;
		}
		
		int N = 1<<h;
		for(int i = 1; i <= w; i++){
			for(int j = 0; j < N; j++){
				val[i][j] = 0;
			}
		}
		for(int i = 1; i <= w; i++){
			for(int j = 0; j < N; j++){
				llint mask = j, sum = 0;
				for(int k = 0; k < h; k++){
					if(j & (1<<k)) sum += a[k][i];
				}
				for(int k = 0; k < h; k++){
					val[i][mask] = max(val[i][mask], sum);
					mask |= ((mask & 1) << h);
					mask >>= 1; 
				}
			}
		}
		
		for(int i = 0; i <= w; i++){
			for(int j = 0; j < N; j++){
				dp[i][j] = -1e18;
			}
		}
		dp[0][0] = 0;
		for(int i = 0; i < w; i++){
			for(int j = 0; j < N; j++){
				int nj = (N-1) - j;
				for(int k = nj; k > 0; k = (k-1)&nj){
					dp[i+1][j|k] = max(dp[i+1][j|k], dp[i][j] + val[i+1][k]);
				}
				dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			}
		}
		cout << dp[w][N-1] << endl;
	}
	
	return 0;
}
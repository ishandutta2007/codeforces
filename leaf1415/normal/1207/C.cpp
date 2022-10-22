#include <iostream>
#include <vector>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n, a, b;
string s;
llint dp[200005][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> a >> b;
		cin >> s;
		int m = s.size();
		s = "#" + s;
		
		for(int i = 0; i <= m; i++){
			for(int j = 0; j < 2; j++){
				dp[i][j] = 1e18;
			}
		}
		dp[0][0] = b;
		
		for(int i = 0; i < m; i++){
			for(int j = 0; j < 2; j++){
				for(int k = 0; k < 2; k++){
					if(i+2 <= m && k < s[i+2]-'0') continue;
					if(k < s[i+1]-'0') continue;
					llint cost = (k+1)*b;
					if(j != k) cost += a;
					dp[i+1][k] = min(dp[i+1][k], dp[i][j] + cost);
				}
			}
		}
		/*for(int i = 0; i <= m; i++){
			for(int j = 0; j < 2; j++){
				 cout << dp[i][j] << " ";
			}
			cout << endl;
		}*/
		cout << dp[m][0] + a*n << "\n";
	}
	flush(cout);
	
	return 0;
}
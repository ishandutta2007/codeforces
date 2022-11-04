/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxM = 200*1000 + 5;
const int mod  = 1000*1000*1000 + 7;

int n,m;
int dp[maxM] , sum[maxM];
pii bus[maxM];
vector <int> test , End;
vector <int> Q[maxM];

int main(){

	ios::sync_with_stdio (false);

	cin >> n >> m;

	for (int i=1; i<=m; i++){
		cin >> bus[i].first >> bus[i].second;
		test.push_back (bus[i].second);
	}

	test.push_back (0);
	test.push_back (n);

	sort (test.begin() , test.end());

	for (int i=0; i<(int)test.size(); i++) if (i==0 || test[i]!=test[i-1])
		End.push_back (test[i]);

	for (int i=1; i<=m; i++){
		int pos = lower_bound (End.begin() , End.end() , bus[i].second) - End.begin();
		Q[pos].push_back (i);
	}

	dp [0]=1;
	sum[0]=1;

	for (int i=1; i<(int)End.size(); i++){
		
		for (int j=0; j<(int)Q[i].size(); j++){
			
			int now = Q[i][j];
			int pos = lower_bound (End.begin() , End.end(), bus[now].first) - End.begin();

			if (pos!=i){
				
				int add;
				if (pos==0)
					add = sum[i-1];
				else
					add = (sum[i-1] - sum[pos-1])%mod;

				dp[i] = (dp[i] + add)%mod;
			}
		}
		sum[i] = (sum[i-1] + dp[i])%mod;
	}

	cout << (dp[(int)End.size()-1] + mod)%mod << endl;
	
	return 0;
}
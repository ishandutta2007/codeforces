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
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long LL;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

const int MAXN = 1000 * 100  + 10;

bool mark[MAXN];
int n;
int dp[MAXN];
vector <int> adj[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i=0; i<n; i++){ 
		int temp; cin >> temp;
		dp[temp] = 1;
	}
	for (int i=2; i<MAXN; i++) if (!mark[i]){
		int past = (dp[i] == 0) ? (-1) : (i);
		for (int j=i*2; j<MAXN; j+=i){
			mark[j] = true;
			if (dp[j] == 1){
				if (past!=-1)
					adj[past].push_back(j);
				past = j;
			}
		}
	}
	for (int i=MAXN-1; i>0; i--) if (dp[i] == 1)
		for (int j=0; j<(int)adj[i].size(); j++)
			dp[i] = max(dp[i], dp[adj[i][j]] + 1);
	cout << (*max_element(dp,dp+MAXN)) << endl;
	return 0;
}
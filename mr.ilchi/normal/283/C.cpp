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

const int mod = 1000000007;

bool mark[1000];
int n,q,t;
int a[1000],b[1000],c[1000],next[1000],in[1000];
int dp[310][100000+10];

int main(){
	cin >> n >> q >> t;
	for (int i=0; i<n; i++) 
		cin >> a[i];
	memset(next, -1, sizeof next);
	for (int i=0; i<q; i++){
		cin >> b[i] >> c[i];
		b[i]--; c[i]--;
		next[b[i]] = c[i];
		in[c[i]]++;
	}
	vector <pii> Q;
	for (int i=0; i<n; i++) if (in[i]==0){
		int cur = i;
		int sum = 0;
		while (cur!=-1 && !mark[cur]){
			mark[cur] = true;
			sum+= a[cur];
			if (next[cur]==-1)
				Q.push_back(pii(sum,0));
			else
				Q.push_back(pii(sum,1));
			cur = next[cur];
		}
		if (cur!=-1){
			cout << 0 << endl;
			return 0;
		}
	}
	for (int i=0; i<n; i++) if (!mark[i]){
		cout << 0 << endl;
		return 0;
	}
	dp[0][0] = 1;
	for (int i=0; i<(int)Q.size(); i++){
		int cost = Q[i].first;
		int type = Q[i].second;
		for (int j=0; j<=t; j++){
			if (type==0){
				dp[i+1][j] = dp[i][j];
				if (cost<=j)
					dp[i+1][j] = (dp[i+1][j] + dp[i+1][j-cost]) % mod;
			}
			else if (cost<=j)
				dp[i+1][j] = (dp[i][j-cost] + dp[i+1][j-cost]) % mod;
			else
				dp[i+1][j] = 0;
		}
	}
	cout << dp[(int)Q.size()][t] << endl;
	return 0;
}
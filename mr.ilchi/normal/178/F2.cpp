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
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <complex>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int maxT = 500 * 100 + 10;

int n,k,tedad=1;
int sum[maxT];
int f[maxT][30] , dp[maxT][110];

void add (string s){

	int now = 1;

	for (int i=0; i<(int)s.size(); i++){
		
		int ind = s[i] - 'a';

		if (f[now][ind]==0){
			tedad++; 
			f[now][ind] = tedad;
		}

		now = f[now][ind];
	}

	sum[now]++;
}

void dfs (int v, int h){
	
	dp[v][0] = 0;

	for (int i=1; i<=sum[v]; i++)
		dp[v][i] = h * (i-1) * i / 2;

	for (int i=0; i<26; i++) if (f[v][i]!=0){
		dfs (f[v][i],h+1);
		int tmp = f[v][i];
		for (int j=k; j; j--)
			for (int z=1; z<=j && dp[tmp][z]!=-1; z++) if (dp[v][j-z]!=-1)
				dp[v][j] = max(dp[v][j] , dp[v][j-z] + dp[tmp][z] + h * (j-z) * z);
	}
}

int main(){

	cin >> n >> k;

	for (int i=1; i<=n; i++){
		string s; cin >> s;
		add(s);
	}

	memset (dp,-1,sizeof dp);

	dfs(1,0);
	
	cout << dp[1][k] << endl;

	return 0;
}
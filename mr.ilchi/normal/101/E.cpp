/*
 * in the name of god
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
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int base = 1000;
const int MAXP = 20+5;
const int MAXN = 20000+10;

int n,m,mod;
int x[MAXN],y[MAXN];
int dp[2][MAXN],preR[MAXP][MAXN],preC[MAXN][MAXP],test[base+5][base+5];

int func (int a, int b) { return (x[n-a]+y[m-b])%mod; }

void go (int x, int y){

	if (x==1 && y==1)  { cout << endl ; return; }
	if (x==1) { cout << 'S'; go(x,y-1); return; }
	if (y==1) { cout << 'C'; go(x-1,y); return; }
	
	if (x%base==1){
		if (preR[x/base][y] == preR[x/base][y-1] + func(x,y)){
			cout << 'S'; 
			go(x,y-1);
		}
		else{
			cout << 'C';
			go(x-1,y);
		}		
		return;
	}
	if (y%base==1){
		if (preC[x][y/base] == preC[x-1][y/base] + func(x,y)){
			cout << 'C';
			go(x-1,y);
		}
		else{
			cout << 'S';
			go(x,y-1);
		}
		return;
	}
	int fx = (x-1)/base*base+1;
	int fy = (y-1)/base*base+1;
	for (int i=fx; i<=x; i++){
		for (int j=fy; j<=y; j++){
			if (i==fx)
				test[i-fx][j-fy] = preR[i/base][j];
			else if (j==fy)
				test[i-fx][j-fy] = preC[i][j/base];
			else
				test[i-fx][j-fy] = max(test[i-fx-1][j-fy],test[i-fx][j-fy-1]) + func(i,j);
		}
	}
	while (x!=fx && y!=fy){
		if (test[x-fx][y-fy] == test[x-fx-1][y-fy] + func(x,y)){
			cout << 'C'; 
			x--;
		}
		else{
			cout << 'S';
			y--;
		}
	}
	go(x,y);
}

int main(){
	cin >> n >> m >> mod;
	for (int i=0; i<n; i++) cin >> x[i];
	for (int i=0; i<m; i++) cin >> y[i];
	for (int i=1; i<=n; i++){
		int cur = i%2;
		int oth = 1-cur;
		for (int j=1; j<=m; j++){
			dp[cur][j] = 0;
			if (i>1) dp[cur][j] = max(dp[cur][j],dp[oth][j]);
			if (j>1) dp[cur][j] = max(dp[cur][j],dp[cur][j-1]);
			dp[cur][j]+= func(i,j);
			if (i%base==1) preR[i/base][j] = dp[cur][j];
			if (j%base==1) preC[i][j/base] = dp[cur][j];
		}
	}
	cout << dp[n%2][m] << endl;
	go(n,m);
	return 0;
}
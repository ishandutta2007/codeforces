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

const int maxN = 200 * 1000;

int n,m,c;
int prob[maxN],x[maxN];
double prof[maxN];
double mini[maxN][20],maxi[maxN][20],dp[maxN][20];

int main(){
	
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> c;

	for (int i=1; i<=n; i++)
		cin >> x[i];

	for (int i=1; i<n; i++)
		cin >> prob[i];

	prof[0]=0.0;

	for (int i=1; i<n; i++){
		double p = prob[i] * 1.0 / 100.0;
		prof[i] = p * (-c) + ((x[i+1]-x[i]) * 1.0 / 2.0);
		prof[i]+= prof[i-1];
	}

	for (int i=1; i<n; i++){
		mini[i][0] = prof[i];
		maxi[i][0] = prof[i];
		dp[i][0] = max(0.0,prof[i]-prof[i-1]);
		for (int j=1; (1<<j)<=i; j++){
			int past = i - (1<<(j-1));
			mini[i][j] = min(mini[i][j-1],mini[past][j-1]);
			maxi[i][j] = max(maxi[i][j-1],maxi[past][j-1]);
			dp[i][j] = max(max(dp[i][j-1],dp[past][j-1]),maxi[i][j-1]-mini[past][j-1]); 
		}
	}

	double ret = 0;

	for (int i=1; i<=m; i++){
		int beg,fin; cin >> beg >> fin;
		fin--;
		beg--;
		int dif = fin-beg;
		double MIN = prof[beg];
		int now = beg+1;
		double ans = 0.0;
		for (int j=0; j<=20; j++) if (dif & (1<<j)){
			now+= (1<<j)-1;
			ans = max(ans,dp[now][j]);
			ans = max(ans,maxi[now][j]-MIN);
			MIN = min(MIN,mini[now][j]);
			now++;
		}
		ret += ans;

	//	cout << beg+1 << ' ' << fin+1 << ' ' << ((prof[fin] - prof[beg]) - ans) << endl;

	/*	ans = 0.0;

		for (int j=beg; j<=fin; j++)
			for (int z=j; z<=fin; z++)
				ans = min (ans , prof[z]-prof[j]);

		ret += ((prof[fin] - prof[beg]) - ans); */
	}

	cout << fixed << setprecision(10) << ret << endl;

	return 0;
}
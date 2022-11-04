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

const int BASE = 800;
const int MAXN = 100000+10;
const int inf = 1000000000;

int n,k;
int cnt[MAXN];
int dp1[MAXN],dp2[MAXN];
int func1[MAXN],func2[MAXN];
int mini1[MAXN],mini2[MAXN];
vector <int> Q[MAXN];

int main(){
	scanf("%d%d", &n, &k);
	int ret = 0;
	for (int i=0; i<k; i++){
		int r,c; scanf("%d%d", &r, &c);
		r = n-r;
		c--;
		if (r>=BASE)
			ret+= 3;
		else{
			cnt[c] = max(cnt[c], r+1);
			Q[c].push_back(r);
		}
	}
	for (int i=0; i<n; i++)
		sort(Q[i].begin(), Q[i].end());
	for (int j=0; j<=BASE; j++){
		func2[j] = (j+1) * (j+2)/2 + 2 - 3 * (j+1);
		if (j!=0)
			func2[j] = min(func2[j], func2[j-1]);
	}
	for (int j=BASE; j>=0; j--)
		mini2[j] = (j+1) * (j+2)/2 + 2;
	for (int i=n-1; i>=0; i--){
		int poi = 0;
		for (int j=0; j<=BASE; j++){
			while (poi<(int)Q[i].size() && Q[i][poi]<j)
				poi++;
			dp1[j] = dp2[max(0, j-1)] + 3 * ((int)Q[i].size()-poi);
			if (j < cnt[i])
				dp1[j] = min(dp1[j], func2[max(0, cnt[i]-1)] + 3 * (int)Q[i].size());
			dp1[j] = min(dp1[j], mini2[max(0, cnt[i]-1)]);
			func1[j] = dp1[j] + (j+1)*(j+2)/2 + 2; 
			mini1[j] = dp1[j] + (j+1)*(j+2)/2 + 2;
		}
		if (i!=0){
			poi = 0;
			for (int j=0; j<=BASE; j++){
				while (poi<(int)Q[i-1].size() && Q[i-1][poi]<=j)
					poi++;
				func1[j]-= 3 * poi;
				if (j!=0) func1[j] = min(func1[j], func1[j-1]);
			}
		}
		for (int j=BASE; j>=0; j--){
			if (j!=BASE)
				mini1[j] = min(mini1[j], mini1[j+1]);
			mini2[j] = mini1[j];
		}
		for (int j=0; j<=BASE; j++){
			dp2[j] = dp1[j];
			func2[j] = func1[j];
		}
//		for (int j=0; j<=n; j++)
//			cout << dp1[j] << ' ';
//		cout << endl;
	}
	cout << ret + dp1[0] << endl;
	return 0;
}
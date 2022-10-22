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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

#include <iostream>
#include <unordered_map>

using namespace std;

int tableL[45], tableH[45];
int pop[1<<20];
bool valid1[1<<20], valid2[1<<20];
int dp[1<<20];

int MaxClique(int G[45][45], int n)
{
	if(n == 1) return 1;
	
	for(int i = 1; i < (1<<20); i++) pop[i] = pop[i&(i-1)] + 1;
	for(int i = 0; i < n; i++) G[i][i] = 1;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n/2; j++){
			tableL[i] |= (G[i][j]) << j;
		}
		for(int j = n/2; j < n; j++){
			tableH[i] |= (G[i][j]) << (j-n/2);
		}
	}
	
	int N = 1<<(n/2);
	for(int i = 0; i < N; i++){
		int val = i;
		for(int j = 0; j < n/2; j++){
			if(i & (1<<j)) val &= tableL[j];
		}
		if(val == i) valid1[i] = true;
	}
	N = 1<<(n-n/2);
	for(int i = 0; i < N; i++){
		int val = i;
		for(int j = 0; j < n-n/2; j++){
			if(i & (1<<j)) val &= tableH[j+n/2];
		}
		if(val == i) valid2[i] = true;
	}
	
	for(int i = 0; i < N; i++){
		if(valid2[i]){
			dp[i] = pop[i];
			continue;
		}
		for(int j = 0; j < n-n/2; j++){
			dp[i] = max(dp[i], dp[i & ~(1<<j)]);
		}
	}
	
	int ret = 0; N = 1<<(n/2);
	for(int i = 0; i < N; i++){
		if(!valid1[i]) continue;
		int val = (1<<(n-n/2)) - 1;
		for(int j = 0; j < n/2; j++){
			if(i & (1<<j)) val &= tableH[j];
		}
		ret = max(ret, pop[i] + dp[val]);
	}
	
	return ret;
}


ll n, k;
int G[45][45];

int main(void)
{
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		rep(j, 0, n-1){
			cin >> G[i][j];
		}
	}
	
	int res = MaxClique(G, n);
	double x = (double)k / res;
	res = res*(res-1)/2;
	
	printf("%.11f\n", res * x * x);
	
	return 0;
}
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

const int inf = 1000000000;
const int maxB= 1<<16;
const int maxI= 105+10;
const int maxN= 500 * 1000 + 10;

int n,m,k;
int a [maxN];
int dp[maxB][maxI],nex[maxN][20];
map <string,int> mp;

int bit (int x) { return 1<<x; }

int go(){
	fill(&nex[0][0],&nex[maxN-1][19],inf);
	fill(&dp [0][0],&dp[maxB-1][maxI-1],inf);
	for (int i=k; i>0; i--){
		for (int j=1; j<=n; j++)
			nex[i][j] = nex[i+1][j];
		nex[i][a[i]] = i;
	}
	dp[0][0] = 0;
	for (int i=1; i<bit(n); i++){
		int cnt=0;
		int cntBit=__builtin_popcount(i);
		for (int j=0; j<n; j++) if (i&bit(j)){
			cnt++;
			int inv = cntBit - cnt;
			for (int z=inv; z<=cntBit*(cntBit-1)/2; z++){
				int tmp = dp[i^bit(j)][z-inv]; 
				if (tmp!=inf)
					dp[i][z] = min(dp[i][z],nex[tmp+1][j+1]);
			}
		}
	}
	for (int i=0; i<=n*(n-1)/2; i++) if (dp[bit(n)-1][i]<=k)
		return i;
	return inf;
}

int main(){
	cin >> n;
	for (int i=1; i<=n; i++){
		string s; cin >> s;
		mp[s] = i;
	}
	ll ans = inf , pos=-1;
	cin >> m;
	for (int i=1; i<=m; i++){
		cin >> k;
		for (int j=1; j<=k; j++){
			string s; cin >> s;
			if (mp.count(s)!=0)
				a[j] = mp[s];
			else{
				k--; 
				j--;
			}
		}
		ll tmp = go();
		if (tmp < ans){
			ans = tmp;
			pos = i;
		}
	}
	if (ans == inf)
		cout << "Brand new problem!" << endl;
	else
		cout << pos << endl << "[:" << string(n*(n-1)/2-ans+1,'|') << ":]" << endl; 
	return 0;
}
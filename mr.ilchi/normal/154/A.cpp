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

const int maxN = 100 * 1000 + 10;

bool bad[30][30];
int n,m;
int dp[maxN],near[30];
string s;

int main(){
	
	memset (near,-1,sizeof near);

	cin >> s;
	cin >> m;
	for (int i=1; i<=m; i++){
		string tmp; cin >> tmp;
		int a = tmp[0]-'a';
		int b = tmp[1]-'a';
		bad[a][b] = bad[b][a] = true;
	}

	dp[0]=1;
	near[s[0]-'a']=0;
	int ans = 1;	
	for (int i=1; i<s.size(); i++){
		int x = s[i]-'a';
		dp[i] = 1;
		for (int j=0; j<26; j++) if (near[j]!=-1 && !bad[x][j])
			dp[i]=max(dp[i],dp[near[j]] + 1);
		near[x] = i;
		ans = max (ans , dp[i]);
	}

	cout << s.size() - ans << endl;

	return 0;
}
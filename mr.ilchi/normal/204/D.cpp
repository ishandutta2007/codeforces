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

const int MAXN= 1000 * 1000 + 10;
const int mod = 1000 * 1000 * 1000 + 7;

int len,k;
int tot[MAXN],cnt[MAXN];
int dp [2][MAXN],end[2][MAXN];
string s;

void get(int *dp, int *end, char t, char tt){
	cnt[0]=0;
	tot[0]=1;
	for (int i=0; i<len; i++){
		cnt[i+1] = cnt[i] + (s[i]==tt);
		tot[i+1] = (tot[i]*((s[i]=='X')+1))%mod;
	}
	dp[0] = 0;
	for (int i=1; i<=len; i++){
		if (i<k || s[i-1]==tt){
			dp [i] = dp[i-1];
			end[i] = 0;
			continue;
		}
		dp[i] = ((s[i-1]=='X') + 1) * dp[i-1]; dp[i]%=mod;
		end[i] = 0;
		if (cnt[i]==cnt[i-k] && (i==k || s[i-1-k]!=t)){
			if (i<=k+1)
				end[i]=1;
			else
				end[i]=(tot[i-k-1] - dp[i-k-1])%mod;
		}
		dp[i]+=end[i]; dp[i]%=mod;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> len >> k >> s;
	get(&dp[0][0],&end[0][0],'B','W'); reverse(s.begin(),s.end());
	get(&dp[1][0],&end[1][0],'W','B'); reverse(s.begin(),s.end());
	ll ans = 0;
	for (int i=0; i<len; i++){
		ans+= (ll)end[0][i+1] * (ll)dp[1][len-i-1];
		ans%=mod;
	}
	ans+=mod; ans%=mod;
	cout << ans << endl;
	return 0;
}
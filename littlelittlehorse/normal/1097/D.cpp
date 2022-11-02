#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
	const int maxn = 131072;
	static char buf[maxn],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
inline int getInt() {
	int res(0);
	char c = getchar();
	while(c < '0') c = getchar();
	while(c >= '0') {
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return res;
}

inline int fastpo(int x, int n, int mod) {
	int res(1);
	while(n) {
		if(n & 1) {
			res = res * (LL)x % mod;
		}
		x = x * (LL) x % mod;
		n /= 2;
	}
	return res;
}
const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dp[10011][55][55];
int s[55][55];
int inv[111];
int main() {
	LL n;
  int k;
  cin >> n >> k;
  LL x = n;
  vector<pair<LL, int> > vec;
  for(LL i(2); i * i <= n; i++) {
    if(n % i == 0) {
      vec.push_back(make_pair(i, 0));
      while(x % i == 0) {
        vec.back().second++;
        x /= i;
      }
    }
  }
  if(x != 1) vec.push_back(make_pair(x, 1));
  /*for(auto tmp : vec) {
    cout << tmp.first << ' ' << tmp.second << endl;
  }*/
  int ans = 1;
  memset(dp, 0, sizeof(dp));
  for(int i(0); i <= 50; i++) dp[0][i][i] = 1;
  for(int i(0); i <= 100; i++) {
    inv[i] = fastpo(i, mod - 2, mod);
  }
  for(int l(1); l <= k; l++) {
    memset(s, 0, sizeof(s));
    for(int i(0); i <= 50; i++) {
      for(int j(i); j <= 50; j++) {
       s[i][j] = ((j == 0 ? 0 : s[i][j - 1]) + dp[l - 1][i][j]) % mod;
      }
    }
    
    for(int i(0); i <= 50; i++) {
      for(int j(i); j <= 50; j++) {
        dp[l][i][j] = ((s[i][j] - (i == 0 ? 0 : s[i][i - 1])) * (LL)inv[j + 1] % mod + mod) % mod;
        //printf("dp[%d][%d][%d] = %d\n", l, i, j, dp[l][i][j]);
      }
    }
  }
  for(int i(0); i < (int)vec.size(); i++) {
    LL p = vec[i].first % mod;
    int l = vec[i].second;
    int pw = 1;
    int tmp = 0;
    for(int j(0); j <= l; j++) {
      tmp = (tmp + dp[k][j][l] * (LL)pw) % mod;
      pw = (LL)pw * p % mod;
    }
    ans = (ans * (LL)tmp) % mod;
  }
  cout << ans << endl;
}
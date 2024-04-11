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
int main() {
	int n;
  scanf("%d", &n);
  int cnt0 = 0;
  map<int, int> frnt, bck;
  for(int i(1); i <= n; i++) {
    string a;
    cin >> a;
    int cnt = 0;
    bool flag = true;
    for(int i(0); i < (int)a.size(); i++) {
      cnt += a[i] == '(' ? 1 : -1;
      if(cnt < 0) flag = false;
    }
    if(flag) {
      if(cnt == 0) {
        cnt0++;
        continue;
      }else {
        frnt[cnt]++;
      }
    }

    cnt = 0;
    flag = true;
    for(int i((int)a.size() - 1); i >= 0; i--) {
      cnt += a[i] == ')' ? 1 : -1;
      if(cnt < 0) flag = false;
    }
    if(flag) {
      bck[cnt]++;
    }
  }
  int ans = cnt0 / 2;
  for(auto tmp : frnt) {
    ans += min(tmp.second, bck[tmp.first]);
  }
  printf("%d\n", ans);
}
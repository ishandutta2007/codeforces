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
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
typedef bitset<7007> BT;
const int N = 7007;
int mu[N];
BT bt[N], st[100011], divs[N]; 
int main() {
	int LIM = 7000;
  for(int i(1); i <= LIM; i++) {
    int x = i;
    mu[i] = 1;
    for(int j(2); j * j <= i; j++) {
      if(i % j == 0) {
        int cnt = 0;
        while(x % j == 0) {
          x /= j;
          cnt++;
        }
        if(cnt > 1) mu[i] = 0;
        else mu[i] *= -1;
      }
    }
    if(x != 1) mu[i] *= -1;
  
    for(int j(1); j <= i; j++) {
      if(i % j == 0) {
        divs[i].set(j);
      }
    }
  }
  for(int i(1); i <= LIM; i++) {
    for(int j(1); j * i <= LIM; j++) {
      if(mu[j] != 0) bt[i][j * i] = 1;
    }
  }
  int n, m;
  scanf("%d%d", &n, &m);
  string ans;
  for(int i(1); i <= m; i++) {
    int tp;
    scanf("%d", &tp);
    if(tp == 1) {
      int x, v;
      scanf("%d%d", &x, &v);
      st[x] = divs[v];
    }else if(tp == 2) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      st[x] = st[y] ^ st[z];
    }else if(tp == 3) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      st[x] = st[y] & st[z];
    }else {
      int x, v;
      scanf("%d%d", &x, &v);
      ans.push_back((st[x] & bt[v]).count() % 2 + '0');
    }
  }
  cout << ans << endl;
}
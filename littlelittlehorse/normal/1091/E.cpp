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
const int N = 500033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int a[N];
LL s[N], cr[N], cl[N];
int main() {
	int n;
  scanf("%d", &n);
  for(int i(1); i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + 1 + n);
  reverse(a + 1, a + 1 + n);
  for(int i(1); i <= n; i++) {
    s[i] = s[i - 1] + a[i];
  }
  int ptr = n;
  int flag = true;
  for(int i(1); i <= n; i++) {
    if(ptr < i) ptr = i;
    while(ptr > i && a[ptr] <= i) ptr--;
    cr[i] = s[i] - i * (i - 1ll) - (s[n] - s[ptr]) - i * (LL)(ptr - i);
//    printf("%d %d\n", i, cr[i]);
    if(i < cr[i]) {flag = false; break;}
  }
  if(!flag) {
    printf("-1\n");
    return 0;
  }
  for(int i(1); i <= n; i++) {
    cr[i] = max(cr[i - 1], cr[i]);
  }
  ptr = n;
  for(int i(0); i <= n; i++) {
    if(ptr < i) ptr = i;
    while(ptr > (i) && a[ptr] <= i + 1) ptr--;
    cl[i] = (i + 1ll) * i + (s[n] - s[ptr]) + (i + 1ll) * (ptr - i) - s[i];
 //   printf("%d %d\n", i, cl[i]);
  }
  for(int i(n - 1); i >= 0; i--) {
    cl[i] = min(cl[i + 1], cl[i]);
  }
  ptr = 1;
  cr[0] = -1;
  cl[n] = n + 1;
  vector<int> vec;
  for(int cur = n; cur >= 0; cur--) {
    while(ptr <= n && cur < a[ptr]) ptr++;
    if(cur >= cr[ptr - 1] && cur <= cl[ptr - 1] && cur % 2 == s[n] % 2) vec.push_back(cur);
  }
  reverse(vec.begin(), vec.end());
  if(vec.empty()) {
    printf("-1\n");
  }else {
    for(int i(0); i < (int)vec.size(); i++) {
      printf("%d%c", vec[i], i == (int)vec.size() ? '\n' : ' ');
    }
  }
}
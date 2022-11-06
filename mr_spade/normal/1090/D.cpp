#include <bits/stdc++.h>
using namespace std;

const int N = 101010;

int n, m, a[N], b[N];
vector<int> g[N];

int main(void) {
  scanf("%d%d", &n, &m);
  for(int i = 1, x, y; i <= m; i++) {
    scanf("%d%d", &x, &y);
    if(x > y) {
      swap(x, y);
    }
    g[y].push_back(x);
  }
  for(int i = 1; i <= n; i++) {
    sort(g[i].begin(), g[i].end());
    a[i] = b[i] = i;
  }
  bool flg = 0;
  for(int i = n; !flg && i >= 1; i--) {
    int now = i - 1;
    for(int j = g[i].size() - 1; ~j; j--, now--) {
      if(g[i][j] != now) {
	break;
      }
    }
    if(now) {
      flg = 1;
      //cerr << i << " " << now << endl;
      for(int j = now + 1; j <= i; j++) {
	if(j >= i - j + now + 1) {
	  break;
	}
	swap(a[j], a[i - j + now + 1]);
	swap(b[j], b[i - j + now + 1]);
      }
      b[i] = now;
    }
  }
  if(!flg) {
    puts("NO");
  } else {
    puts("YES");
    for(int i = 1; i <= n; i++) {
      printf("%d ", a[i]);
    }
    puts("");
    for(int i = 1; i <= n; i++) {
      printf("%d ", b[i]);
    }
  }
  return 0;
}
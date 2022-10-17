#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef pair<int,int> pii;

template<class T>
inline void minimize(T& a, const T& b) { if (b < a) { a = b; } }

const int N = 2100, infty = 1000000000;
int n,s,a[N],x[N],xn,vis[N];
pii dp2[N];
pair<int,pii> cost[N][N];
pair<int,pair<pii,int> > dp[N];

int nxt(int i) { return (i+1)%n; }
int nxt(int i, int val) {
  i = nxt(i);
  while (a[i] != val) i = nxt(i);
  return i;
}
int prv(int i) { return (i+n-1)%n; }
int prv(int i, int val) {
  i = prv(i);
  while (a[i] != val) i = prv(i);
  return i;
}
int dist(int i, int j) { return j>=i ? j-i : n+j-i; }
int advanc(int i, int s) { return (i+n+s)%n; }

int main() {
  scanf("%d%d",&n,&s); --s;
  REP(i,n) { scanf("%d",&a[i]); x[i] = a[i]; }
  sort(x,x+n);
  xn = unique(x,x+n) - x;

  REP(i,n) dp[i].first = dp2[i].first = infty;
  REP(i,n) REP(j,n) cost[i][j].first = infty;

  REP(_val,xn) {
    int val = x[xn-1-_val];
    int valnxt = x[xn-_val];

    REP(i,n) if (a[i] == val) {
      if (_val == 0) {
        dp2[i].first = 0;
      } else {
        int j = nxt(i,valnxt);
        minimize(dp2[i], make_pair(dist(i,j) + dp[j].first, dist(i,j)));
        j = prv(i,valnxt);
        minimize(dp2[i], make_pair(dist(j,i) + dp[j].first, -dist(j,i)));
      }
    }

    REP(i,n) if (a[i] == val) {
      int i2 = i;
      int i3 = nxt(i,val);

      do {
        minimize(cost[i][i2], make_pair(dist(i,i2) + 2*dist(i3,i), make_pair(-dist(i3,i), dist(i3,i2))));
        minimize(cost[i][i3], make_pair(dist(i3,i) + 2*dist(i,i2), make_pair(dist(i,i2), -dist(i3,i2))));
        i2 = i3;
        i3 = nxt(i3,val);
      } while (i2 != i);
    }

    REP(i,n) if (a[i] == val) {
      int i2 = i;

      do {
        minimize(dp[i], make_pair(cost[i][i2].first + dp2[i2].first, make_pair(cost[i][i2].second, dp2[i2].second)));
        i2 = nxt(i2,val);
      } while (i2 != i);
    }
  }

  pii ans;
  ans.first = infty;
  if (a[s] == x[0]) {
    ans = make_pair(dp[s].first, 0);
  } else {
    int j = nxt(s,x[0]);
    minimize(ans, make_pair(dist(s,j) + dp[j].first, dist(s,j)));
    j = prv(s,x[0]);
    minimize(ans, make_pair(dist(j,s) + dp[j].first, -dist(j,s)));
  }

  printf("%d\n",ans.first);
  printf("%+d\n",ans.second);
  int j = advanc(s, ans.second);
  vis[j] = 1;
  REP(_val,xn) {
    int val = x[_val];

    int steps[3] = { dp[j].second.first.first, dp[j].second.first.second, dp[j].second.second };

    int step = 0;
    REP(i,3) {
      int delta = steps[i] < 0 ? -1 : 1;
      REP(_,abs(steps[i])) {
        j = advanc(j, delta);
        step += delta;
        if (a[j] == val && !vis[j]) {
          vis[j] = 1;
          printf("%+d\n", step);
          step = 0;
        }
      }

      if (i==1) val = x[_val+1];
    }
  }
}
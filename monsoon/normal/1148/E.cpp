#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef pair<int,int> pii;

const int N=5*310000;
int n,x,ans;
set<pii> a,b;
int ans_a[N],ans_b[N],ans_c[N];

void move(int a, int b, int c) {
  ans_a[ans] = a;
  ans_b[ans] = b;
  ans_c[ans] = c;
  ++ans;
}

int main() {
  scanf("%d",&n);
  REP(i,n) { scanf("%d",&x); a.insert(make_pair(x, i)); }
  REP(i,n) { scanf("%d",&x); b.insert(make_pair(x, i)); }
  vector<pii> A(a.begin(), a.end());
  vector<pii> B(b.begin(), b.end());
  vector<int> S;

  int ok=1;
  REP(i,n) {
    if (A[i].first == B[i].first) {
    } else if (A[i].first < B[i].first) {
      S.push_back(i);
    } else {
      int moje = A[i].first - B[i].first;
      while (moje > 0) {
        if (S.empty()) { ok = 0; break; }
        int si = S.back();
        int d = min(B[si].first - A[si].first, moje);
        A[si].first += d;
        move(A[si].second, A[i].second, d);
        if (B[si].first == A[si].first) {
          S.pop_back();
        }
        moje -= d;
      }
    }
  }

  if (!S.empty()) { ok = 0; }

  if (!ok) {
    puts("NO");
  } else {
    puts("YES");
    printf("%d\n", ans);
    REP(i,ans) { printf("%d %d %d\n",ans_a[i]+1,ans_b[i]+1,ans_c[i]); }
  }
}
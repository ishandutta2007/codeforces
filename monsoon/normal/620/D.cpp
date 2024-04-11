#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef long long ll;
typedef pair<ll,int> pii;

const int N = 2100;
int n,m,a[N],b[N],nA,nB;
ll sa,sb,ans;
int cnt,ansa[2],ansb[2];
pii A[N*N],B[N*N];

int main() {
  scanf("%d",&n);
  REP(i,n) { scanf("%d",&a[i]); sa += a[i]; }
  scanf("%d",&m);
  REP(i,m) { scanf("%d",&b[i]); sb += b[i]; }
  ans = abs(sa-sb);
  cnt = 0;

  REP(i,n) REP(j,m) {
    ll s = sa - sb - 2*a[i] + 2*b[j];
    if (abs(s) < ans) {
      ans = abs(s);
      cnt = 1;
      ansa[0] = i;
      ansb[0] = j;
    }
  }

  REP(i,n) REP(j,i) { A[nA++] = make_pair(a[i] + a[j], i*N+j); }
  REP(i,m) REP(j,i) { B[nB++] = make_pair(b[i] + b[j], i*N+j); }

  sort(B,B+nB);

  REP(i,nA) {
    ll fs = -(sa - sb - 2LL*A[i].first)/2;

    int pos = lower_bound(B,B+nB,make_pair(fs,0)) - B;
    for(int j=max(0,pos-2); j<min(nB,pos+3); ++j) {
      ll s = sa - sb - 2LL*A[i].first + 2LL*B[j].first;

      if (abs(s) < ans) {
        ans = abs(s);
        cnt = 2;
        ansa[0] = A[i].second/N; ansa[1] = A[i].second%N;
        ansb[0] = B[j].second/N; ansb[1] = B[j].second%N;
      }
    }
  }

  printf("%lld\n%d\n",ans,cnt);
  REP(i,cnt) {
    printf("%d %d\n",ansa[i]+1,ansb[i]+1);
  }
}
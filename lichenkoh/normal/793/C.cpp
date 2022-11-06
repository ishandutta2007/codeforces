#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
struct rational_t { ll nu, de;
  rational_t(const ll &n = 0, const ll &d = 1) {
    ll g = __gcd(abs(n), abs(d)); nu = n / g; de = d / g;
    if (de < 0) { nu = -nu; de = -de; } }
  rational_t operator+(const rational_t& b) const
  { return rational_t( nu*b.de+de*b.nu, de*b.de ); }
  rational_t operator-(const rational_t& b) const
  { return rational_t( nu*b.de-de*b.nu, de*b.de ); }
  rational_t operator-() { return rational_t(-nu, de); }
  rational_t operator*(const rational_t& b) const
  { return rational_t( nu*b.nu, de*b.de ); }
  rational_t operator/(const rational_t& b) const
  { return rational_t( nu*b.de, de*b.nu ); }
  bool operator== (const rational_t & b) const {return nu * b.de == b.nu * de;}
  bool operator== (const int &k) const { return nu == k * de; }
  bool operator< (const rational_t& b) const { return nu * b.de < b.nu * de; }
  bool operator> (const rational_t& b) const { return nu * b.de > b.nu * de; }
};
typedef rational_t rat;
const int OK=0,NO=1,ALL=2;
pair<pair<rat,rat>, int> one_coord(ll ix, ll dx, ll xlo, ll xhi) {
  if (dx==0) {
    //printf("dx:%d xlo:%d xhi:%d\n",dx,xlo,xhi);
    if (xlo<ix&&ix<xhi) return MP(MP(rat(1,1),rat(1,1)),ALL);
    else return MP(MP(rat(1,1),rat(1,1)),NO);
  }
  rat lo=rat((xlo-ix),dx);
  rat hi=rat((xhi-ix),dx);
  return MP(MP(min(lo,hi),max(lo,hi)),OK);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  rat lo=rat(-INF,1);
  rat hi=rat(INF,1);
  int n; scanf("%d",&n);
  ll xlo[2],xhi[2];
  scanf("%lld %lld %lld %lld",&xlo[0],&xlo[1],&xhi[0],&xhi[1]);
  for (int i=0;i<n;i++) {
    ll ix[2],dx[2];
    scanf("%lld %lld %lld %lld",&ix[0],&ix[1],&dx[0],&dx[1]);
    for (int t=0;t<2;t++) {
      auto got=one_coord(ix[t], dx[t], xlo[t], xhi[t]);
      if (got.snd==NO) {printf("-1\n"); return 0;}
      if (got.snd==OK) {
        //printf("%lld/%lld. %lld/%lld\n",got.fst.fst.nu,got.fst.fst.de,got.fst.snd.nu,got.fst.snd.de);
        chkmax(lo,got.fst.fst);
        chkmin(hi,got.fst.snd);
      }
    }
  }
  chkmax(lo,rat(0,1));
  if (lo<hi) {
    ld final=((ld)lo.nu)/((ld)lo.de);
    printf("%.15f\n",(double)final);
  }
  else printf("-1\n");
}
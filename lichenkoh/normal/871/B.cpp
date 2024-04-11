#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

int query(int x, int y) {
  int ans;
  printf("? %d %d\n",x,y);
  fflush(stdout);
  scanf("%d",&ans);
  return ans;
}
void bang(int sols, const vector<int> &sol) {
  printf("!\n%d\n",sols);
  for (auto &w:sol) {
    printf("%d ",w);
  }
  printf("\n");
  fflush(stdout);
}
int n;
const int mn=5000+4;
int vgot1[mn];
vector<int> b;
bool vcheck(const vector<int> &p) {
  //if (n==1) return true;
  for (int x=0;x<n;x++) b[p[x]]=x;
  for (int y=0;y<n;y++) {
    if ((p[y]^b[0])!=vgot1[y]) {
      //printf("y:%d p1:%d by:%d vgot1:%d\n",y,p[1],b[y],vgot1[y]);
      return false;
    }
  }
  return true;
}

bitset<mn> s;
int vgot[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  scanf("%d",&n);
  b.resize(n);
  int sols=0; vector<int> vfinal;
  for (int y=0;y<n;y++) {
    vgot[y]=query(0,y);
  }

  for (int y=0;y<n;y++) {
    vgot1[y]=query(y,0);
  }

  vector<int> vans;
  for (int y=0;y<n;y++) {
    if (vgot[y]==y) {
      vans.resize(n);
      bool ok=1;
      for (int x=0;x<n;x++) {
        int z=vgot[x]^y;
        if (!(0<=z&&z<n)) {ok=0; break;}
        vans[z]=x;
      }
      if (ok) {
        s.reset();
        for (int x = 0; x < n; x++) s[vans[x]]=true;
        //for (int x = 0; x < n; x++) printf("%d ",vans[x]);
        //printf(" end y:%d\n",y);
        if (s.count() == n && vcheck(vans)) {
          vfinal = vans;
          sols++;
        }
      }
    }
  }
  bang(sols, vfinal);
}
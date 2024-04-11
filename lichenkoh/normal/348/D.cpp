#include <bits/stdc++.h>
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
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mn=3004;
char a[mn][mn];
int total[mn][mn];
int xlim,ylim;
inline void normp(int &x) {
	if (x>=MOD) x-=MOD;
}
inline void normn(int &x) {
	if (x<0) x+=MOD;
}
inline bool valid(int x, int y) {
	return 0<=x&&x<xlim&&0<=y&&y<ylim&&a[x][y]!='#';
}

ll f(pii s, pii t) {
	memset(total,0,sizeof total);
	int sx=s.fst,sy=s.snd;
	int tx=t.fst,ty=t.snd;
	if (!(valid(sx,sy)&&valid(tx,ty))) return 0;
  total[sx][sy]=1;
  for (int x=sx;x<=tx;x++) {
  	for (int y=sy;y<=ty;y++) {
      if (valid(x,y)) {
      	if (valid(x+1,y)) {total[x+1][y]+=total[x][y]; normp(total[x+1][y]);}
        if (valid(x,y+1)) {total[x][y+1]+=total[x][y]; normp(total[x][y+1]);}
      }
    }
  }
  return total[tx][ty];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d %d\n",&xlim,&ylim);
  for (int x=0;x<xlim;x++) {
    scanf("%s\n",a[x]);
  }
  pii a1=MP(0,1);
  pii b1=MP(xlim-2,ylim-1);
  pii a2=MP(1,0);
  pii b2=MP(xlim-1,ylim-2);
  ll ans=f(a1,b1)*f(a2,b2)-f(a1,b2)*f(a2,b1);
  ans%=MOD;
  if (ans<0) ans+=MOD;
  printf("%lld\n",ans);
}
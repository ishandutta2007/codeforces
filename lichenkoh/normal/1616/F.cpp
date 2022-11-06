#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,avx2")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

template <uint MD> struct ModInt {
    using M = ModInt;
    const static M G;
    uint v=0;
    ModInt(ll _v = 0) { set_v(_v % MD + MD); }
    M& set_v(uint _v) {
        v = (_v < MD) ? _v : _v - MD;
        return *this;
    }
    explicit operator bool() const { return v != 0; }
    M operator-() const { return M() - *this; }
    M operator+(const M& r) const { return M().set_v(v + r.v); }
    M operator-(const M& r) const { return M().set_v(v + MD - r.v); }
    M operator*(const M& r) const { return M().set_v(ull(v) * r.v % MD); }
    M operator/(const M& r) const { return *this * r.inv(); }
    M& operator+=(const M& r) { return *this = *this + r; }
    M& operator-=(const M& r) { return *this = *this - r; }
    M& operator*=(const M& r) { return *this = *this * r; }
    M& operator/=(const M& r) { return *this = *this / r; }
    bool operator==(const M& r) const { return v == r.v; }
    M pow(ll n) const {
        M x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    M inv() const { return pow(MD - 2); }
    friend ostream& operator<<(ostream& os, const M& r) { return os << r.v; }
};
using Mint = ModInt<3>;
template<> const Mint Mint::G = Mint(2);

template <class D> struct Mat : VV<D> {
    using VV<D>::VV;
    using VV<D>::size;
    int h() const { return int(size()); }
    int w() const { return int((*this)[0].size()); }
    Mat operator*(const Mat& r) const {
        assert(w() == r.h());
        Mat res(h(), V<D>(r.w()));
        for (int i = 0; i < h(); i++) {
            for (int j = 0; j < r.w(); j++) {
                for (int k = 0; k < w(); k++) {
                    res[i][j] += (*this)[i][k] * r[k][j];
                }
            }
        }
        return res;
    }
    Mat& operator*=(const Mat& r) { return *this = *this * r; }
    Mat pow(ll n) const {
        assert(h() == w());
        Mat x = *this, r(h(), V<D>(w()));
        for (int i = 0; i < h(); i++) r[i][i] = D(1);
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
};

template <class Mint> VV<Mint> solve_linear(Mat<Mint> a, V<Mint> b) {
    int h = a.h(), w = a.w();
    assert(int(b.size()) == h);
    int r = 0;
    V<bool> used(w);
    V<int> idxs;
    for (int x = 0; x < w; x++) {
        int my = -1;
        for (int y = r; y < h; y++) {
            if (a[y][x]) {
                my = y;
                break;
            }
        }
        if (my == -1) continue;
        if (r != my) swap(a[r], a[my]);
        swap(b[r], b[my]);
        for (int y = r + 1; y < h; y++) {
            if (!a[y][x]) continue;
            auto freq = a[y][x] / a[r][x];
            for (int k = x; k < w; k++) a[y][k] -= freq * a[r][k];
            b[y] -= freq * b[r];
        }
        r++;
        used[x] = true;
        idxs.push_back(x);
        if (r == h) break;
    }
    for (int y = r; y < h; y++) {
        if (b[y]) return {};
    }
    VV<Mint> sols;
    {
        V<Mint> v(w);
        for (int y = r - 1; y >= 0; y--) {
            int f = idxs[y];
            v[f] = b[y];
            for (int x = f + 1; x < w; x++) {
                v[f] -= a[y][x] * v[x];
            }
            v[f] /= a[y][f];
        }
        sols.push_back(v);
    }
    for (int s = 0; s < w; s++) {
        if (used[s]) continue;
        V<Mint> v(w);
        v[s] = Mint(1);
        for (int y = r - 1; y >= 0; y--) {
            int f = idxs[y];
            for (int x = f + 1; x < w; x++) {
                v[f] -= a[y][x] * v[x];
            }
            v[f] /= a[y][f];
        }
        sols.push_back(v);
    }
    return sols;
}


const int mn=64;
int g[mn][mn];
void go() {
  memset(g,-1,sizeof g);
  int n,m;cin>>n>>m;
  vi val(m);
  Mat<Mint> M; V<Mint> vec;
  for (int i=0;i<m;i++) {
    int x,y,k; cin>>x>>y>>k;
    --k; --x; --y;
    g[x][y]=i;
    g[y][x]=i;
    //printf("x: %d %d %d\n",x,y,i);
    val[i]=k;
    if (k!=-2) {
      V<Mint> v(m);
      v[i]=1;
      M.PB(v);
      vec.PB(Mint(k));
      //printf("i:%d k:%d\n",i,k);
    }
  }
  for (int x=0;x<n;x++) {
    for (int y=0;y<x;y++) {
      for (int z=0;z<y;z++) {
        int a=g[x][y],b=g[y][z],c=g[z][x];
        if (a!=-1&&b!=-1&&c!=-1) {
          V<Mint> v(m);
          v[a]=1; v[b]=1; v[c]=1;
          M.PB(v);
          vec.PB(Mint(0));
          //printf("abc: %d %d %d\n",a,b,c);
        }
      }
    }
  }
  if (M.size()==0) {
    for (int i=0;i<m;i++) {
      int ans=val[i];
      if (ans==-2) ans=0;
      printf("%d ",ans+1);
    }
    printf("\n");
    return;
  }
  auto answer = solve_linear(M, vec);
  if (answer.empty()) {
      printf("-1\n");
      return;
  } else {
    for (int i=0;i<m;i++) {
      int ans=answer[0][i].v+1;
      if (ans==0) ans+=3;
      printf("%d ",ans);
    }
    printf("\n");
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin>>t; for (int i=0;i<t;i++) go();
}




static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}

int rint()
{
    readAhead(16);

    int x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}
char rch()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
long long rlong()
{
    readAhead(32);

    long long x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}
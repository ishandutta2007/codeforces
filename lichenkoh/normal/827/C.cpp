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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
inline int rri()
{
  char c;
  while (c = getchar(), c <= ' ');
  bool sign = c == '-';
  if (sign)
  {
      c = getchar();
  }
  int res = c - '0';
  while (c = getchar(), c >= '0' && c <= '9')
  {
    res = res * 10 + (c - '0');
  }
  // One character is gobbled here
  return sign ? -res : res;
}
inline ll rrl()
{
  char c;
  while (c = getchar(), c <= ' ');
  bool sign = c == '-';
  if (sign)
  {
      c = getchar();
  }
  ll res = c - '0';
  while (c = getchar(), c >= '0' && c <= '9')
  {
    res = res * 10 + (c - '0');
  }
  // One character is gobbled here
  return sign ? -res : res;
}
inline char rrc()
{
  char c;
  while (c = getchar(), c <= ' ');
  return c;
}
inline int rrs(char *target) {
  char c;
  while (c = getchar(), c <= ' ');
  int idx=-1;
  target[++idx]=c;
  while(1) {
  	c=getchar();
  	if (c<=' '){
  		target[++idx]='\0';
  		return idx;
  	}
  	target[++idx]=c;
  }
}
const int mn=1e5+4;
const int MAXSEG = mn;  // limit for array size
typedef int S;
S identity = 0;
S combine(const S& lefts, const S& rights) {
  return lefts+rights;
}
void build(S *t, int n) {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
}

void modify(S *t, int n, int p, const S& valuee) { // set value at position p
  int val=valuee+t[p+n];
  for (t[p += n] = val; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}

S query(S *t, int n, int l, int r) { // sum on interval [l, r]
  r++;
  S resl=identity, resr=identity;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]);
    if (r&1) resr = combine(t[--r], resr);
  }
  return combine(resl, resr);
}

S *t[11][11][4];
int vsegn[11];
void init(int an) {
  for (int p=1;p<=10;p++) {
    int n=((an+p-1)/p)+1;
    vsegn[p]=n;
    for (int o=0;o<p;o++) {
      for (int c=0;c<4;c++) {
        int sz=2*(n+1);
        t[p][o][c]= new S[sz];
        for (int i=0;i<sz;i++) t[p][o][c][i]=0;
      }
    }
  }
}

void putch(int an, int x, int c) {
  for (int p=1;p<=10;p++) {
    int o=x%p; // OPT!!
    int y=x/p;
    int segn=vsegn[p];
    t[p][o][c][segn+y]++;
  }
}
void modch(int an, int x, int oldc, int newc) {
  for (int p=1;p<=10;p++) {
    int o=x%p; // OPT!!
    int y=x/p;
    int segn=vsegn[p];
    modify(t[p][o][oldc],segn,y,-1);
    modify(t[p][o][newc],segn,y,1);
  }
}
int ask(int an, int p, int al, int ar, int c) {
  if (al>ar) return 0;
  int o=al%p;
  int L=al/p;
  int len=(ar-al+1+p-1)/p;
  int R=L+len-1;
  if (L>R) return 0;
  return query(t[p][o][c],vsegn[p],L,R);
}
char s[mn];
char e[mn];
int lbl[256];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  lbl['A']=0;
  lbl['T']=1;
  lbl['C']=2;
  lbl['G']=3;
  int an=rrs(s);
  init(an);
  for (int i=0;i<an;i++) {
    int c=lbl[s[i]];
    putch(an,i,c);
  }
  for (int p=1;p<=10;p++) {
    for (int o=0;o<p;o++) {
      for (int c=0;c<4;c++) build(t[p][o][c],vsegn[p]);
    }
  }
  int q=rri();
  for (int i=0;i<q;i++) {
    int qt=rri();
    if (qt==1) {
      int x=rri(); char c=rrc();
      --x;
      char oldc=lbl[s[x]];
      modch(an,x,oldc,lbl[c]);
      s[x]=c;
    }
    else {
      int l=rri(),r=rri(); int p=rrs(e);
      --l; --r;
      int final=0;
      for (int x=0;x<p;x++) {
        int c=lbl[e[x]];
        int got=ask(an,p,l+x,r,c);
        final+=got;
      }
      printf("%d\n",final);
    }
  }
}
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,unsafe-math-optimizations")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
#include <immintrin.h>
#include <emmintrin.h>
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
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

const int mn=100000;
//const int mn=10;
const int R=sqrt(mn);
const int mk=5;
bitset<mn> orig[mk][2];
bitset<mn> b;
/* KMP from UBC2012 bookcode */
// t is the string to search in, p is the substring to search for
int fail[mn+1];
void kmp_init(const char *p, const int plen) {
  for (int i=0, j=-1, m=plen; ; ++i, ++j) {
    fail[i] = j; if (i == m) return;
    while (j>=0 && p[i]!=p[j]) j = fail[j];
} } // fail[i] = len of longest proper suffix that's also a prefix in s[0...i-1]
int kmp_match(const char *t, const int tlen, const char *p, const int plen) {
  int n=tlen,m=plen;
  kmp_init(p,m);
  int matches=0;
  for (int i=0, j=0; ; ++i, ++j) {
    if (j == m) matches++, j = fail[j];
    if (i == n) return matches;
    while (j>=0 && t[i]!=p[j]) j = fail[j]; }
  return matches;
}
/* End KMP from UBC2012 bookcode */

char str[mn+1];
char q[mn+1];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  scanf("%s\n",str); int slen=strlen(str);
  {
    int t=0;
    for (int k=0;k<mk;k++) {
      for (int x=0;x<slen;x++) {
        int c=str[x]-'a'+1;
        orig[k][0][x]=(c>>k)&1;
      }
      orig[k][1]=orig[k][0];
      orig[k][1].flip();
    }
  }

  int qlim; scanf("%d\n",&qlim);
  for (int qi=0;qi<qlim;qi++) {
    char t; scanf("%c ",&t);
    if (t=='1') {
      int p; char c; scanf("%d %c\n",&p,&c); --p;
      str[p]=c;
      c=c-'a'+1;
      for (int k=0;k<mk;k++) {
        bool bit=(c>>k)&1;
        orig[k][0][p]=bit;
        orig[k][1][p]=!bit;
      }
    }
    else {
      int l,r; scanf("%d %d %s\n",&l,&r,q); --l; --r;
      int qlen=strlen(q);
      int ans=0;
      if (r-l+1>=qlen) {
        if (qlen<=R) {
          for (int x=0;x<qlen;x++) q[x]=q[x]-'a'+1;
          b.reset();
          for (int k=0;k<5;k++) {
            for (int x=0;x<qlen;x++) {
              bool c=(q[x]>>k)&1;
              b|=(orig[k][c]>>x);
              //cout<<k<<" x:"<<x<<" b:"<<b<<endl;
            }
          }
          //cout<<"all"<<(r-qlen+1-l+1)<<endl;
          ans=(r-qlen+1-l+1)-((b>>l).count() - (b>>(r-qlen+2)).count());
        }
        else {
          ans=kmp_match(str+l,r-l+1,q,qlen);
        }
      }
      printf("%d\n",ans);
    }
  }
}

/*
inline int read_char() {
  static char buf[1 << 16], *ptr = buf, *end_ptr = buf;
  if (ptr == end_ptr) {
    int len = fread(buf, 1, sizeof(buf), stdin);
    if (len <= 0) return EOF;
    ptr = buf;
    end_ptr = buf + len;
  }
  return *ptr++;
}

inline int rint() {
  int ch; bool sg = 0;
  do {
    ch = read_char();
    if (ch == '-') sg = 1;
  } while (ch < '0' || ch > '9');
  int x = ch - '0';
  while (true) {
    ch = read_char();
    if (ch < '0' || ch > '9') break;
    x = x * 10 + ch - '0';
  }
  return (sg?-x:x);
}
*/
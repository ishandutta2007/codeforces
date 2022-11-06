#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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




const int mn=(1e5)+2;

const int MAXN=mn; // >= 256

ll sumc2=0;
ll c2(ll x) {
  return ((x+1)*x)/2;
}
const int mx=mn;
class UnionFind {
  typedef int UFTYPE;
public:
  UFTYPE ufIdentity = 0;
  inline UFTYPE combine(UFTYPE x, UFTYPE y) {
    sumc2-=c2(x);sumc2-=c2(y);
    sumc2+=c2(x+y);
    return x+y;
  }
  inline UFTYPE getInitialValue(int x) {
    return 0;
  }
  int ufParent[mx];
  int rank[mx];
  UFTYPE ufData[mx];
  inline void ufreset(int x) {
    ufParent[x]=x;
    ufData[x]=getInitialValue(x);
    rank[x]=0;
  }
  void init(int n) {
    for (int x=0;x<n;x++) {
      ufreset(x);
    }
  }
  int ffind(int x) {
    if (ufParent[x] != x) {
      ufParent[x] = ffind(ufParent[x]);
    }
    return ufParent[x];
  }
  void funion(int _x, int _y) {
    int xr = ffind(_x);
    int yr = ffind(_y);
    if (xr==yr) return;
    if (rank[xr] > rank[yr]) swap(xr,yr);
    if (rank[xr]==rank[yr]) rank[yr]++;
    ufParent[xr] = yr;
    ufData[yr]=combine(ufData[xr],ufData[yr]);
  }
  int getDataForPos(int x) {
    return ufData[x];
  }
  void inc(int _x) {
    int x=ffind(_x);
    sumc2-=c2(ufData[x]);
    ++ufData[x];
    sumc2+=c2(ufData[x]);
  }
};




class DC3Algorithm {
  private: 
  // lexicographic order for pairs
  inline bool leq(int a1, int a2, int b1, int b2) {
      return(a1 < b1 || a1 == b1 && a2 <= b2);
  }
   
  // and triples
  inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
      return(a1 < b1 || a1 == b1 && leq(a2,a3, b2,b3));
  } // and triples
   
  // stably sort a[0..n-1] to b[0..n-1] with keys in 0..K from r
  static void radixPass(int* a, int* b, int* r, int n, int K) {// count occurrences
      int* c = new int[K + 1]; // counter array
      for (int i = 0; i <= K; i++) c[i] = 0; // reset counters
      for (int i = 0; i < n; i++) c[r[a[i]]]++; // count occurrences
      for (int i = 0, sum = 0; i <= K; i++) // exclusive prefix sums
      {
          int t = c[i];
          c[i] = sum;
          sum += t;
      }
      for (int i = 0;  i < n; i++) b[c[r[a[i]]]++] = a[i]; // sort
      delete [] c;
  }
   
  // find the suffix array SA of s[0..n-1] in {1..K}n
  // require s[n]=s[n+1]=s[n+2]=0, n>=2
  void suffixArray(int* s, int* SA, int n, int K) {
    assert(n>=2);
      int n0 = (n+2)/3, n1 = (n+1)/3, n2 = n/3, n02 = n0+n2;
      int* s12 = new int[n02+3]; s12[n02] = s12[n02+1] = s12[n02+2] = 0;
      int* SA12 = new int[n02+3]; SA12[n02] = SA12[n02+1] = SA12[n02+2] = 0;
      int* s0 = new int[n0];
      int* SA0 = new int[n0];
      // generate positions of mod 1 and mod 2 suffixes
      // the "+(n0-n1)" adds a dummy mod 1 suffix if n%3 == 1
      for (int i=0, j=0; i < n + (n0-n1); i++)
          if (i%3 != 0) s12[j++] = i;
      // lsb radix sort the mod 1 and mod 2 triples
      radixPass(s12 , SA12, s+2, n02, K);
      radixPass(SA12, s12 , s+1, n02, K);
      radixPass(s12 , SA12, s  , n02, K);
      // find lexicographic names of triples
      int name = 0, c0 = -1, c1 = -1, c2 = -1;
      for (int i = 0; i < n02; i++) {
          if (s[SA12[i]] != c0 || s[SA12[i]+1] != c1 || s[SA12[i]+2] != c2) {
              name++;
              c0 = s[SA12[i]];
              c1 = s[SA12[i]+1];
              c2 = s[SA12[i]+2];
          }
          if (SA12[i]%3 == 1) s12[SA12[i]/3] = name; // left half
          else s12[SA12[i]/3 + n0] = name; // right half
      }
      // recurse if names are not yet unique
      if (name < n02) {
          suffixArray(s12, SA12, n02, name);
          // store unique names in s12 using the suffix array
          for (int i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
      } else // generate the suffix array of s12 directly
          for (int i = 0;  i < n02; i++) SA12[s12[i] - 1] = i;
      // stably sort the mod 0 suffixes from SA12 by their first character
      for (int i = 0, j = 0; i < n02; i++)
          if (SA12[i] < n0) s0[j++] = 3*SA12[i];
      radixPass(s0, SA0, s, n0, K);
      // merge sorted SA0 suffixes and sorted SA12 suffixes
      for (int p = 0, t = n0-n1, k = 0; k < n; k++) {
          #define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)
          int i = GetI(); // pos of current offset 12 suffix
          int j = SA0[p]; // pos of current offset 0 suffix
          if (SA12[t] < n0 ? // different compares for mod 1 and mod 2 suffixes
              leq(s[i], s12[SA12[t] + n0], s[j], s12[j/3]) :
              leq(s[i],s[i+1],s12[SA12[t]-n0+1], s[j],s[j+1],s12[j/3+n0]))
          {// suffix from SA12 is smaller
              SA[k] = i; t++;
              if (t == n02) // done --- only SA0 suffixes left
              for (k++; p < n0; p++, k++) SA[k] = SA0[p];
          } else {// suffix from SA0 is smaller
              SA[k] = j; p++;
              if (p == n0) // done --- only SA12 suffixes left
              for (k++; t < n02; t++, k++) SA[k] = GetI();
          }
      }
      delete [] s12; delete [] SA12; delete [] SA0; delete [] s0;
  }
  void realSuffixArray(int* s, int* SA, int n, int K) {
    if (n==1) {
      SA[0]=0;
    }
    else if (n==2) {
          if (s[0]<s[1]) {
            SA[0]=0; SA[1]=1;
          }
          else {
            SA[0]=1; SA[1]=0;
          }
    }
    else {
      suffixArray(s,SA,n,K);
    }
  }
  int AN;
  int STR[MAXN+4];
  int SA[MAXN+4];

  void prep_string(string s) {
      AN = s.length();
      for (int i=0;i<AN;i++) {
        STR[i]=s[i]-'a'+1;
      }
      STR[AN]=STR[AN+1]=STR[AN+2]=0;
      //memset(SA,0,sizeof SA);
  }

  vector<int> REVSA;
  vector<int> LCP;
  void compute_lcp() {
    int n=AN,k=0;
    REVSA.resize(n);
    LCP.resize(n);
    for(int i=0; i<n; i++) REVSA[SA[i]]=i;
    for(int i=0; i<n; i++, k?k--:0)
    {
        if(REVSA[i]==n-1) {k=0; continue;}
        int j=SA[REVSA[i]+1];
        while(i+k<n && j+k<n && STR[i+k]==STR[j+k]) k++;
        LCP[REVSA[i]]=k;
    }
  }
  public:
    vector<int> GetLCP() {
        return LCP;
    }
    void Construct2(const char *s) {
        prep_string(s);
        realSuffixArray(STR,SA,AN,27); // 'z'+1 is used as string separator.
        // printf("%s\nslen:%d\n",s,AN);
        // for (int i=0;i<AN;i++) {printf("%d: %s\n",i,s+SA[i]);}
        compute_lcp();
    }
    void Construct(string s) {
        Construct2(s.c_str());
    }


    vector<int> GetSA() {
        vector<int> ret; ret.resize(AN);
        for (int i = 1; i <= AN; i++)
            ret[i-1]=SA[i];
        return ret;
    }
    vector<int> GetREVSA() {
        return REVSA;
    }

    UnionFind uf;
    // Trample over SA and STR to save memory
    #define vcnt SA
    #define vl STR
    //int vcnt[MAXN];
    //int vl[MAXN];
    int vidx[MAXN];
    void askLCPinit() {
      memset(vcnt,0,sizeof vcnt);
      for (int i=0;i<AN;i++) ++vcnt[LCP[i]+1];
      for (int i=1;i<=AN;i++) {
        vcnt[i]+=vcnt[i-1];
      }
      for (int i=0;i<AN;i++) {
        int lcp=LCP[i];
        vl[vidx[lcp]+vcnt[lcp]]=i;
        ++vidx[lcp];
      }
      uf.init(AN);
    }
    bool askLCPstridx(int x, int y) {
      return uf.ffind(REVSA[x])==uf.ffind(REVSA[y]);
    }
    void askLCPprocess(int lcp) {
      uf.inc(REVSA[AN-lcp]);
      int lo=vcnt[lcp],hi=vcnt[lcp+1];
      for (int i=lo;i<hi;i++) {
        int x=vl[i];
        //assert(LCP[x]==lcp);
        uf.funion(x,x+1);
      }
    }

};

DC3Algorithm g;

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s; cin>>s;
  g.Construct(s);
  int n=s.length();
  g.askLCPinit();
  ll ans=0;
  for (int lcp=n;lcp>=1;lcp--) {
    g.askLCPprocess(lcp);
    ans+=sumc2;
  }
  printf("%lld\n",ans);
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
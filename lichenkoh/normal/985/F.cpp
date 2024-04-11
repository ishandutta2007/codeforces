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

inline ll MK(ll x, ll y) {
  return (x<<32)|y;
}

int kfst(ll x) {return (x>>32);}
int ksnd(ll x) {return (x)&0xffffffff;}

const int mn=2e5+1;

const int MAXN=26*mn; // >= 256

class UnionFind {
  static const int mx=MAXN;
  typedef int UFTYPE;
public:
  int ufParent[mx];
  unsigned char rank[mx];
  void init(int n) {
    for (int x=0;x<n;x++) {
      ufParent[x]=x;
    }
    // memset(rank,0,sizeof rank); // Uncomment if you reuse.
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
  }
};

class DC3Algorithm {
  const int ALPHABET_SIZE=3; // May need to add 1 to be a string separator.
  const int START_ALPHABET='a';
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
  public:int STR[MAXN+4];
  private:
  int SA[MAXN+4];

  void prep_string(string s) {
      AN = s.length();
      for (int i=0;i<AN;i++) {
        STR[i]=s[i]-START_ALPHABET+1;
      }
      STR[AN]=STR[AN+1]=STR[AN+2]=0;
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
  //RmqSparseTable RST;
  public:
    vector<int> GetLCP() {
        return LCP;
    }
    void FastConstruct2(int n) { // Pass in string directly
      AN=n;
      STR[AN]=STR[AN+1]=STR[AN+2]=0;
      //memset(SA,0,sizeof SA); // Is this needed?
      realSuffixArray(STR,SA,AN,ALPHABET_SIZE);
      compute_lcp();
      //RST.init(LCP);
    }
    void Construct2(const char *s) {
        prep_string(s);
        //memset(SA,0,sizeof SA); // Is this needed?
        realSuffixArray(STR,SA,AN,ALPHABET_SIZE);
        compute_lcp();
        //RST.init(LCP);
    }
    void Construct(string s) {
        Construct2(s.c_str());
    }

    /*int queryLCPsaidx(int ox, int oy) {
      if (ox==oy) return AN-SA[ox];
      int x=ox,y=oy;
      if (x>=y) swap(x,y);
      return RST.minVal(x,y-1);
    }

    int queryLCPstridx(int ox, int oy) {
      int x=REVSA[ox],y=REVSA[oy];
      return queryLCPsaidx(x,y);
    }*/

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
      int lo=vcnt[lcp],hi=vcnt[lcp+1];
      for (int i=lo;i<hi;i++) {
        int x=vl[i];
        //assert(LCP[x]==lcp);
        uf.funion(x,x+1);
      }
    }
};


DC3Algorithm g;
char s[mn];
int c2pos[mn][26];
bitset<mn> vans;
int qx[mn],qy[mn];
ll szqid[mn];
int main() 
{
  //clock_t start=clock();
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,qlim; scanf("%d %d\n",&n,&qlim);
  scanf("%s\n",s);
  for (int i=0;i<n;i++) s[i]-='a';
  for (int a=0;a<26;a++) {
    for (int i=0;i<n;i++) {
      g.STR[a*(n+1)+i]=(s[i]==a)?1:2;
    }
    g.STR[a*(n+1)+n]=3;
  }
  //printf("Start suffix:%f\n",(clock()-start)/(double)CLOCKS_PER_SEC);
  g.FastConstruct2(26*(n+1)-1);
  //printf("End suffix:%f\n",(clock()-start)/(double)CLOCKS_PER_SEC);
  vans.set();
  memset(c2pos[n],-1,sizeof c2pos[n]);
  for (int x=n-1;x>=0;x--) {
    memcpy(c2pos[x],c2pos[x+1],sizeof c2pos[x]);
    c2pos[x][s[x]]=x;
  }
  //printf("Start readq:%f\n",(clock()-start)/(double)CLOCKS_PER_SEC);
  for (int q=0;q<qlim;q++) {
    int x,y,l;
    scanf("%d %d %d\n",&x,&y,&l); --x;--y;
    qx[q]=x;qy[q]=y; szqid[q]=-MK(l,q);
  }
  //printf("End readq:%f\n",(clock()-start)/(double)CLOCKS_PER_SEC);
  sort(szqid,szqid+qlim);
  //printf("Start askLCPinit:%f\n",(clock()-start)/(double)CLOCKS_PER_SEC);
  g.askLCPinit();
  //printf("End askLCPinit:%f\n",(clock()-start)/(double)CLOCKS_PER_SEC);
  int gl=n+1;
  //printf("Start query:%f\n",(clock()-start)/(double)CLOCKS_PER_SEC);
  for (int sid=0;sid<qlim;sid++) {
    ll got=-szqid[sid];
    int q=ksnd(got);
    int x=qx[q],y=qy[q],l=kfst(got);
    while(gl>l) {
      --gl;
      g.askLCPprocess(gl);
    }
    bool ans=true;
    for (int t=0;t<2;t++) {
      for (int a=0;a<26;a++) {
        int apos=c2pos[x][a];
        if (apos==-1||apos-x+1>l) continue;
        int b=s[apos-x+y];
        if (!g.askLCPstridx(a*(n+1)+x,b*(n+1)+y)) {ans=false; break;}
      }
      if (!ans) break;
      swap(x,y);
    }
    vans[q]=ans;
  }
  //printf("End query:%f\n",(clock()-start)/(double)CLOCKS_PER_SEC);
  //return 0;
  for (int q=0;q<qlim;q++) {
    if (vans[q]) printf("YES\n");
    else {
      printf("NO\n");
    }
  }
}
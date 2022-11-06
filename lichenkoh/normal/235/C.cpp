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
//int rint();char rch();long long rlong();
const int MAXSZ=(512-128)*(1<<20);
char prealloc[MAXSZ];
int preidx=0;
void * operator new(size_t size) {
  int oldidx=preidx;
  preidx+=(((int)size) + 3) & ~0x03;
  //preidx+=size;
  return (void *)(&prealloc[oldidx]);
}
void free (void* ptr) {
  return;
}

const int mn=(3e6+4);

// Linear Suffix Array O(N)

const int MAXN=mn;
/*
class RmqSparseTable {

    int* logTable;
    int** rmq;
    int n;
public:
    void init(vector<int> &a) {
      n=a.size();

      logTable = new int[n + 1];
      fill(logTable,logTable+n+1,0);
      for (int i = 2; i <= n; i++)
        logTable[i] = logTable[i >> 1] + 1;

      rmq = new int*[logTable[n] + 1];
      for (int i=0;i<logTable[n] + 1;i++) {
        rmq[i]=new int[n];
      }
      for (int i = 0; i < n; ++i)
        rmq[0][i] = a[i];

      for (int k = 1; (1 << k) < n; ++k) {
        for (int i = 0; i + (1 << k) <= n; i++) {
          int x = rmq[k - 1][i];
          int y = rmq[k - 1][i + (1 << k - 1)];
          rmq[k][i] = min(x,y);
        }
      }
    }

    int minVal(int i, int j) {
      int k = logTable[j - i];
      int x = rmq[k][i];
      int y = rmq[k][j - (1 << k) + 1];
      return min(x,y);
    }
};
*/

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


    void prep_string(char *s, int slen) {
      AN = slen;
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
    //RmqSparseTable RST;
public:
    vector<int> GetLCP() {
      return LCP;
    }
    void Construct2(char *s, int slen) {
      prep_string(s,slen);
      realSuffixArray(STR,SA,AN,27); // 'z'+1 is used as string separator.
      //printf("%s\nslen:%d\n",s,AN);
      //for (int i=0;i<AN;i++) {printf("%d: %s\n",i,s+SA[i]);}
      compute_lcp();
      //RST.init(LCP);
    }
    /*void Construct(string s) {
      Construct2(s.c_str(),s.length());
    }*/
    /*
    int queryLCPsaidx(int ox, int oy) {
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
};

const int mx=mn;
typedef int UFTYPE;
class UnionFind {
public:

// Custom
    UFTYPE ufIdentity = 0;
    inline UFTYPE combine(UFTYPE x, UFTYPE y) {
      return x+y;
    }
    /*inline UFTYPE getInitialValue(int x) {
      return x;
    }*/


    int ufParent[mx];
    int rank[mx];
    UFTYPE ufData[mx];
    inline void ufreset(int x) {
      ufParent[x]=x;
      //ufData[x]=getInitialValue(x);
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
};
int seen[mn];
DC3Algorithm dc3;
char a[mn];
UnionFind uf;
vector<int> vlen2lcp[mn];
//const int mm=mn;
//const int ms=mn;
const int mm=1e6+2;
vector<int> vlen2q[mm];
const int ms=1e5+2;
char *vt[ms];
int tlen[ms];
int vans[ms];
int vbase[ms];
char s[mm];
char tmp[mm];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  scanf("%s\n%d\n",s,&n);
  int slen=strlen(s);
  for (int i=0;i<n;i++) {
    scanf("%s",tmp);
    tlen[i]=strlen(tmp);
    vt[i]=new char[tlen[i]];
    memcpy(vt[i],tmp,sizeof(char)*tlen[i]);
  }
  for (int i=0;i<n;i++) vlen2q[tlen[i]].PB(i);
  int alen=0;
  for (int i=0;i<slen;i++) {
    a[alen++]=s[i];
  }
  a[alen++]='z'+1;
  for (int i=0;i<n;i++) {
    vbase[i]=alen;
    for (int k=0;k<tlen[i];k++) {
      a[alen++]=vt[i][k];
    }
    for (int k=0;k<tlen[i]-1;k++) {
      a[alen++]=vt[i][k];
    }
  }
  a[alen]='\0';
  dc3.Construct2(a,alen);
  vector<int> revsa=dc3.GetREVSA();
  vector<int> sa=dc3.GetSA();
  vector<int> lcp=dc3.GetLCP();
  for (int i=0;i<alen;i++) {
    vlen2lcp[lcp[i]].PB(i);
  }
  uf.init(alen);
  //memset(uf.ufData,0,sizeof uf.ufData);
  for (int x=0;x<slen;x++) {
    int saidx=revsa[x];
    uf.ufData[saidx]=1;
    //printf("saidx:%d has 1\n",saidx);
  }
  int qid=0;
  for (int len=mm-1;len>=1;len--) {
    for (auto &saidx:vlen2lcp[len]) {
      uf.funion(saidx,saidx+1);
      //printf("Merge %d %d\n",saidx,saidx+1);
    }
    for (auto &q: vlen2q[len]) {
      ++qid;
      char *t=vt[q];
      int tlenn=tlen[q];
      int apos=vbase[q];
      int ans=0;
      for (int k=0;k<tlenn;k++) {
        int saidx=revsa[apos];
        int ufid=uf.ffind(saidx);
        //printf("Query apos:%d saidx:%d ufid:%d\n",apos,saidx,ufid);
        if (seen[ufid]!=qid) {
          seen[ufid]=qid;
          ans+=uf.getDataForPos(ufid);
          //printf("Add:%d\n",uf.getDataForPos(ufid));
        }
        apos++;
      }
      vans[q]=ans;
    }
  }
  for (int q=0;q<n;q++) {
    printf("%d\n",vans[q]);
  }
}



/*
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
}*/
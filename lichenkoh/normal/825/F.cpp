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
const int mn=8004;

// Linear Suffix Array O(N)

// String index from 0
// Usage:
//  string s;
//  DC3Algorithm dc3;
//  dc3.Construct(s);
//  Now we can use dc3.GetSA() and dc3.GetLCP()
// SA and LCP is 0-indexed
// First entry of LCP is always 0
// LCP[i]=Longest common prefix between LCP[i-1] and LCP[i]. LCP[0]=0
// After building SparseTabe, query(left+1,right) to query LCP of SA[left],SA[right]

#define MAXN mn // >= 256

class RmqSparseTable {

  int* logTable;
  int** rmq;
  int n;
  public:
  void init(int *a, int asz) {
    n=asz;

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


class DC3Algorithm {
private: 
    int AN;
    int A[3 * MAXN + 100];
    int cnt[MAXN + 1]; 
    int SA[MAXN + 1];
    RmqSparseTable RST;

    void radix_pass(int* A, int AN, int* R, int RN, int* D) {
        memset(cnt, 0, sizeof(int) * (AN + 1));
        int* C = cnt + 1;
        for (int i = 0; i < RN; i++) ++C[A[R[i]]];
        for (int i = -1, v = 0; i <= AN && v < RN; v += C[i++]) swap(v, C[i]);
        for (int i = 0; i < RN; i++) D[C[A[R[i]]]++] = R[i];
    }

    void suffix_array(int* A, int AN) {
        if (!AN) 
            SA[0] = 0;
        else if (AN == 1) {
            SA[0] = 1;
            SA[1] = 0;
            return;
        }
        
        int RN = 0;
        int* SUBA = A + AN + 2;
        int* R = SUBA + AN + 2;
        for (int i = 1; i < AN; i += 3) SUBA[RN++] = i;
        for (int i = 2; i < AN; i += 3) SUBA[RN++] = i;
        A[AN + 1] = A[AN] = -1;
        radix_pass(A + 2, AN - 2, SUBA, RN, R);
        radix_pass(A + 1, AN - 1, R, RN, SUBA);
        radix_pass(A + 0, AN - 0, SUBA, RN, R);

        int resfix, resmul, v;
        if (AN % 3 == 1) {
            resfix = 1;
            resmul = RN >> 1;
        }
        else {
            resfix = 2;
            resmul = RN + 1 >> 1;
        }
        for (int i = v = 0; i < RN; i++) {
            v += i && (A[R[i - 1] + 0] != A[R[i] + 0] || A[R[i - 1] + 1] != A[R[i] + 1] || A[R[i - 1] + 2] != A[R[i] + 2]);
            SUBA[R[i] / 3 + (R[i] % 3 == resfix) * resmul] = v;
        }

        if (v + 1 != RN) {
            suffix_array(SUBA, RN);
            SA[0] = AN;
            for (int i = 1; i <= RN; i++) 
                SA[i] = SA[i] < resmul ? 3 * SA[i] + (resfix==1?2:1) : 3 * (SA[i] - resmul) + resfix;
        }
        else {
            SA[0] = AN;
            memcpy(SA + 1, R, sizeof(int) * RN);
        }

        int NMN = RN; 
        for (int i = RN = 0; i <= NMN; i++) 
            if (SA[i] % 3 == 1) 
                SUBA[RN++] = SA[i] - 1;
        
        radix_pass(A, AN, SUBA, RN, R);

        for (int i = 0; i <= NMN; i++) 
            SUBA[SA[i]] = i;

        int ii = RN - 1;
        int jj = NMN;
        int pos;
        for (pos = AN; ii >= 0; pos--) {
            int i = R[ii];
            int j = SA[jj];
            int v = A[i] - A[j];
            if (!v) 
                if (j % 3 == 1) 
                    v = SUBA[i + 1] - SUBA[j + 1];
                else {
                    v = A[i + 1] - A[j + 1];
                    if (!v) v = SUBA[i + 2] - SUBA[j + 2];
                }            
            SA[pos] = v < 0 ? SA[jj--] : R[ii--];
        }
    }

    void prep_string(string s) {
        int v = 0;
        AN = s.length();
        memset(cnt, 0, 256 * sizeof(int));
        for (int i = 0; i < AN; i++) cnt[s[i]]++;
        for (int i = 0; i < 256; i++) cnt[i] = cnt[i] ? v++ : -1;
        for (int i = 0; i < AN; i++) A[i] = cnt[s[i]];
    }

    int REVSA[MAXN + 1];
    void compute_reverse_sa() {
        for (int i = 0; i <= AN; i++) REVSA[SA[i]] = i;
    }

    int LCP[MAXN + 1];
    void compute_lcp() {
        int len = 0;
        for (int i = 0; i < AN; i++, len = max(0, len - 1)) {
            int s = REVSA[i];
            int j = SA[s - 1];
            for (; i + len < AN && j + len < AN && A[i + len] == A[j + len]; len++);
            LCP[s] = len;
        }
    }

public:
    vector<int> GetLCP() {
        vector<int> ret; ret.clear();
        for (int i = 1; i <= AN; i++)
            ret.push_back(LCP[i]);
        return ret;
    }
    void Construct2(const char *s) {
        prep_string(s);
        suffix_array(A, AN);
        compute_reverse_sa();
        compute_lcp();
        RST.init(LCP+1,AN);
    }
    void Construct(string s) {
        Construct2(s.c_str());
    }

    int queryLCP(int ox, int oy) {
      if (ox==oy) return AN-ox;
      int x=REVSA[ox]-1,y=REVSA[oy]-1;
      //printf("xx:%d x:%d yy:%d y:%d\n",xx,x,yy,y);
      if (x>=y) swap(x,y);
      return RST.minVal(x+1,y);
    }

    vector<int> GetSA() {
        vector<int> ret; ret.resize(AN);
        for (int i = 1; i <= AN; i++)
            ret[i-1]=SA[i];
        return ret;
    }
    vector<int> GetREVSA() {
        vector<int> ret; ret.resize(AN);
        for (int i = 0; i < AN; i++)
            ret[SA[i+1]]=i;
        return ret;
    }
};


DC3Algorithm dc3;
char s[mn];
int f[mn];
int n;
int vdig[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  vdig[1]=1;
  vdig[10]=2;
  vdig[100]=3;
  vdig[1000]=4;
  for (int x=1;x<mn;x++) chkmax(vdig[x],vdig[x-1]);
  scanf("%s",&s);
  n=strlen(s);
  dc3.Construct2(s);
  /*vector<int> SA=dc3.GetSA();
  //vector<int> LCP=dc3.GetLCP();
  //printf("%s\n\n",all.c_str());
  string st(s);
  for (int i=0;i<SA.size();i++) {
    auto w=SA[i];
    printf("%d: %s\n",i,st.substr(w,st.length()-w).c_str());
  }
  printf("\n");
  //for (auto &w:SA) printf("%d ",w); printf("\n");
  //for (auto &w:LCP) printf("%d ",w); printf("\n");
  //vector<int> revsa=dc3.GetREVSA();*/
  for (int x=0;x<=n;x++) f[x]=1<<30;
  f[0]=0;
  for (int x=0;x<n;x++) {
    for (int y=x+1;y<=n;y++) {
      int l=y-x;
      int c=0;
      for (int z=x;z<n;z+=l) {
        //printf("x:%d rx:%d z:%d rz:%d st:%d\n",x,revsa[x],z,revsa[z], ST.minVal(revsa[x]+1,revsa[z]));
        //printf("x:%d z:%d l:%d lcp:%d\n",x,z,l,dc3.queryLCP(x,z));
        if (dc3.queryLCP(x,z)>=l) {
          c++;
          int cand=vdig[c]+l+f[x];
          chkmin(f[z+l],cand);
        }
        else break;
      }
    }
  }
  printf("%d\n",f[n]);
}
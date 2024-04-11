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
inline void chkmin(string &aa, const string &bb) {
  if (aa.length()==bb.length()) {
    if (aa>bb) aa=bb;
  }
  else if (aa.length() > bb.length()) {
    aa=bb;
  }
}
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
typedef vector<pii> vpii;
const int E=0;
const int T=1;
const int F=2;
const int mk=3;
const int mz=1<<8;
const int MARK=1;
const int DONE=2;
string vdist[mk][mz];
bitset<mz> proced[mk];
bool cmp(const string &s, const string &a) {
  int slen=s.length(),alen=a.length();
  if (s.length()==a.length()) {
    return s<a;
  }
  else {
    return slen<alen;
  }
}
struct Node{
  string s;
  int k,sig;
  Node(string s, int k, int sig): s(s), k(k), sig(sig) {}
  bool operator < (Node a)const{
    // MUST reverse since priority_queue is a max-heap.
    // Do not just do !(a<b). This function must return false for equality.
    return cmp(a.s,s);
  }
};
priority_queue<Node > pq;
void push(const string &s, const int k, const int sig) {
  if (vdist[k][sig].length()==0||cmp(s,vdist[k][sig])) {
      vdist[k][sig]=s;
      pq.push(Node(s,k,sig));
  }
}

void dij() {
  push("z",F,0b10101010);
  push("y",F,0b11001100);
  push("x",F,0b11110000);
  while(!pq.empty()) {
    Node v=pq.top(); pq.pop();
    if (proced[v.k][v.sig]) continue;
    if (v.k==E) {
      {
        const int src=T,dest=E;
        for (int z=proced[src]._Find_first();z<mz;z=proced[src]._Find_next(z)) {
          push(v.s+"|"+vdist[src][z], dest, v.sig|z);
        }
      }
      push("("+v.s+")", F, v.sig);
    }
    else if (v.k==T) {
      {
        const int src=E,dest=E;
        for (int z=proced[src]._Find_first();z<mz;z=proced[src]._Find_next(z)) {
          push(vdist[src][z]+"|"+v.s, dest, v.sig|z);
        }
      }
      push(v.s,E,v.sig);
      {
        const int src=F,dest=T;
        for (int z=proced[src]._Find_first();z<mz;z=proced[src]._Find_next(z)) {
          push(v.s+"&"+vdist[src][z], dest, v.sig&z);
        }
      }
    }
    else {
      {
        const int src=T,dest=T;
        for (int z=proced[src]._Find_first();z<mz;z=proced[src]._Find_next(z)) {
          push(vdist[src][z]+"&"+v.s, dest, v.sig&z);
        }
      }
      push(v.s, T, v.sig);
      push("!"+v.s, F, (~v.sig)&(mz-1));
    }
    proced[v.k][v.sig]=true;
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  dij();
  int n; cin>>n;
  for (int j=0;j<n;j++) {
    string s; cin>>s;
    int x=0;
    for (int i=0;i<8;i++) {
      if (s[i]=='1') x|=1<<i;
    }
    string ans=vdist[E][x];
    printf("%s\n",ans.c_str());
  }

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
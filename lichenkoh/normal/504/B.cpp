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
const int UNDEF = -1;
const int INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

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

int readInt()
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
const int mn=2e5+2;
int t[2*mn];

void fadd(int *t, int i, int value, int n) {
  for (; i < 2*n; i |= i + 1)
    t[i] += value;
}

  // sum[0..i]
int fsum(int *t, int i) {
  int res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    res += t[i];
  return res;
}

int a[2][mn];
int b[mn];

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt();
  for (int k=0;k<2;k++) for (int i=0;i<n;i++) a[k][i]=readInt();
  for (int k=0;k<2;k++) {
    memset(t,0,sizeof t);
    for (int i=0;i<n;i++) {
      int x=a[k][i];
      int s=fsum(t,x);
      int pos=x-s;
      //printf("k:%d i:%d pos:%d\n",k,i,pos);
      b[i]+=pos;
      fadd(t,x,1,n);
    }
  }
  for (int i=n-1;i>=0;i--) {
    int base=n-i;
    //printf("i:%d base:%d\n",i,base);
    while(b[i]>=base) {
      b[i]-=base;
      if (i!=0) b[i-1]++;
    }
  }
  ordered_set s;
  for (int i=0;i<n;i++) s.insert(i);
  for (int i=0;i<n;i++) {
    int pos=*(s.find_by_order(b[i]));
    s.erase(pos);
    printf("%d ",pos);
  }
  printf("\n");
}
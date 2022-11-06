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


void fail() {
	printf("-1\n"); exit(0);
}
set<int> v[2];
vector<vi> vans;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s;cin>>s;
  int n=s.length();
  int zeros=0,ones=0;
  for (int i=0;i<n;i++) {
  	char c=s[i];
  	if (c=='0') zeros++;
  	else ones++;
  	v[c-'0'].insert(i);
  }
  int seqs=zeros-ones;
  if (seqs<=0) fail();
  for (int j=0;j<seqs;j++) {
  	vi vgot;
  	{
  		int b=0;
  		auto it=v[b].begin();
  		if (it==v[b].end()) fail();
  		vgot.PB(*it);
  		v[b].erase(it);
  	}
  	while(1) {
  	  {
  			int b=1;
  			auto it=v[b].lower_bound(vgot[vgot.size()-1]);
  			if (it==v[b].end()) break;
	  		vgot.PB(*it);
	  		v[b].erase(it);
  		}
  	  {
  			int b=0;
  			auto it=v[b].lower_bound(vgot[vgot.size()-1]);
  			if (it==v[b].end()) fail();
	  		vgot.PB(*it);
	  		v[b].erase(it);
  		}
  	}
  	vans.PB(vgot);
  }
  if (v[0].size()+v[1].size()!=0) fail();
  assert(vans.size()==seqs);
  printf("%d\n",vans.size());
  for (auto &a:vans) {
  	printf("%d ",a.size());
  	for (auto &b:a) printf("%d ",b+1);
  	printf("\n");
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
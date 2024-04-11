/*
Ideas to improve:
In each block:
queryl: We push all queryl onto precompute_request[l]. Then we precompute. Then we finally commit.
queryr:
We need to binary search for mo_left for each r.
First, for each index and each sqrt block, we can precompute the binsearched indices for the left and right endpoints of the block.
This takes O(n*sqrt(n)) memory. We can do a sweep for each p.
Then, when we binsearch, binsearch only within the binsearched indices.
*/

#include <bits/stdc++.h>
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
const int mn=200000;
pair<pii, int> q[mn];
int x2blk[mn];
const int BLK=2.75*sqrt(mn);
bool cmp(const pair<pii, int> &x, const pair<pii, int> &y) {
  int l1=x2blk[x.first.first],l2=x2blk[y.first.first];
  int r1=x.first.second,r2=y.first.second;
  return (l1<l2)||(l1==l2&&r1<r2);
}
int p2v[mn];
int v2p[mn+1];
const int mh=4544226+200000;
int _prealloc[mh];
int _preallocsz=0;
int *p2m[mn];
int p2msz[mn];
int p2p[mn];
inline int binsearch(int p, int key, int imin, int imax) {
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (p2m[p][imid]<key) imin=imid+1;
    else imax=imid;
  }
  //printf("p:%d x:%d ans:%d\n",p,key,imin);
  return imin;
}
int mo_left=0,mo_right=0;
inline int queryr(int p) {
	int pidx=p2p[p];
	int sz=p2msz[p];
	int got=pidx+1-binsearch(p,mo_left,0,pidx+1);
  return got;
}
int p2mli[mn];
inline int queryl(int p) {
	int sz=p2msz[p];
	int got=p2mli[p];
	while(got<sz&&p2m[p][got]<=mo_right) ++got;
	p2mli[p]=got;
	int pidx=p2p[p];
	got-=pidx;
  return got;
}
ll live=1;
inline void insr(int p) {
	int got=queryr(p);
  live+=got;
}
inline void rmr(int p) {
  int got=queryr(p);
  live-=got;
}
inline void insl(int p) {
	int got=queryl(p);
  live+=got;
}
inline void rml(int p) {
  int got=queryl(p);
  live-=got;
}

ll vans[mn];
int tmp[mn+1];
inline void put(ll x)
{
    if (!x){putchar('0'); putchar('\n'); return; }
    char ch[21];
    int ln = 0;
    while (x){
        ch[ln++] = x % 10;
        x /= 10;
    }
    ln--;
    while (ln >= 0){ putchar(ch[ln--] + 48); }
    putchar('\n');
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(v2p,-1,sizeof v2p);
  int n=rint(),qn=rint();
  int quo=0,rem=0;
	for (int x=0;x<n;x++) {
		if (++rem==BLK) {
			rem=0; quo++;
		}
		x2blk[x]=quo;
	}
  for (int p=0;p<n;p++) {
    int v=rint();
    p2v[p]=v;
    v2p[v]=p;
  }
  for (int x=1;x<=n;x++) {
    for (int y=x+x;y<=n;y+=x) tmp[y]++;
  }
  for (int p=0;p<n;p++) {
    int v=p2v[p];
    p2m[p]=_prealloc+_preallocsz;
    _preallocsz += tmp[v] + n/v;
  }
  //printf("%d\n",_preallocsz); exit(0);
  for (int p=0;p<n;p++) {
    int v=p2v[p];
    p2m[p][p2msz[p]++]=p;
    for (int x=v+v;x<=n;x+=v) {
      int posx=v2p[x];
      if (posx!=-1) {
        p2m[p][p2msz[p]++]=posx;
        p2m[posx][p2msz[posx]++]=p;
      }
    }
  }
  for (int p=0;p<n;p++) {
    sort(p2m[p],p2m[p]+p2msz[p]);
    p2p[p]=binsearch(p,p,0,p2msz[p]);
  }
  for (int qi=0;qi<qn;qi++) {
    int L=rint()-1,R=rint()-1;
    q[qi]=MP(MP(L,R),qi);
  }
  sort(q,q+qn,cmp);
  int lastblk=-1;
  for (int i=0;i<qn;i++) {
    int L=q[i].first.first,R=q[i].first.second;
    int blk=x2blk[L];
    if (blk!=lastblk) {
    	mo_left=L;
    	mo_right=L;
    	live=1;
    	lastblk=blk;
    }
    while(mo_right<R) mo_right++,insr(mo_right);
    while(mo_right>R) rmr(mo_right),mo_right--;
    while(mo_left>L)  mo_left--,insl(mo_left);
    while(mo_left<L)  rml(mo_left),mo_left++ ;
    int qi=q[i].snd;
    vans[qi]=live;
  }
  for (int qi=0;qi<qn;qi++) {
  	printf("%lld\n",vans[qi]);
  }

}
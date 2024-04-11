#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const bool DBG=0;
void go() {
	int n=rint(); int m=rint();
	vi final[2];
	for (int k=0;k<2;k++) final[k].resize(n+1,-1);
	vector<set<int> > g(n+1);
	vector<pii> origEdge;
	for (int i=0;i<m;i++) {
		int l=rint(); int r=rint();
		origEdge.PB(MP(l,r));
		g[l].insert(r); g[r].insert(l);
	}
	vector<set<int> > deg2v(n);
	for (int x=1;x<=n;x++) deg2v[g[x].size()].insert(x);
	bool phase=false;
	int live=n;
	int labelstart=1;
	vector<bool> islive(n+1,true);
	vi group[2]; vi phase0; set<int> neigh0;
	for (int d=n-1;d>=0;) {
		for (auto it=deg2v[d].begin();it!=deg2v[d].end();) {
			int z=*it;
			if (!islive[z]) {
				it=deg2v[d].erase(it);
				continue;
			}
			vpii proc;
			if (phase) {
				if (group[0].size()==0) {
					assert(group[1].size()==0);
					proc.PB(MP(z,0));
					int found=-1;
					for (int innerD=d;innerD>=0&&found==-1;innerD--) {
						for (auto &x: deg2v[innerD]) {
							if (islive[x] && x!=z && g[x].count(z)==0) {
								found=x; break;
							}
						}
					}
					assert(found!=-1);
					proc.PB(MP(found,1));
				} else {
					int grouptype=neigh0.count(z)?0:1;
					proc.PB(MP(z,grouptype));
				}
				for (auto &w:proc) group[w.snd].PB(w.fst);
			} else {
				proc.PB(MP(z,-1));
				phase0.PB(z);
			}
			for (auto &pr:proc) {
				int x=pr.fst,grouptype=pr.snd;
				if (DBG) printf("d:%d z:%d x:%d grouptype:%d\n",d,z,x,grouptype);
				live--; assert(islive[x]); islive[x]=false;
				for (auto &y:g[x]) {
					if (islive[y] && g[y].size()) {
						if (grouptype==0) {
							if (DBG) printf("y:%d belongs to neigh0\n",y);
							neigh0.insert(y);
						}
						deg2v[g[y].size()].erase(y);
						g[y].erase(x);
						int degy=g[y].size();
						assert(degy<d);
						deg2v[degy].insert(y);
					}
				}
			}
			//g[x].clear();
			it=deg2v[d].erase(it);
		}

		d--;
		if (d<live-1 || d==-1) {
			if (!phase) {
				phase=true;
				for (auto &x:phase0) {
					if (DBG) printf("Phase0: %d\n",x);
					for (int k=0;k<2;k++) final[k][x]=labelstart;
					++labelstart;
				}
			} else {
				if (group[0].size()&&group[1].size()) {
					if (DBG) for (int t=0;t<2;t++) {
						for (auto &x:group[t]) {
							printf("%d ",x);
						}
						printf(" end group %d at d=%d\n",t,d);
					}
					for (int k=0;k<2;k++) {
						int labels=labelstart;
						for (int t=0;t<2;t++) {
							for (auto &x:group[t^k]) {
								final[k][x]=labels; labels++;
							}
						}
					}
					labelstart+=group[0].size()+group[1].size();
					neigh0.clear();
					for (int k=0;k<2;k++) group[k].clear();
				}
			}
		}
	}
	for (int k=0;k<2;k++) {
		for (int x=1;x<=n;x++) printf("%d ",final[k][x]);
		printf("\n");
	}
	if (DBG) {	// Checker
		if (DBG) for (int k=0;k<2;k++) {
			for (int x=1;x<=n;x++) {
				printf("%d ",final[k][x]);
			}
			printf("\n");
		}
		for (int k=0;k<2;k++) {
			vector<bool> seen(n+1,false);
			for (int x=1;x<=n;x++) {
				assert(final[k][x]!=-1);
				seen[final[k][x]]=true;
			}
			int count=0; for (int x=1;x<=n;x++) count+=seen[x];
			assert(count==n);
		}
		for (auto &p:origEdge) {
			int l=p.fst,r=p.snd;
			assert(((final[0][l]-final[0][r]) * ll(final[1][l]-final[1][r])) > 0);
		}
		int diff=0;
		for (int x=1;x<=n;x++) {
			if (final[0][x]!=final[1][x]) diff++;
		}
		printf("diff:%d\n",diff);
	}
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t=rint(); for (int i=0;i<t;i++) go();
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
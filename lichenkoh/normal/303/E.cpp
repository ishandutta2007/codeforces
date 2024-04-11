#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
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
const int mn=82;
ld probprev[mn],probin[mn],probaft[mn];
ld f[mn][mn][mn];
ld vansstage[mn][mn];
void trans(vector<int> &have, int base, int mainpi, int haveprev) {
	int hsz=have.size();
	//printf("mainpi:%d base:%d\n",mainpi,base);
	for (int havei=0;havei<hsz;havei++) {
		int pi=have[havei];
		int cur=havei+base;
		int nxt=cur+1;
		for (int ht=0;ht<=nxt;ht++) {
			memset(f[nxt][ht],0,(nxt+1-ht)*sizeof(ld));
		}
		for (int height=0;height<=cur;height++) {
			for (int same=0;same<=cur-height;same++) {
				ld now=f[cur][height][same];
				//printf("cur:%d height:%d same:%d now:%f probin:%f probprev:%f probaft:%f\n",cur,height,same,now,probin[pi],probprev[pi],probaft[pi]);
				//if (now==0) break;
				if (now!=0) {
					f[cur+1][height][same+1]+=now*probin[pi];
					if (probprev[pi]!=0) f[cur+1][height+1][same]+=now*probprev[pi];
					if (probaft[pi]!=0) f[cur+1][height][same]+=now*probaft[pi];
				}
			}
		}
	}
	int cur=hsz+base;
	for (int height=0;height<=cur;height++) {
		for (int same=0;same<=cur-height;same++) {
			ld now=f[cur][height][same];
			//printf("cur:%d height:%d same:%d now:%f\n",cur,height,same,now);
			//if (now==0) break;
			if (now!=0) {
				now*=probin[mainpi];
				int num=same+1;
				vansstage[mainpi][height+haveprev]+=now/num;
				vansstage[mainpi][height+haveprev+num]-=now/num;
			}
		}
	}
}
int vl[mn],vr[mn];set<int> tmps; vector<int> v;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
	for (int pi=0;pi<n;pi++) {
		vl[pi]=rint();vr[pi]=rint();
		tmps.insert(vl[pi]);tmps.insert(vr[pi]);
	}
	for (auto &w:tmps) v.PB(w);
	int vsz=v.size()-1;
	for (int vi=0;vi<vsz;vi++) {
		int AL=v[vi],AR=v[vi+1];
		//printf("AL:%d AR:%d\n",AL,AR);
		vector<int> have;
		int haveprev=0;
		for (int pi=0;pi<n;pi++) {
			int numer=(min(AR,vr[pi])-max(AL,vl[pi]));
			//printf("vl[pi]:%d vr[pi]:%d numer:%d\n",vl[pi],vr[pi],numer);
			if (numer>0) {
				long double denom=(vr[pi]-vl[pi]);
				probin[pi]=numer/denom;
				have.PB(pi);
				probprev[pi]=(max(0,AL-vl[pi]))/denom;
				probaft[pi]=(max(0,vr[pi]-AR))/denom;
			}
			else if (vr[pi]<=AL) {
				haveprev++;
			}
		}
		memset(f[0],0,sizeof f[0]);
		f[0][0][0]=1;
		int hsz=have.size();
		if (hsz) {
			vector<int> start=have; start.resize(hsz-1);
			trans(start,0,have[hsz-1],haveprev);
			for (int mainhi=hsz-2;mainhi>=0;mainhi--) {
				vector<int> transh;
				for (int hi=mainhi+1;hi<hsz;hi++) transh.PB(have[hi]);
				trans(transh,mainhi,have[mainhi],haveprev);
			}
		}
	}
	for (int pi=0;pi<n;pi++) {
		double have=0;
		for (int rank=0;rank<n;rank++) {
			have+=vansstage[pi][rank];
			printf("%.7f ",have);
		}
		printf("\n");
	}
}
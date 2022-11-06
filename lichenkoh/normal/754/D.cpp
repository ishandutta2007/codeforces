#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e9;
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


map<ll,pair<vll,vll> > h;
const ll mn=3e5+4;
ll vl[mn],vr[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n=readInt(),k=readInt();
	for (ll i=1;i<=n;i++) {
		ll l=readInt(),r=readInt();
		vl[i]=l;vr[i]=r;
		h[l].fst.PB(i);
		h[r].snd.PB(i);
	}
	pair<ll,pll> best=MP(0,MP(-1,-1));
	set<pll, greater<pll> > lo; set<pll> hi;
	for (auto &w:h) {
		vector<ll> &vins=w.snd.fst;
		if (lo.size()>0) {
			pll cutoff=*(lo.begin());
			for (auto &x:vins) {
				pll got=MP(vl[x],x);
				if (got<cutoff) lo.insert(got);
				else hi.insert(got);
			}
		}
		else if (hi.size()>0) {
			pll cutoff=*(hi.begin());
			for (auto &x:vins) {
				pll got=MP(vl[x],x);
				if (got<cutoff) lo.insert(got);
				else hi.insert(got);
			}
		}
		else {
			for (auto &x:vins) {
				pll got=MP(vl[x],x);
				lo.insert(got);
			}
		}
		while((ll)lo.size()>k) {
			hi.insert(*(lo.begin()));
			lo.erase(lo.begin());
		}
		while((ll)lo.size()<k&&hi.size()>0) {
			lo.insert(*(hi.begin()));
			hi.erase(hi.begin());
		}
		if ((ll)lo.size()>=k) {
			assert((ll)lo.size()==k);
			ll left=(lo.begin())->fst;
			ll right=w.fst;
			chkmax(best,MP(right-left+1,MP(left,right)));
		}
		vector<ll> &ver=w.snd.snd;
		for (auto &x:ver) {
			lo.erase(MP(vl[x],x));
			hi.erase(MP(vl[x],x));
		}
	}
	if (best.fst==0) {
		printf("0\n");
		for (ll x=1;x<=k;x++) printf("%d ",x);
		printf("\n");
	}
	else {
		printf("%d\n",best.fst);
		ll fl=best.snd.fst,fr=best.snd.snd;
		for (ll x=1;x<=n;x++) {
			if (k==0) break;
			if (vl[x]<=fl&&fr<=vr[x]) {
				printf("%d ",x);
				--k;
			}
		}
		printf("\n");
	}
}
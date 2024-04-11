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
const ll INF=1e18;
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


const ll maxn=30001;
const ll maxid=maxn*4;
bitset<maxid> active;
ll id2node[maxid][3];
ll _src2id[maxn];
ll src2id[maxn][4];
ll _dest2id[maxn];
ll dest2id[maxn][8];
typedef pair<pair<ll,ll>, ll> st;
ll node2cnt[maxn];
st id2st[maxid];
set<pair<st,ll> > s;
void update_st(ll id) {
	ll a=id2node[id][0];
	ll b=id2node[id][1];
	ll c=id2node[id][2];
	ll bCnt=node2cnt[b];
	ll cCnt=node2cnt[c];
	id2st[id]=MP(MP(max(bCnt,cCnt),min(bCnt,cCnt)),-node2cnt[a]);
}
void update_id(ll id) {
	s.erase(MP(id2st[id],id));
	update_st(id);
	s.insert(MP(id2st[id],id));
}
void update_nodes(ll input_id) {
	set<ll> ids;
	for (ll k=0;k<3;k++) {
		ll node=id2node[input_id][k];
		for (ll i=0;i<4;i++) {ll id=src2id[node][i];  if (active[id]) ids.insert(id);}
		for (ll i=0;i<8;i++) {ll id=dest2id[node][i]; if (active[id]) ids.insert(id);}
	}
	for (auto &id:ids) update_id(id);
}
int main()
{
	active.set();
	ll n=readInt();
	for (ll v=1;v<=n;v++) node2cnt[v]=4;
	for (ll id=1;id<=4*n;id++) {
		ll a=readInt(),b=readInt(),c=readInt();
		id2node[id][0]=a;
		id2node[id][1]=b;
		id2node[id][2]=c;
		src2id[a][_src2id[a]++]=id;
		dest2id[b][_dest2id[b]++]=id;
		dest2id[c][_dest2id[c]++]=id;
		id2st[id]=MP(MP(4,4),-4);
		s.insert(MP(id2st[id],id));
	}
	vector<ll> final;
	while(!s.empty()) {
		auto top=*(s.begin());
		s.erase(s.begin());
		ll id=top.snd;
		final.PB(id);
		active[id]=false;
		ll a=id2node[id][0],b=id2node[id][1],c=id2node[id][2];
		node2cnt[a]--;
		++node2cnt[b];
		++node2cnt[c];
		//assert(node2cnt[b]<=9&&node2cnt[c]<=9);
		update_nodes(id);
	}
	printf("YES\n");
	for (auto &id:final) printf("%d ",id);
	printf("\n");
}
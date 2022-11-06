// http://codeforces.com/contest/837/submission/29253673
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

typedef pll STV;
struct Node {
    STV a;
    Node *lp, *rp;
};
class PersistentRangeModifyPointQuery {
public:
    // NumQueries * (log(max_index)+1) * 4
    Node tr[(2*75000) * (18+1) * 4];
    Node *lastn = tr;
    STV comb(const STV &x, const STV &y) {
        // Must be commutative
        return MP(x.fst+y.fst,x.snd+y.snd);
    }
    const STV identity=MP(0ll,0ll);
    int segn;
    void init(int _n) {
        segn=_n;
    }
    void _modify(Node *&cur, int l, int r, int x, int y, const STV &delta) {
        if (l > y || r < x) return;
        Node* cp = cur;
        cur = lastn++;
        if (cp) {
            *cur = *cp;
        }
        if (x <= l && r <= y) {
            cur->a = comb(cur->a, delta);
        } else {
            int m = (l + r) >> 1;
            _modify(cur->lp, l, m, x, y, delta);
            _modify(cur->rp, m + 1, r, x, y, delta);
        }
    }
    void modify(Node *&cur, int x, int y, const STV &delta) {
        _modify(cur, 0, segn-1, x, y, delta);
    }
    STV _query(Node* cur, int l, int r, int x) {
        if (cur==NULL) return identity;
        int m = (l + r) >> 1;
        STV ans=cur->a;
        if (x<=m) ans=comb(ans, _query(cur->lp, l, m, x));
        else ans=comb(ans, _query(cur->rp, m + 1, r, x));
        return ans;
    }
    STV query(Node *cur, int x) {
        return _query(cur, 0, segn-1, x);
    }
};
PersistentRangeModifyPointQuery st;

Node *root[75000+1];
ll presum[75000+1];
const int mx=200001;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  st.init(mx+1);
  for (int i=1;i<=n;i++) {
    int x1=rint(),x2=rint(),y1=rint(),a=rint(),b=rint(),y2=rint();
    presum[i]=y1+presum[i-1];
    root[i]=root[i-1];
    //printf("modify:%lld a:%d x1+1:%d b:%d y1:%d\n",(a*(ll)(x1+1))+(b-y1),a,x1+1,b,y1);
    //printf("got:%lld\n",got);
    st.modify(root[i],x1+1,x2,MP(b-y1,0ll));
    //printf("queryA:%lld\n",st.query(&root[i],x1+1,x1+1));
    //printf("l:%d r:%d a:%d\n",x1+1,x2,a);
    if (x1+1<=x2) st.modify(root[i],x1+1,x2,MP(0ll,a));
    //printf("queryB:%lld\n",st.query(&root[i],x1+1,x1+1));
    st.modify(root[i],x2+1,mx,MP(y2-y1,0));
    //printf("queryC:%lld\n",st.query(&root[i],x1+1,x1+1));
  }
  int qm=rint();
  ll last=0;
  for (int q=0;q<qm;q++) {
    int l=rint(),r=rint(),x=rint();
    x=(last+x)%1000000000;
    int qx=min(x,mx);
    auto pr=st.query(root[r],qx);
    ll R=pr.fst+pr.snd*x;
    auto pl=st.query(root[l-1],qx);
    ll L=pl.fst+pl.snd*x;
    ll OR=presum[r];
    ll OL=presum[l-1];
    last=R-L+OR-OL;
    //printf("x:%d R:%lld L:%lld OR:%lld OL:%lld\n",x,R,L,OR,OL);
    printf("%lld\n",last);
  }
}
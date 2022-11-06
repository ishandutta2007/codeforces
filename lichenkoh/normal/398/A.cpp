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

ll solve(ll a, ll b) {
	pll ans=MP(-b*b,-1ll);
	for (ll t=1;t<=a;t++) {
		ll parts=t+1;
		ll quo=b/parts;
		ll rem=b%parts;
		ll quo_only=parts-rem;
		ll quo_1=rem;
		ll cand=-quo_only*quo*quo-quo_1*(quo+1)*(quo+1)+t-1+(a-t+1)*(a-t+1);
		//ll cand=-(parts-1)*(quo*quo)-(quo+rem)*(quo+rem)+t-1+(a-t+1)*(a-t+1);
		chkmax(ans,MP(cand,t));
	}	
	return ans.fst;
}

pll bf(ll a, ll b) {
	ll n=a+b;
	ll zlim=1LL<<n;
	pll ans=MP(-b*b*2,-1ll);
	for (ll z=0;z<zlim;z++) {
		if (__builtin_popcountll(z)==a) {
			ll prev=1LL&z;
			ll cnt=1;
			ll cand=0;
			for (ll i=1;i<=n;i++) {
				ll bit=(z>>i)&1LL;
				if (bit!=prev||i==n) {
					if (prev) cand+=cnt*cnt;
					else cand-=cnt*cnt;
					//if (z==1) printf("i:%I64d cand:%I64d cnt:%I64d prev\n")
					cnt=0;
					prev=bit;
				}
				cnt++;
			}
			chkmax(ans,MP(cand,z));
		}
	}
	return ans;
}
void test() {
	for (ll k=0;k<100000;k++) {
		srand(time(0)+clock()+rand());
		ll a=rand()%10;
		ll b=rand()%10;
		//a=1;b=3;
		ll s=solve(a,b);
		pll u=bf(a,b);
		if (s!=u.fst) {
			printf("%I64d %I64d %I64d %I64d %I64d\n",a,b,s,u.fst,u.snd);
		}
	}
}
int main() 
{
	//test();
	//return 0;
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll a,b; cin>>a>>b;
	if (a==0) {
		printf("%I64d\n",-b*b);
		for (int i=0;i<b;i++) printf("x");
		printf("\n");
		return 0;
	}
	pll ans=MP(-b*b,-1ll);
	for (ll t=1;t<=a;t++) {
		ll parts=t+1;
		ll quo=b/parts;
		ll rem=b%parts;
		ll quo_only=parts-rem;
		ll quo_1=rem;
		ll cand=-quo_only*quo*quo-quo_1*(quo+1)*(quo+1)+t-1+(a-t+1)*(a-t+1);
		//ll cand=-(parts-1)*(quo*quo)-(quo+rem)*(quo+rem)+t-1+(a-t+1)*(a-t+1);
		chkmax(ans,MP(cand,t));
	}	
	//printf("%I64d\n",ans.fst);
	printf("%I64d\n",ans.fst);
	ll t=ans.snd;
	{
		ll parts=t+1;
		ll quo=b/parts;
		ll rem=b%parts;
		ll quo_only=parts-rem;
		ll quo_1=rem;
		bool used=0;
		for (int i=0;i<parts;i++) {
			ll xs=quo; if (i>=quo_only) xs++;
			for (int j=0;j<xs;j++) printf("x");
			if (i==0) {
				for (int j=0;j<a-t+1;j++) printf("o");	
			}
			else if (i!=parts-1) printf("o");
		}
	}
	printf("\n");
}
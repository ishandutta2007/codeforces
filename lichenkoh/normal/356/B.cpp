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
const ll mn=1e6+4;
ll n,m;
char a[mn],b[mn];
ll acnt[26],bcnt[26];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%lld %lld\n%s\n%s\n",&n,&m,a,b);
  ll alen=strlen(a),blen=strlen(b);
  ll g=__gcd(alen,blen);
  ll ans=0;
  for (ll r=0;r<g;r++) {
    memset(acnt,0,sizeof acnt);
    memset(bcnt,0,sizeof bcnt);
    for (ll x=r;x<alen;x+=g) acnt[a[x]-'a']++;
    for (ll x=r;x<blen;x+=g) bcnt[b[x]-'a']++;
    ll as=0,bs=0; for (ll c=0;c<26;c++) {as+=acnt[c]; bs+=bcnt[c];}
    ll cand=as*(ll)bs;
    for (ll c=0;c<26;c++) {
      cand-=acnt[c]*(ll)bcnt[c];
    }
    ans+=cand;
  }
  ll lcm=(alen*(ll)blen)/g;
  ll finalmult=(n*(ll)alen)/lcm;
  ll final=finalmult*(ll)ans;
  printf("%lld\n",final);
}
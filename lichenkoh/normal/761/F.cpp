#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;
const ll mq=300000;
const ll mn=1002;
char vs[mn][mn];
int va[mq],vb[mq],vc[mq],vd[mq]; char ve[mq];
ll n,m,q;
typedef struct {
	ll a[mn][mn];
} S;
void addval(S &s, ll x1, ll y1, ll x2, ll y2, ll val) {
	x1++; y1++;
	x2+=2; y2+=2;
	s.a[x1][y1]+=val;
	s.a[x2][y1]-=val;
	s.a[x1][y2]-=val;
	s.a[x2][y2]+=val;
}
void addpt(S &s, ll x1, ll y1, ll val) {
	x1++; y1++;
	s.a[x1][y1]+=val;
}
void process1(S &s) {
	{
		for (ll x=1;x<=n+1;x++) for (ll y=0;y<=m+1;y++) {
			s.a[x][y]+=s.a[x-1][y];
		}
		for (ll x=0;x<=n+1;x++) for (ll y=1;y<=m+1;y++) {
			s.a[x][y]+=s.a[x][y-1];
		}
	}
}
void process(S &s) {
	for (ll j=0;j<2;j++) {
		for (ll x=1;x<=n+1;x++) for (ll y=0;y<=m+1;y++) {
			s.a[x][y]+=s.a[x-1][y];
		}
		for (ll x=0;x<=n+1;x++) for (ll y=1;y<=m+1;y++) {
			s.a[x][y]+=s.a[x][y-1];
		}
	}
}
ll sum1(S &s, ll x, ll y) {
	return s.a[x+1][y+1];
}
ll sum(S &s, ll r1, ll c1, ll r2, ll c2) {
  return sum1(s, r2, c2) - sum1(s, r1 - 1, c2) - sum1(s, r2, c1 - 1) + sum1(s, r1 - 1, c1 - 1);
}

ll difforig[mq];
S t1[26], t2[26], tb;//, tall;
ll vans[mq];
//SS diffo[26];
//S ta[26],tb,tc[26],tall,tbyk[26];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%lld %lld %lld\n",&n,&m,&q);
	for (ll i=0;i<n;i++) scanf("%s\n",vs[i]);
	for (ll x=0;x<n;x++) for (ll y=0;y<m;y++) vs[x][y]=vs[x][y]-'a';
	for (ll i=0;i<q;i++) {
		char e;
		scanf("%d %d %d %d %c",&va[i],&vb[i],&vc[i],&vd[i],&e);
		--va[i];--vb[i];--vc[i];--vd[i];
		ve[i]=e-'a';
	}
	if (q==0) {
		printf("0\n"); return 0;
	}
	auto &diffo=t1;
	//for (ll c=0;c<26;c++) memset(t1[c].a,0,sizeof t1[c].a);
	for (ll c=0;c<26;c++) for (ll x=0;x<n;x++) for (ll y=0;y<m;y++) {
		addval(diffo[c],x,y,x,y,abs(c-vs[x][y]));
	}
	for (ll c=0;c<26;c++) process(diffo[c]);

	long long allsum=0;
	for (ll i=0;i<q;i++) {
		ll x1=va[i],y1=vb[i],x2=vc[i],y2=vd[i],c=ve[i];
		difforig[i]=sum(diffo[c],x1,y1,x2,y2);
		//printf("i:%lld difforig:%lld\n",i,difforig[i]);
		allsum+=difforig[i];
	}


	auto &tbyk=t1;
	for (ll c=0;c<26;c++) memset(t1[c].a,0,sizeof t1[c].a);
	for (ll i=0;i<q;i++) {
		ll x1=va[i],y1=vb[i],x2=vc[i],y2=vd[i],k=ve[i];
		addval(tbyk[k], x1, y1, x2, y2, 1);
	}
	for (ll k=0;k<26;k++) process(tbyk[k]);

	for (ll x=0;x<n;x++) {
		for (ll y=0;y<m;y++) {
			for (ll k=0;k<26;k++) {
				ll cnt=sum(tbyk[k],x,y,x,y);
				addpt(tb,x,y,cnt*abs(k-vs[x][y]));
			}
		}
	}
	process1(tb);

	auto &td=t2;
	//for (ll c=0;c<26;c++) memset(t2[c].a,0,sizeof t2[c].a);
	for (ll x=0;x<n;x++) {
		for (ll y=0;y<m;y++) {
			for (ll k=0;k<26;k++) {
				ll cnt=sum(tbyk[k],x,y,x,y);
				td[k].a[x][y]=cnt;
			}
		}
	}
	auto &tc=t1;
	for (ll c=0;c<26;c++)memset(t1[c].a,0,sizeof t1[c].a);
	for (ll x=0;x<n;x++) for (ll y=0;y<m;y++) {
		{
			ll sum=0;
			ll ans=0;
			for (ll c=0;c<26;c++) {
				ans+=sum;
				addpt(tc[c],x,y,ans);
				sum+=td[c].a[x][y];
			}
		}
		{
			ll sum=0;
			ll ans=0;
			for (ll c=25;c>=0;c--) {
				ans+=sum;
				addpt(tc[c],x,y,ans);
				sum+=td[c].a[x][y];
			}
		}
	}

	for (ll c=0;c<26;c++) process1(tc[c]);

	for (ll i=0;i<q;i++) {
		long long x1=va[i],y1=vb[i],x2=vc[i],y2=vd[i],c=ve[i];
		long long init=q*(long long)difforig[i] + allsum;
		long long ans1=0;
		long long ans2=sum(tb, x1,y1,x2,y2);
		long long ans3=sum(tc[c], x1,y1,x2,y2);
		long long cand=init-ans1-ans2+ans3;
		vans[i]=cand;
	}

	auto &tall=tb;
	memset(tb.a,0,sizeof tb.a);
	for (ll i=0;i<q;i++) {
		ll x1=va[i],y1=vb[i],x2=vc[i],y2=vd[i];
		addval(tall, x1, y1, x2, y2, 1);
	}
	process(tall);

	auto &ta=t1;
	for (ll c=0;c<26;c++) memset(t1[c].a,0,sizeof t1[c].a);
	for (ll x=0;x<n;x++) {
		for (ll y=0;y<m;y++) {
			ll cnt=sum(tall,x,y,x,y);
			for (ll c=0;c<26;c++) {
				addpt(ta[c],x,y,cnt*abs(c-vs[x][y]));
			}
		}
	}
	for (ll c=0;c<26;c++)process1(ta[c]);

	long long final=1LL<<62LL;
	for (ll i=0;i<q;i++) {
		long long x1=va[i],y1=vb[i],x2=vc[i],y2=vd[i],c=ve[i];
		long long ans1=sum(ta[c], x1,y1,x2,y2);
		long long cand=vans[i]-ans1;
		chkmin(final,cand);
	}
	printf("%lld\n",final);
}
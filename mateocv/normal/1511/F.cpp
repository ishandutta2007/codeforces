#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const ll MOD=998244353;

vector<string> s;

inline ll add(ll x, ll y){
	x+=y;
	if(x>=MOD)x-=MOD;
	return x;
}

ll dp[1010][10][6][10][6];

ll f(ll x, ll p0, ll c0, ll p1, ll c1){
	ll &res=dp[x][p0][c0][p1][c1];
	if(res>=0)return res;
	if(x==0)return res=(p0==SZ(s)&&p1==SZ(s));
	res=0;
	vector<ll> v0,v1;
	if(p0==SZ(s))fore(i,0,SZ(s))v0.pb(i);
	else v0.pb(p0);
	if(p1==SZ(s))fore(i,0,SZ(s))v1.pb(i);
	else v1.pb(p1);
	for(auto i0:v0){
		for(auto i1:v1){
			if(s[i0][c0]==s[i1][c1]){
				res=add(res,f(x-1,c0+1==SZ(s[i0])?SZ(s):i0,(c0+1)%SZ(s[i0]),c1+1==SZ(s[i1])?SZ(s):i1,(c1+1)%SZ(s[i1])));
			}
		}
	}
	return res;
}

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

typedef vector<ll> vi;
vi BM(vi x){
	vi ls,cur;ll lf=0,ld=0;
  fore(i,0,SZ(x)){
		ll t=0;
    fore(j,0,SZ(cur))t=(t+x[i-j-1]*(ll)cur[j])%MOD;
		if((t-x[i])%MOD==0)continue;
    if(!SZ(cur)){cur.resize(i+1);lf=i;ld=(t-x[i])%MOD;continue;}
		ll k=-(x[i]-t)*fpow(ld,MOD-2)%MOD;
		vi c(i-lf-1);c.pb(k);
    fore(j,0,SZ(ls))c.pb(-ls[j]*k%MOD);
    if(SZ(c)<SZ(cur))c.resize(SZ(cur));
    fore(j,0,SZ(cur))c[j]=(c[j]+cur[j])%MOD;
    if(i-lf+SZ(ls)>=SZ(cur))ls=cur,lf=i,ld=(t-x[i])%MOD;
		cur=c;
	}
  fore(i,0,SZ(cur))cur[i]=(cur[i]%MOD+MOD)%MOD;
	return cur;
}

const int LOG=32;

//init O(n^2log) query(n^2 logk)
//input: terms: first n term; trans: transition function; MOD; LOG=mxlog of k
//output calc(k): kth term mod MOD
//example: {1,1} {2,1} an=2*a_(n-1)+a_(n-2); calc(3)=3 calc(10007)=71480733
struct LinearRec{
  typedef vector<ll> vi;
  ll n; vi terms, trans; vector<vi> bin;
  vi add(vi &a, vi &b){
    vi res(n*2+1);
    fore(i,0,n+1)fore(j,0,n+1)res[i+j]=(res[i+j]*1LL+(ll)a[i]*b[j])%MOD;
    for(int i=2*n; i>n; --i){
      fore(j,0,n)res[i-1-j]=(res[i-1-j]*1LL+(ll)res[i]*trans[j])%MOD;
      res[i]=0;
    }
    res.erase(res.begin()+n+1,res.end());
    return res;
  }
  LinearRec(vi &terms, vi &trans):terms(terms),trans(trans){
    n=SZ(trans);vi a(n+1);a[1]=1;
    bin.pb(a);
    fore(i,1,LOG)bin.pb(add(bin[i-1],bin[i-1]));
  }
  ll calc(ll k){
    vi a(n+1);a[0]=1;
    fore(i,0,LOG)if((k>>i)&1)a=add(a,bin[i]);
    ll ret=0;
    fore(i,0,n)ret=((ll)ret+(ll)a[i+1]*terms[i])%MOD;
    return ret;
  }
};

int main(){FIN;
	ll n,m; cin>>n>>m;
	s.resize(n);
	fore(i,0,n)cin>>s[i];
	mset(dp,-1);
	//cout<<f(m,n,0,n,0)<<"\n";
	vector<ll> v;
	fore(i,0,1010)v.pb(f(i,n,0,n,0));
	auto re=BM(v);
	while(SZ(v)>SZ(re))v.pop_back();
	LinearRec lr(v,re);
	cout<<lr.calc(m+1)<<"\n";
	
	return 0;
}
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
typedef int ll;

string s;

const int MAXL=1522;

ll dp[MAXL][202][202];

const ll MOD=10007;

inline ll add(ll x, ll y){
	x+=y;
	if(x>=MOD)x-=MOD;
	return x;
}

ll f(ll x, ll l, ll r){
	ll &res=dp[x][l][r];
	if(res>=0)return res;
	if(x==0)return res=l>r-1;
	if(x==1)return res=(l>r-1?26:l==r-1);
	res=0;
	fore(i,0,26){
		res=add(res,f(x-2,l+(l<SZ(s)&&s[l]=='a'+i),r-(r>0&&s[r-1]=='a'+i)));
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
  typedef vector<int> vi;
  int n; vi terms, trans; vector<vi> bin;
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
  int calc(int k){
    vi a(n+1);a[0]=1;
    fore(i,0,LOG)if((k>>i)&1)a=add(a,bin[i]);
    int ret=0;
    fore(i,0,n)ret=((ll)ret+(ll)a[i+1]*terms[i])%MOD;
    return ret;
  }
};

int main(){FIN;
	cin>>s;
	ll n; cin>>n;
	mset(dp,-1);
	//cout<<f(SZ(s)+n,0,SZ(s)-1)<<"\n";
	vector<ll> v;
	fore(i,0,MAXL-SZ(s)){
		if(n%2==i%2)v.pb(f(SZ(s)+i,0,SZ(s)));
	}
	//for(auto i:v)cout<<i<<" ";
	//cout<<"\n";
	auto re=BM(v);
	//cout<<SZ(re)<<"\n";
	//for(auto i:re)cout<<i<<" ";
	//cout<<"\n";
	while(SZ(v)>SZ(re))v.pop_back();
	//for(auto i:v)cout<<i<<" ";
	//cout<<"\n";
	LinearRec lr(v,re);
	cout<<lr.calc(n/2+1)<<"\n";
	
	return 0;
}
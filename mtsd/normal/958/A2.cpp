#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 100005;

struct RollingHash {
	static const ll mo0=1000000007,mo1=1000000009;
	static ll mul0,mul1,mul2,mul3; static vector<ll> pmo[4];
	static const ll add0=1000010007,add1=1003333331;
	vector<string> s; int rw,cl; vector<vector<ll> > hash_[2];
	void init(vector<string> s) {
		this->s=s; rw=(int)s.size(); cl=(int)s[0].size();
		hash_[0].resize(rw+1,vector<ll>(cl+1,0)),hash_[1].resize(rw+1,vector<ll>(cl+1,0));
		if(!mul0) mul0=10009+(((ll)&mul0)>>5)%259,mul1=10007+(((ll)&mul1)>>5)%257;
		if(!mul2) mul2=10039+(((ll)&mul2)>>5)%289,mul3=10037+(((ll)&mul3)>>5)%287;
		if(pmo[0].empty()) pmo[0].pb(1),pmo[1].pb(1),pmo[2].pb(1),pmo[3].pb(1);
		rep(i,rw)rep(j,cl) hash_[0][i+1][j+1]=(hash_[0][i+1][j]*mul0+add0+s[i][j])%mo0;	//hash_[0][i][j]0~i-1,0~j-1
		rep(i,rw)rep(j,cl) hash_[1][i+1][j+1]=(hash_[1][i+1][j]*mul1+add1+s[i][j])%mo1;
		rep(j,cl)rep(i,rw) hash_[0][i+1][j+1]=(hash_[0][i][j+1]*mul2+hash_[0][i+1][j+1])%mo0;
		rep(j,cl)rep(i,rw) hash_[1][i+1][j+1]=(hash_[1][i][j+1]*mul3+hash_[1][i+1][j+1])%mo1;
	}
	ll comp(int u,int l,int d,int r,int id,const ll mod){
		return (hash_[id][d+1][r+1]+(mod-hash_[id][d+1][l]*pmo[id][r+1-l]%mod)
					+(mod-hash_[id][u][r+1]*pmo[id+2][d+1-u]%mod)+(hash_[id][u][l]*pmo[id][r+1-l]%mod*pmo[id+2][d+1-u]%mod))%mod;
	}
	pair<ll,ll> hash(int u,int l,int d,int r) {	//su~d,l~r
		if(l>r||u>d) return make_pair(0,0);
		while(pmo[0].size()<r+2) pmo[0].pb(pmo[0].back()*mul0%mo0), pmo[1].pb(pmo[1].back()*mul1%mo1);
		while(pmo[2].size()<d+2) pmo[2].pb(pmo[2].back()*mul2%mo0), pmo[3].pb(pmo[3].back()*mul3%mo1);
		return make_pair(comp(u,l,d,r,0,mo0),comp(u,l,d,r,1,mo1));
	}
	pair<ll,ll> hash(vector<string> s) { init(s); return hash(0,0,(int)s.size()-1,(int)s[0].size()-1); }	//s
	static pair<ll,ll> rconcat(pair<ll,ll> L,pair<ll,ll> R,int len) {	//LR(lenR)
		while(pmo[0].size()<len+2) pmo[0].pb(pmo[0].back()*mul0%mo0), pmo[1].pb(pmo[1].back()*mul1%mo1);
		return make_pair((R.first + L.first*pmo[0][len])%mo0,(R.second + L.second*pmo[1][len])%mo1);
	}
	static pair<ll,ll> cconcat(pair<ll,ll> L,pair<ll,ll> R,int len) {	//LR(lenR)
		while(pmo[2].size()<len+2) pmo[2].pb(pmo[2].back()*mul2%mo0), pmo[3].pb(pmo[3].back()*mul3%mo1);
		return make_pair((R.first + L.first*pmo[2][len])%mo0,(R.second + L.second*pmo[3][len])%mo1);
	}
};
vector<ll> RollingHash::pmo[4]; ll RollingHash::mul0,RollingHash::mul1,RollingHash::mul2,RollingHash::mul3;

bool contain(RollingHash& arg1,vector<string>& arg2)
{
	int r = (int)arg2.size(),c = (int)arg2[0].size();
	if(arg1.rw < r || arg1.cl < c){
		return false;
	}
	RollingHash rh;
	pair<ll,ll> hs = rh.hash(arg2);
	rep(i,arg1.rw-r+1){
		rep(j,arg1.cl-c+1){
			if(arg1.hash(i,j,i+r-1,j+c-1) == hs){
				return true;
			}
		}
	}
	return false;
}

set<pll> st;
map<pll,int> mp;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vs a(n),b(m);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,m){
        cin >> b[i];
    }
    RollingHash rh1,rh2;
    rh1.init(a),rh2.init(b);
    rep(i,n-m+1){
        pll p = rh2.hash(0,i,m-1,m+i-1);
        st.insert(p);
        mp[p] = i;
    }
    rep(i,n-m+1){
        pll res = rh1.hash(i,0,m+i-1,m-1);
        if(st.find(res) != st.end()){
            cout << i+1 << " " << mp[res]+1 << "\n";
            return 0;
        }
    }
    return 0;
}
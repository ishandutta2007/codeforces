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

vector<ll> comp(vector<ll> a, vector<ll> b){
	ll n=SZ(a);
	vector<ll> res(n);
	fore(i,0,n)res[i]=b[a[i]];
	return res;
}

vector<ll> fpow(vector<ll> p, ll e){
	ll n=SZ(p);
	vector<ll> res;
	fore(i,0,n)res.pb(i);
	while(e){
		if(e&1)res=comp(res,p);
		p=comp(p,p),e>>=1;
	}
	return res;
}

const int MAXN=100005;

vector<ll> g[MAXN];

int main(){FIN;
	ll n; cin>>n;
	vector<ll> a(n),p(n);
	fore(i,0,n)cin>>p[i],p[i]--;
	fore(i,0,n)cin>>a[i],a[i]--;
	set<ll> st;
	for(auto i:p)st.insert(i);
	ll c=n-SZ(st);
	ll m=0;
	for(auto i:a)m=max(m,i);
	m-=n-1;
	m/=c;
	auto pp=fpow(p,m);
	fore(i,0,n)g[pp[i]].pb(i);
	fore(i,0,n)sort(ALL(g[i]));
	vector<ll> res(n,-1);
	set<ll> rem;
	fore(i,0,n)rem.insert(i);
	vector<ll> mini(n,-1);
	fore(i,0,n){
		if(a[i]<n){
			assert(SZ(g[i]));
			res[g[i][0]]=a[i];
			rem.erase(a[i]);
			for(auto j:g[i]){
				mini[j]=max(mini[j],a[i]);
			}
		}
	}
	//for(auto i:res)cout<<i+1<<" ";
	//cout<<"\n";
	fore(i,0,n){
		if(res[i]==-1){
			auto s=*rem.lower_bound(mini[i]);
			res[i]=s;
			rem.erase(s);
		}
	}
	for(auto i:res)cout<<i+1<<" ";
	cout<<"\n";
	
	return 0;
}
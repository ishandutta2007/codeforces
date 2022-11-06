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

vector<ll> p={1,2,3,5,9,17};

vector<ll> pot;

const ll MOD=998244353;

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

ll k,a,h; 

vector<ll> getw(ll n, ll mk){
	vector<ll> v,vn,res(n);
	fore(i,0,n)v.pb(i);
	ll va=0,ta=0;
	while(SZ(v)>1){
		fore(i,0,SZ(v)/2){
			if((1ll<<va)&mk){
				vn.pb(v[2*i]);
				res[v[2*i+1]]=ta;
			}else{
				vn.pb(v[2*i+1]);
				res[v[2*i]]=ta;
			}
			va++;
		}
		ta++;
		v=vn;
		vn.clear();
	}
	res[v[0]]=ta;
	return res;
}

ll calch(ll st, ll n, ll mk, ll posp, ll w){
	auto g=getw(n,mk);
	//for(auto i:g)cout<<i<<" ";
	//cout<<"\n";
	fore(i,0,SZ(g))g[i]=p[posp-g[i]];
	if(w){
		fore(i,0,SZ(g)){
			if(g[i]==2)g[i]=1;
		}
	}
	//for(auto i:g)cout<<i<<" ";
	//cout<<"\n";
	ll res=0;
	fore(i,0,n){
		res=(res+(st+i)*pot[g[i]])%MOD;
	}
	return res;
}

int main(){FIN;
	cin>>k>>a>>h;
	fore(i,0,20)pot.pb(fpow(a,i));
	ll n=(1ll<<k);
	if(k<=3){
		fore(i,0,(1ll<<(n-1))){
			if(calch(1,n,i,k,0)==h){
				auto res=getw(n,i);
				for(auto i:res)cout<<p[k-i]<<" ";
				cout<<"\n";
				return 0;
			}
		}
		cout<<"-1\n";
	}else{
		ll nn=n/2;
		set<pair<ll,ll>> st[2];
		fore(i,0,(1ll<<(nn-1))){
			st[0].insert({calch(nn+1,nn,i,k,0),i});
			st[1].insert({calch(nn+1,nn,i,k,1),i});
		}
		fore(i,0,(1ll<<(nn-1))){
			auto c0=calch(1,nn,i,k,0);
			auto it0=st[1].lower_bound(pair<ll,ll>({(h-c0+MOD)%MOD,-1}));
			if(it0!=st[1].end()&&it0->fst==(h-c0+MOD)%MOD){
				auto res=getw(nn,i);
				for(auto i:res){
					cout<<p[k-i]<<" ";
				}
				res=getw(nn,it0->snd);
				for(auto i:res){
					if(p[k-i]>2)cout<<p[k-i]<<" ";
					else cout<<"1 ";
				}
				cout<<"\n";
				return 0;
			}
			auto c1=calch(1,nn,i,k,1);
			auto it1=st[0].lower_bound(pair<ll,ll>({(h-c1+MOD)%MOD,-1}));
			if(it1!=st[0].end()&&it1->fst==(h-c1+MOD)%MOD){
				auto res=getw(nn,i);
				for(auto i:res){
					if(p[k-i]>2)cout<<p[k-i]<<" ";
					else cout<<"1 ";
				}
				res=getw(nn,it1->snd);
				for(auto i:res){
					cout<<p[k-i]<<" ";
				}
				cout<<"\n";
				return 0;
			}
		}
		cout<<"-1\n";
	}
	
	return 0;
}
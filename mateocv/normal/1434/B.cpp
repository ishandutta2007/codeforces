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

const int MAXN=100005;

vector<ll> v;

ll u[MAXN],m[MAXN];

vector<ll> s;

vector<pair<ll,ll>> ran[2*MAXN];

priority_queue<pair<ll,ll>> pq;

ll res[2*MAXN];

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,2*n){
		char c; cin>>c;
		if(c == '+'){
			v.pb(0);
		}else{
			ll a; cin>>a;
			v.pb(a);
		}
	}
	fore(i,0,2*n)v[i]-=1;
	fore(i,0,2*n){
		if(v[i]>=0)u[v[i]]=i;
	}
	ll va=0;
	fore(i,0,2*n){
		if(v[i]>=0)va--;
		else va++;
		if(va<0){
			cout<<"NO\n";
			return 0;
		}
	}
	//cout<<"HOLAAAAAAAAa"<<endl;
	fore(i,0,2*n){
		if(v[i]<0)continue;
		while(SZ(s)&&s.back()<v[i])s.pop_back();
		if(SZ(s)){
			m[v[i]]=s.back();
		}else{
			m[v[i]]=-1;
		}
		s.pb(v[i]);
	}
	fore(i,0,n){
		ll ub=0;
		if(m[i]>=0)ub=u[m[i]];
		ran[ub].pb({u[i],i});
	}
	
	mset(res,-1);
	fore(i,0,2*n){
		for(auto j:ran[i]){
			pq.push({-j.fst,j.snd});
		}
		if(v[i]<0){
			if(SZ(pq)==0){
				cout<<"NO\n";
				return 0;
			}
			auto f=pq.top();
			pq.pop();
			if(-f.fst>=i){
				res[i]=f.snd;
			}else{
				cout<<"NO\n";
				return 0;
			}
		}
	}
	cout<<"YES\n";
	fore(i,0,2*n){
		if(res[i]>=0)cout<<res[i]+1<<" ";
	}
	cout<<"\n";
	return 0;
}
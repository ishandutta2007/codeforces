#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll esp(ll p){
	for(ll i=2;i*i<=p;i++){
		if(p%i==0)return 0;
	}
	return 1;
}

ll be(ll b, ll e){
  ll r=1;
  while(e)if(e&1)r=(r*b),e^=1; else b=(b*b),e/=2;
  return r;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll d[n];
		fore(i,0,n)cin>>d[i];
		/*unordered_*/set<ll>s;
		//sort(d,d+n);
		fore(i,0,n)s.insert(d[i]);
		vector<pair<ll,ll>> p;
		fore(i,0,n){
			if(esp(d[i]))p.pb({d[i],1});
		}
		fore(i,0,SZ(p)){
			ll va=p[i].fst;
			while(1){
				va*=p[i].fst;
				//cout<<va<<"\n";
				if(s.count(va))p[i].snd++;
				else break;
			}
		}
		ll tot=1,br=0;
		for(auto i:p){
			tot*=(i.snd+1);
			if(tot>350){
				br=1; break;
			}
		}
		//for(auto i:p)cout<<i.snd<<" ";
		//cout<<tot<<"\n";
		if(br){
			cout<<-1<<"\n";
			continue;
		}
		ll res=1;
		if(tot==n+2){
			for(auto i:p){
				res*=be(i.fst,i.snd);
			}
			for(ll i=2;i*i<=res;i++){
				if(res%i==0){
					if(s.count(i)==0||s.count(res/i)==0){
						br=1; break;
					}
				}
			}
			if(br){
				cout<<-1<<"\n";
				continue;
			}else{
				cout<<res<<"\n";
			}
		}else if(tot==n+1){
			for(auto i:p){
				res*=be(i.fst,i.snd);
			}
			res*=p[0].fst;
			for(ll i=2;i*i<=res;i++){
				if(res%i==0){
					if(s.count(i)==0||s.count(res/i)==0){
						br=1; break;
					}
				}
			}
			if(br){
				cout<<-1<<"\n";
				continue;
			}else{
				cout<<res<<"\n";
			}
		}else{
			cout<<-1<<"\n";
			continue;
		}
	}
	
	return 0;
}
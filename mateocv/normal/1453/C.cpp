#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

char a[2020][2020];

pair<ll,ll> com[2020][10];

pair<ll,ll> NEUT={2020,-1};

vector<ll> solve(ll n){
	fore(i,0,n){
		fore(j,0,10){
			com[i][j]=NEUT;
		}
	}
	fore(i,0,n){
		fore(j,0,n){
			com[j][a[i][j]-'0'].fst=min(com[j][a[i][j]-'0'].fst,i);
			com[j][a[i][j]-'0'].snd=max(com[j][a[i][j]-'0'].snd,i);
		}
	}
	vector<ll> res(10);
	fore(j,0,10){
		pair<ll,ll> ex=NEUT;
		fore(i,0,n){
			if(com[i][j]!=NEUT){
				res[j]=max(res[j],(com[i][j].snd-com[i][j].fst)*max(i,n-1-i));
				ex.fst=min(ex.fst,i);
				ex.snd=max(ex.snd,i);
			}
		}
		if(ex==NEUT)continue;
		fore(i,0,n){
			if(com[i][j]!=NEUT){
				res[j]=max(res[j],max(com[i][j].snd,n-1-com[i][j].fst)*max(abs(ex.fst-i),abs(ex.snd-i)));
			}
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			fore(j,0,n){
				cin>>a[i][j];
			}
		}
		auto res0=solve(n);
		fore(i,0,n){
			fore(j,i+1,n){
				swap(a[i][j],a[j][i]);
			}
		}
		auto res1=solve(n);
		fore(i,0,10)cout<<max(res0[i],res1[i])<<" ";
		cout<<"\n";
	}
	
	return 0;
}
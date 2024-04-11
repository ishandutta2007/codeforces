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

const int MAXN=1010;

ll n,m;

ll t[MAXN][MAXN];

vector<pair<pair<ll,ll>,ll>> v;

vector<pair<pair<ll,ll>,ll>> res;

vector<pair<ll,ll>> dir={{0,0},{0,1},{1,0},{1,1}};

bool valid(ll x, ll y){
	return 0<=x&&x<n&&0<=y&&y<m;
}

void ch(ll x, ll y){
	if(!valid(x,y))return;
	ll c=0;
	for(auto ii:dir){
		ll i=x+ii.fst,j=y+ii.snd;
		if(!valid(i,j))return;
		if(!t[i][j])continue;
		else if(c==0)c=t[i][j];
		else if(c!=t[i][j])return;
	}
	if(c)v.pb({{x,y},c});
}

void paint(pair<pair<ll,ll>,ll> p){
	ll maxi=0;
	ll x=p.fst.fst,y=p.fst.snd,c=p.snd;
	for(auto ii:dir){
		ll i=x+ii.fst,j=y+ii.snd;
		maxi=max(maxi,t[i][j]);
		t[i][j]=0;
	}
	if(maxi==c){
		res.pb(p);
		fore(dx,-1,2){
			fore(dy,-1,2){
				ll i=x-dx,j=y-dy;
				if(i!=x||j!=y)ch(i,j);
			}
		}
	}
}

int main(){FIN;
	cin>>n>>m;
	fore(i,0,n){
		fore(j,0,m)cin>>t[i][j];
	}
	fore(i,0,n-1){
		fore(j,0,m-1){
			ch(i,j);
		}
	}
	while(SZ(v)){
		auto b=v.back();
		v.pop_back();
		paint(b);
	}
	fore(i,0,n){
		fore(j,0,m){
			if(t[i][j]){
				cout<<"-1\n";
				return 0;
			}
		}
	}
	cout<<SZ(res)<<"\n";
	reverse(ALL(res));
	for(auto i:res)cout<<i.fst.fst+1<<" "<<i.fst.snd+1<<" "<<i.snd<<"\n";
	return 0;
}
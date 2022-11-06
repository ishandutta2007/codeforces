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

vector<pair<ll,ll>> a;

const int MAXN=200005,sq=500;

vector<ll> oc[MAXN];

ll ex[MAXN];

vector<ll> lz;

void add(ll l, ll r, ll x, ll y){
	ll va=l,pd=0;
	while(va<r){
		if(!pd){
			if(va+x<r){
				lz[va+x]+=1;
				va+=x;
				pd^=1;
			}else break;
		}else{
			if(va+y<r){
				lz[va+y]-=1;
				va+=y;
				pd^=1;
			}else break;
		}
	}
	if(pd)lz[r]-=1;
}

vector<ll> sr[sq];

ll ofs[MAXN];

int main(){FIN;
	ll n,m; cin>>n>>m;
	a.resize(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	vector<ll> b(m);
	fore(i,0,m){
		ll x,y; cin>>x>>y;
		if(x==1)b[i]=y-1;
		else b[i]=-y;
		oc[y-1].pb(i);
	}
	//cout<<"INPUT"<<endl;
	//for(auto i:b)cout<<i<<" ";
	//cout<<"\n";
	fore(i,0,n){
		if(SZ(oc[i])&1)oc[i].pb(m);
	}
	fore(i,0,n){
		if(a[i].fst+a[i].snd<sq)ex[i]=1;
	}
	lz.resize(m+1);
	fore(i,0,n){
		if(!ex[i]){
			fore(j,0,SZ(oc[i])/2){
				add(oc[i][2*j],oc[i][2*j+1],a[i].fst,a[i].snd);
			}
		}
	}
	//for(auto i:lz)cout<<i<<" ";
	//cout<<"\n";
	vector<ll> res(m);
	fore(i,1,sq)sr[i].resize(i);
	ll sump=0;
	fore(i,0,m){
		sump+=lz[i];
		res[i]+=sump;
		if(ex[max(b[i],-b[i]-1)]){
			if(b[i]>=0){
				ll x=a[b[i]].fst,y=a[b[i]].snd;
				ofs[b[i]]=i%(x+y);
				fore(j,ofs[b[i]]+x,ofs[b[i]]+x+y){
					sr[x+y][j%(x+y)]+=1;
				}
			}else{
				ll x=a[-b[i]-1].fst,y=a[-b[i]-1].snd;
				ll of=ofs[-b[i]-1];
				//cout<<x<<" "<<y<<" "<<of<<"\n";
				fore(j,of+x,of+x+y){
					sr[x+y][j%(x+y)]-=1;
				}
			}
		}
		/*
		fore(j,1,3){
			cout<<j<<": ";
			for(auto jj:sr[j])cout<<jj<<" ";
			cout<<"\n";
		}
		*/
		fore(j,1,sq)res[i]+=sr[j][i%j];
	}
	for(auto i:res)cout<<i<<"\n";
	
	return 0;
}
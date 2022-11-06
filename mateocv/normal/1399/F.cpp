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

bool cmp(const pair<ll,ll> &a,const pair<ll,ll> &b){
	return a.snd-a.fst>b.snd-b.fst||(a.snd-a.fst==b.snd-b.fst&&a.fst<b.fst);
}
/*
bool cmp2(const pair<pair<ll,ll>,ll> &a,const pair<pair<ll,ll>,ll> &b){
	return a.fst.fst<b.fst.fst||(a.fst.fst==b.fst.fst&&a.fst<b.fst)||(a.fst==b.fst&&a.snd<b.snd);
}
*/
vector<ll> g[3030];

ll dp[3030];

pair<ll,ll> a[3030];

ll f(ll u){
	//cout<<u<<": ";
	ll &r=dp[u];
	if(r>=0)return r;
	r=1;
	vector<pair<pair<ll,ll>,ll>> v;
	for(auto i:g[u]){
		v.pb({a[i],i});
	}
	sort(ALL(v));
	//for(auto i:v)cout<<i.fst.fst<<" "<<i.fst.snd<<" "<<i.snd<<"\n";
	ll npos[2][SZ(v)];
	mset(npos,-1);
	fore(i,0,SZ(v)-1){
		npos[0][i]=i+1;
	}
	//npos[0][v.back().snd]=-1;
	//fore(i,0,SZ(v))npos[1][v[i].snd]=-1;
	fore(i,0,SZ(v)){
		fore(j,i+1,SZ(v)){
			if(v[j].fst.fst>v[i].fst.snd){
				npos[1][i]=j; break;
			}
		}
	}
	if(SZ(v)==0)return r=1;
	ll maxi[SZ(v)];
	mset(maxi,-1);
	for(ll i=SZ(v)-1;i>=0;i--){
		maxi[i]=0;
		if(npos[0][i]!=-1){
			maxi[i]=max(maxi[i],maxi[npos[0][i]]);
		}
		if(npos[1][i]!=-1){
			maxi[i]=max(maxi[i],maxi[npos[1][i]]+f(v[i].snd));
		}else{
			maxi[i]=max(maxi[i],f(v[i].snd));
		}
	}
	//cout<<u<<": ";
	//fore(i,0,SZ(v))cout<<maxi[i]<<" ";
	r=maxi[0]+1;
	//cout<<" -> "<<r<<"\n";
	return r;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		n++;
		fore(i,0,n-1)cin>>a[i].fst>>a[i].snd;
		a[n-1]={0,4e5};
		sort(a,a+n,cmp);
		//fore(i,0,n)cout<<a[i].fst<<" "<<a[i].snd<<"\n";
		//cout<<"HOLAAAAA"<<endl;
		fore(i,0,n){
			fore(j,0,i){
				if(a[j].fst<=a[i].fst&&a[i].snd<=a[j].snd)g[j].pb(i);;
			}
		}
		fore(i,0,n){
			dp[i]=-1;
		}
		/*
		fore(i,0,n){
			cout<<i<<": ";
			for(auto j:g[i]){
				cout<<j<<" ";
			}
			cout<<"\n";
		}
		*/
		//cout<<"HOLAAAAA"<<endl;
		cout<<f(0)-1<<"\n";
		fore(i,0,n)g[i].clear();
	}
	
	return 0;
}
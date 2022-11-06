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

bool cmp(pair<pair<ll,ll> ,ll> a, pair<pair<ll,ll> ,ll> b){
	return a.fst.fst*b.fst.snd<b.fst.fst*a.fst.snd;
}

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.fst*b.snd<b.fst*a.snd;
}

bool compe(pair<ll,ll> a, pair<ll,ll> b){
	return a.fst*b.snd<=b.fst*a.snd;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		vector<ll> ar;
		fore(i,0,m){
			ar.pb(a.back());
			a.pop_back();
		}
		vector<vector<ll>> v(m);
		vector<pair<pair<ll,ll>,ll>> vp;
		vector<ll> sg,ub(m);
		fore(i,0,m){
			ll k; cin>>k;
			ll s=0;
			v[i].resize(k);
			fore(j,0,k)cin>>v[i][j],s+=v[i][j];
			vp.pb({{s,k},i});
			sg.pb(s);
		}
		
		sort(ALL(vp),cmp);
		sort(ALL(ar));
		fore(i,0,m)ub[vp[i].snd]=i;
		vector<ll> sump[3]={{0},{0},{0}};
		fore(i,0,m){
			ll val[3]={0,0,0};
			if(i&&compe(vp[i].fst,(pair<ll,ll>){ar[i-1],1}))val[0]=1;
			if(compe(vp[i].fst,(pair<ll,ll>){ar[i],1}))val[1]=1;
			if(i<m-1&&compe(vp[i].fst,(pair<ll,ll>){ar[i+1],1}))val[2]=1;
			fore(k,0,3)sump[k].pb(sump[k].back()+val[k]);
		}
		//for(auto i:ar)cout<<i<<" ";
		//cout<<"\n";
		//for(auto i:vp)cout<<i.fst.fst<<" "<<i.fst.snd<<" "<<i.snd<<"\n";
		fore(i,0,m){
			//cout<<i<<":\n";
			fore(j,0,SZ(v[i])){
				//cout<<" "<<j<<":\n";
				pair<ll,ll> p={sg[i]-v[i][j],SZ(v[i])-1};
				//cout<<p.fst<<" "<<p.snd<<"\n";
				ll l=0,r=m-1;
				while(l<=r){
					ll mid=(l+r)/2;
					if(comp(vp[mid].fst,p))l=mid+1;
					else r=mid-1;
				}
				if(l>ub[i])l--;
				//cout<<"l "<<l<<"\n";
				ll mn=min(l,ub[i]);
				ll mx=max(l,ub[i]);
				ll res=(sump[1][mn]-sump[1][0]==mn)&&(sump[1][m]-sump[1][mx+1]==m-mx-1);
				if(l==ub[i])res=(res&&(compe(p,{ar[l],1})));
				if(l>ub[i])res=(res&&(sump[0][ub[i]+1]-sump[0][l+1]==ub[i]-l)&&(compe(p,{ar[l],1})));
				if(l<ub[i])res=(res&&(sump[2][l]-sump[2][ub[i]]==l-ub[i])&&(compe(p,{ar[l],1})));
				cout<<res;
			}
		}
		cout<<"\n";
	}
	
	return 0;
}
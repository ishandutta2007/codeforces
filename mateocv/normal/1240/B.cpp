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

int main(){FIN;
	ll q; cin>>q;
	while(q--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i],a[i]--;
		set<ll> st;
		fore(i,0,n)st.insert(a[i]);
		vector<ll> v;
		for(auto i:st)v.pb(i);
		ll nn=SZ(v);
		ll comp[n];
		mset(comp,0);
		fore(i,0,nn){
			comp[v[i]]=i;
		}
		fore(i,0,n)a[i]=comp[a[i]];
		//fore(i,0,n)cout<<a[i]<<" "; cout<<"\n";
		ll c[nn];
		mset(c,0);
		fore(i,0,n)c[a[i]]++;
		//fore(i,0,nn)cout<<c[i]<<" "; cout<<"\n";
		ll b[nn];
		mset(b,0);
		ll cp[nn];
		mset(cp,0);
		fore(i,0,n){
			if(cp[a[i]]==0&&a[i]>0&&cp[a[i]-1]==c[a[i]-1])b[a[i]]++;
			cp[a[i]]++;
		}
		//fore(i,0,nn)cout<<b[i]<<" "; cout<<"\n";
		ll res=0;
		ll van=0;
		fore(i,0,nn){
			if(b[i])van++,res=max(res,van);
			else{
				van=0;
			}
		}
		cout<<nn-res-1<<"\n";
	}
	
	return 0;
}
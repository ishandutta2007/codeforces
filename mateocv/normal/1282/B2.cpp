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
	ll t; cin>>t;
	while(t--){
		ll n,p,k; cin>>n>>p>>k;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		sort(a,a+n);
		ll res=0,resp=0;
		ll sump[n+1];
		sump[0]=0;
		fore(i,1,n+1)sump[i]=a[i-1]+sump[i-1];
		fore(i,0,k){
			resp=0;
			ll tot=sump[i];
			//cout<<"corto1 ";
			if(tot>p)continue;
			resp+=i;
			ll pos=k-1+i;
			while(1){
				//cout<<"corto2 ";
				if(pos>=n)break;
				//cout<<"corto3 ";
				if(tot+a[pos]>p)break;
				tot+=a[pos];
				pos+=k;
				resp+=k;
			}
			//cout<<resp<<" ";
			res=max(res,resp);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
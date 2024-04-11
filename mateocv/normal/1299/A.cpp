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
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	vector<ll> b[31];
	fore(i,0,n){
		fore(j,0,30){
			if((1<<j)&a[i])b[j].pb(i);
		}
	}
	/*ll res[n];
	mset(res,0);
	fore(i,0,30){
		if(SZ(b[i])==1){
			res[b[i][0]]++;
		}
	}
	ll maxi=0,maxid=-1;
	fore(i,0,n){
		if(res[i]>maxi){
			maxi=res[i];
			maxid=i;
		}
	}
	if(maxid==-1){
		fore(i,0,n)cout<<a[i]<<" ";
		return 0;
	}
	cout<<a[maxid]<<" ";
	fore(i,0,n)if(i!=maxid)cout<<a[i]<<" ";*/
	
	fore(i,0,30){
		if(SZ(b[29-i])==1){
			cout<<a[b[29-i][0]]<<" ";
			fore(j,0,n)if(j!=b[29-i][0])cout<<a[j]<<" ";
			return 0;
		}
	}
	fore(i,0,n)cout<<a[i]<<" ";
	return 0;
}
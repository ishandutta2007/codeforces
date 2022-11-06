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

ll ask(ll op, ll a, ll b){
	if(op==0)cout<<"XOR ";
	else cout<<"AND ";
	cout<<a+1<<" "<<b+1<<endl;
	ll resp; cin>>resp;
	return resp;
}

map<ll,ll> mp;

int main(){FIN;
	ll n; cin>>n;
	ll a[n-1];
	fore(i,0,n-1)a[i]=ask(0,0,i+1);
	ll l=-1,r=-1;
	fore(i,0,n-1){
		if(mp.count(a[i])){
			l=mp[a[i]];
			r=i+1;
			break;
		}else{
			mp[a[i]]=i+1;
		}
	}
	ll res[n];
	mset(res,0);
	if(l!=-1){
		ll val=ask(1,l,r);
		res[0]=a[l-1]^val;
		fore(i,1,n)res[i]=res[0]^a[i-1];
	}else{
		mp.clear();
		l=-1; r=-1;
		fore(i,0,n-1){
			if(mp.count(a[i])){
				l=mp[a[i]];
				r=i+1;
				break;
			}else{
				mp[a[i]^(n-1)]=i+1;
			}
		}
		assert(l!=-1);
		res[0]=0;
		res[0]^=ask(1,0,l);
		res[0]^=ask(1,0,r);
		fore(i,1,n)res[i]=res[0]^a[i-1];
	}
	cout<<"! ";
	fore(i,0,n)cout<<res[i]<<" ";
	cout<<endl;
	
	return 0;
}
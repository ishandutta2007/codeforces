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

ll btd(string &s){
	ll res=0;
	fore(i,0,SZ(s)){
		res*=2;
		res+=s[i]-'0';
	}
	return res;
}

string dtb(ll n, ll m){
	string res;
	fore(i,0,m){
		if((1ll<<i)&n)res.pb('1');
		else res.pb('0');
	}
	reverse(ALL(res));
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll a[n];
		fore(i,0,n){
			string s; cin>>s;
			a[i]=btd(s);
		}
		sort(a,a+n);
		//fore(i,0,n)cout<<a[i]<<" "; cout<<"\n";
		ll l=0,r=(1ll<<m)-1;
		ll c=(1ll<<m)-n;
		while(l<=r){
			ll mid=(l+r)/2;
			ll cant=lower_bound(a,a+n,mid+1)-a;
			ll tot=mid+1-cant;
			//cout<<l<<" "<<r<<" "<<mid<<" "<<cant<<" "<<tot<<"\n";
			if(tot>=(c+1)/2)r=mid-1;
			else l=mid+1;
		}
		//cout<<l<<"\n";
		cout<<dtb(l,m)<<"\n";
	}
	
	return 0;
}
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
	string s; cin>>s;
	vector<ll> a,b;
	fore(i,0,SZ(s)){
		if(s[i]=='A'){
			a.pb(i);
		}else{
			b.pb(i);
		}
	}
	ll res=0;
	fore(i,0,SZ(a)){
		if(i<SZ(a)-1){
			res+=a[i+1]-a[i]-1;
		}else{
			res+=n-1-a[i];
		}
		//cout<<res<<"\n";
		if(i>0){
			res+=a[i]-a[i-1]-1;
		}else{
			res+=a[i];
		}
		//cout<<res<<"\n";
	}
	fore(i,0,SZ(b)){
		if(i<SZ(b)-1){
			res+=b[i+1]-b[i]-1;
		}else{
			res+=n-1-b[i];
		}
		//cout<<res<<"\n";
		if(i>0){
			res+=b[i]-b[i-1]-1;
		}else{
			res+=b[i];
		}
		//cout<<res<<"\n";
	}
	ll dos=0;
	fore(i,0,SZ(s)-1){
		if(s[i]!=s[i+1])dos++;
	}
	res-=dos;
	//cout<<res<<"\n";
	cout<<n*(n-1)/2-res;
	
	return 0;
}
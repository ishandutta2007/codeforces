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
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)a[i]+=(a[i]%10);
		ll c=0;
		fore(i,0,n)c+=(a[i]%10==0);
		if(c==n){
			ll br=0;
			fore(i,0,n){
				if(a[i]!=a[0])br++;
			}
			if(br)cout<<"NO\n";
			else cout<<"YeS\n";
		}else if(c){
			cout<<"nO\n";
		}else{
			fore(i,0,n){
				while(a[i]%10!=2)a[i]+=(a[i]%10);
			}
			ll br=0;
			fore(i,0,n){
				if(((a[i]/10)&1)!=((a[0]/10)&1))br++;
			}
			if(br)cout<<"NO\n";
			else cout<<"YeS\n";
		}
	}
	
	return 0;
}
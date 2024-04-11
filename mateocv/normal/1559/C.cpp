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
		if(a[0]==1){
			cout<<n+1<<" ";
			fore(i,0,n)cout<<i+1<<" ";
			cout<<"\n";
			continue;
		}
		if(a[n-1]==0){
			fore(i,0,n)cout<<i+1<<" ";
			cout<<n+1<<" ";
			cout<<"\n";
			continue;
		}
		ll pos=-1;
		fore(i,0,n-1){
			if(a[i]==0&&a[i+1]==1){
				pos=i; break;
			}
		}
		assert(pos!=-1);
		fore(i,0,pos+1)cout<<i+1<<" ";
		cout<<n+1<<" ";
		fore(i,pos+1,n)cout<<i+1<<" ";
		cout<<"\n";
	}
	
	return 0;
}
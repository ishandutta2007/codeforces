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
		ll n,s; cin>>n>>s;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll maxi=0;
		ll maxid=0;
		ll rec=-1;
		fore(i,0,n){
			s-=a[i];
			if(a[i]>maxi){
				maxi=a[i];
				maxid=i;
			}
			if(s<0){
				rec=i;
				break;
			}
			if(i==n-1)rec=n;
		}
		if(rec==n){
			cout<<"0\n";
		}else{
			if(s+maxi>=0)cout<<maxid+1<<"\n";
			else cout<<"0\n";
		}
	}
	return 0;
}
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
		ll a[n],b[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		ll u=0,m=0;
		fore(i,0,n){
			if(a[i]==1)u++;
			if(a[i]==-1)m++;
		}
		ll br=0;
		fore(i,0,n){
			if(a[n-1-i]==1)u--;
			if(a[n-1-i]==-1)m--;
			if(b[n-1-i]==a[n-1-i])continue;
			if(b[n-1-i]>a[n-1-i]&&u==0){
				br++; break;
			}
			if(b[n-1-i]<a[n-1-i]&&m==0){
				br++; break;
			}
		}
		if(br){
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
		}
	}
	
	return 0;
}
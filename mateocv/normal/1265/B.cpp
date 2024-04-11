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
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll u=-1;
		fore(i,0,n){
			if(a[i]==1)u=i;
		}
		string res(n,'0');
		ll l=u-1,r=u+1;
		res[0]='1';
		fore(i,2,n+1){
			while(l>=0){
				if(a[l]<=i)l--;
				else break;
			}
			while(r<n){
				if(a[r]<=i)r++;
				else break;
			}
			if(r-l-1==i)res[i-1]='1';
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
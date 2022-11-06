#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
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
	ll res=0;
	fore(i,0,n){
		res+=min(abs(a[i]-1),abs(a[i]+1));
	}
	ll tot=0;
	fore(i,0,n){
		if(a[i]==0){
			cout<<res; return 0;
		}
		if(a[i]<0)tot++;
	}
	if(tot%2==0)cout<<res;
	else cout<<res+2;
	
	return 0;
}
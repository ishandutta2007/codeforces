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
		reverse(a,a+n);
		ll cam=0,br=0;
		fore(i,0,n-1){
			if(cam==0){
				if(a[i]>a[i+1])cam++;
			}else{
				if(a[i]<a[i+1]){
					cout<<n-i-1<<"\n";
					br++; break;
				}
			}
		}
		if(!br){
			cout<<"0\n";
		}
	}
	
	return 0;
}
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
	ll t; cin>>t;
	while(t--){
		ll n,x; cin>>n>>x;
		ll d[n],h[n];
		fore(i,0,n)cin>>d[i]>>h[i];
		ll dd=0;
		fore(i,0,n)dd=max(dd,d[i]);
		ll b=0;
		fore(i,0,n)b=max(b,d[i]-h[i]);
		if(b==0){
			if(x<=dd)cout<<1<<"\n";
			else cout<<-1<<"\n";
		}else{
			x-=dd;
			if(x<=0){
				cout<<1<<"\n";
			}else{
				cout<<(x+b-1)/b+1<<"\n";
			}
		}
	}
	
	return 0;
}
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

deque<ll> d;

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	fore(i,0,n)d.pb(a[i]);
	cout<<(n-1)/2<<"\n";
	fore(i,0,n){
		if(i&1){
			cout<<d.front()<<" ";
			d.pop_front();
		}else{
			cout<<d.back()<<" ";
			d.pop_back();
		}
	}
	
	return 0;
}
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
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll x=0;
	fore(i,0,n)x^=a[i];
	if(n%2==0&&x!=0){
		cout<<"NO\n";
		return 0;
	}
	if(n%2==0)n--;
	vector<pair<ll,pair<ll,ll>>> res;
	fore(i,0,n/2){
		res.pb({2*i,{2*i+1,2*i+2}});
	}
	fore(i,1,n/2){
		res.pb({2*(n/2-1-i),{2*(n/2-1-i)+1,2*(n/2-1-i)+2}});
	}
	cout<<"YES\n";
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i.fst+1<<" "<<i.snd.fst+1<<" "<<i.snd.snd+1<<"\n";
	
	return 0;
}
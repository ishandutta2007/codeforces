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
		ll s=0;
		for(auto i:a)s+=i;
		ll tr=n*(n+1)/2;
		if(s%tr!=0||s<=0){
			cout<<"NO\n";
			continue;
		}
		s/=tr;
		vector<ll> res(n);
		ll br=0;
		fore(i,0,n){
			res[i]=(a[(i+n-1)%n]+s-a[i]);
			if(res[i]%n!=0||res[i]<=0){
				cout<<"NO\n";
				br++; break;
			}
			res[i]/=n;
		}
		if(br)continue;
		ll ss=0;
		for(auto i:res)ss+=i;
		if(s!=ss){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}
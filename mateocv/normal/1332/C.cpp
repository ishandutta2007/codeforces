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
		ll n,k; cin>>n>>k;
		string s; cin>>s;
		ll res=0;
		fore(i,0,(k+1)/2){
			//cout<<i<<": ";
			map<char,ll> cant;
			fore(j,0,n/k)cant[s[j*k+i]]++;//,cout<<j*k+i<<" ";
			if(i!=k-1-i)fore(j,0,n/k)cant[s[(j+1)*k-i-1]]++;//,cout<<(j+1)*k-i-1<<" ";
			ll tot=0,maxi=0;
			for(auto i:cant){
				tot+=i.snd;
				maxi=max(maxi,i.snd);
			}
			res+=tot-maxi;
			//cout<<"\n";
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
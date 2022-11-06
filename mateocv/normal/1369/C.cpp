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
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll> w(k);
		fore(i,0,k)cin>>w[i];
		ll res=0;
		sort(ALL(a));
		sort(ALL(w));
		reverse(ALL(w));
		fore(i,0,k){
			if(w[k-1-i]==1)res+=a.back();
			res+=a.back();
			a.pop_back();
		}
		fore(i,0,SZ(w))w[i]--;
		while(SZ(w)){
			if(w.back()==0)w.pop_back();
			else if(w.back()==1){
				res+=a.back();
				a.pop_back();
				w.pop_back();
			}else{
				a.pop_back();
				w[SZ(w)-1]--;
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
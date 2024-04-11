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

bool iss(vector<ll> v){
	auto vs=v;
	sort(ALL(vs));
	return vs==v;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		ll res=0,maxi=-1;
		fore(i,0,n){
			maxi=max(maxi,a[i]);
			if(maxi==i){
				res++;
				maxi=-1;
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
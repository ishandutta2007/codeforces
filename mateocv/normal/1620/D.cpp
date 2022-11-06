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
		sort(ALL(a));
		set<ll> st;
		for(auto i:a)st.insert(i);
		ll maxi=a.back();
		ll c[3]={0,0,0};
		for(auto i:a)c[i%3]++;
		ll res=(maxi+2)/3;
		if(maxi%3==0){
			if(c[1]+c[2])res++;
		}else if(maxi%3==1){
			if(c[2]&&(st.count(1)||st.count(maxi-1)))res++;
		}else if(maxi%3==2){
			if(c[1])res++;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
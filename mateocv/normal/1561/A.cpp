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

vector<ll> oper(vector<ll> a, ll p){
	fore(i,0,SZ(a)-1){
		if((i&1)==p){
			if(a[i]>a[i+1])swap(a[i],a[i+1]);
		}
	}
	//for(auto i:a)cout<<i<<" ";
	//cout<<"\n";
	return a;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		auto b=a;
		sort(ALL(b));
		ll res=0;
		while(a!=b){
			a=oper(a,res&1);
			res++;
		}
		cout<<res<<"\n";
	}
	
	
	return 0;
}
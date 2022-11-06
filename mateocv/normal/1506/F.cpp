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

ll mino(ll a, ll b){
	//cout<<a<<" "<<b<<"\n";
	ll res=0;
	if((a+b)&1){
		res= (a-b)/2;
	}else{
		if(a==b)res= a;
		else res= mino(a-1,b)+1;
	}
	//cout<<res<<"\n";
	return res;
}

ll mine(ll a, ll b){
	//cout<<a<<" "<<b<<"\n";
	ll res= (a-b+1)/2;
	//cout<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<pair<ll,ll>> a(n);
		fore(i,0,n)cin>>a[i].fst,a[i].fst--;
		fore(i,0,n)cin>>a[i].snd,a[i].snd--;
		sort(ALL(a));
		ll res=mino(a[0].fst,a[0].snd);
		fore(i,0,SZ(a)-1){
			pair<ll,ll> d={a[i+1].fst-a[i].fst,a[i+1].snd-a[i].snd};
			if((a[i].fst+a[i].snd)&1)res+=mine(d.fst,d.snd);
			else res+=mino(d.fst,d.snd);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
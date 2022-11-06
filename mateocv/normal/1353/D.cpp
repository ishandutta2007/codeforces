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
		priority_queue<pair<ll,ll>> pq;
		pq.push({n,0});
		ll res[n];
		mset(res,0);
		ll va=1;
		while(SZ(pq)){
			pair<ll,ll> q=pq.top(); pq.pop();
			ll p=(2*(-q.snd)+q.fst-1)/2;
			res[p]=va++;
			if(p+q.snd>0)pq.push({p+q.snd,q.snd});
			if(-q.snd+q.fst-p-1>0)pq.push({-q.snd+q.fst-p-1,-p-1});
		}
		fore(i,0,n)cout<<res[i]<<" ";
		cout<<"\n";
	}
	
	return 0;
}
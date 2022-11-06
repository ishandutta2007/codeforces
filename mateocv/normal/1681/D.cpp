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

vector<ll> dig(ll n){
	vector<ll> res;
	while(n){
		if(n%10>=2)res.pb(n%10);
		n/=10;
	}
	return res;
}

ll cantd(ll n){
	ll res=0;
	while(n){
		res++;
		n/=10;
	}
	return res;
}

ll bfs(ll x, ll n){
	map<ll,ll> mp;
	queue<ll> q;
	q.push(x);
	mp[x]=0;
	while(SZ(q)){
		auto f=q.front(); q.pop();
		auto d=dig(f);
		for(auto i:d){
			ll nx=i*f;
			if(!mp.count(nx)){
				mp[nx]=mp[f]+1;
				q.push(nx);
				if(cantd(nx)>=n)return mp[nx];
			}
		}
	}
	return -1;
}

int main(){FIN;
	ll n,x; cin>>n>>x;
	cout<<bfs(x,n)<<"\n";
		
	return 0;
}
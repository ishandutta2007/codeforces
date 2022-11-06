#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll suma(ll x){
	ll res=0;
	while(x>0){
		res+=(x%2);
		x/=2;
	}
	return res;
}

//map<ll,ll> m;

int main(){FIN;
	ll n,k; cin>>n>>k;
	if(suma(n)>k){
		cout<<"No"; return 0;
	}
	priority_queue<ll> q;
	fore(i,0,60){
		if(n&(1ll<<i)){
			q.push(i);
		}
	}
	while(SZ(q)<k){
		ll t=q.top(); q.pop();
		q.push(t-1); q.push(t-1);
	}
	cout<<"Yes\n";
	/*while(SZ(q)){
		m[q.top()]++; q.pop();
	}
	ll s=m.end()->fst;*/
	ll s=q.top();
	vector<ll> v;
	ll dif=n;
	if(s<0)fore(i,0,-s)dif*=2;
	while(SZ(v)<k){
		if(dif>0){
			if(s>=0){
				if(dif-(1ll<<s)>=0){
					v.pb(s); dif-=(1ll<<s); 
				}else{
					s--; 
					if(s==-1)dif*=2;
					
				}
			}else{
				if(dif-1>=0){
					v.pb(s); dif--;
				}else{
					s--; dif*=2;
				}
			}	
		}else{
			ll b=v.back(); v.pop_back();
			v.pb(b-1); v.pb(b-1);	
		}
	}
	for(auto i:v)cout<<i<<" ";
	
	return 0;
}
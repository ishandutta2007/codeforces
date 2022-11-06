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
	ll n; cin>>n;
	ll a[n],b[n];
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i],b[i]--;
	ll res=0;
	vector<ll> resc;
	ll lle[n];
	mset(lle,0);
	fore(i,0,n){
		if(b[i]!=-2){
			lle[b[i]]++;
		}
	}
	queue<ll> q;
	fore(i,0,n){
		if(lle[i]==0)q.push(i);
	}
	vector<ll> va;
	while(SZ(q)){
		ll f=q.front(); q.pop();
		res+=a[f];
		if(a[f]>=0){
			resc.pb(f);
			if(b[f]!=-2){
				a[b[f]]+=a[f];
				lle[b[f]]--;
				if(lle[b[f]]==0)q.push(b[f]);
			}
		}else{
			va.pb(f);
			if(b[f]!=-2){
				lle[b[f]]--;
				if(lle[b[f]]==0)q.push(b[f]);
			}
		}
	}
	reverse(ALL(va));
	for(auto i:va)resc.pb(i);
	cout<<res<<"\n";
	for(auto i:resc)cout<<i+1<<" ";
	return 0;
}
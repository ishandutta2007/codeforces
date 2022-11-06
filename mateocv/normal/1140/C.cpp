#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,k; cin>>n>>k;
	pair<ll,ll>d[n];
	ll t,b;
	fore(i,0,n){
		cin>>t>>b;
		d[i].fst=b;
		d[i].snd=t;
	}
	sort(d,d+n);
//	fore(i,0,n)cout<<d[i].fst<<" "<<d[i].snd<<"\n";//cout<<"\n";
	
	ll D[n];
	priority_queue<ll,vector<ll>,greater<ll>> q;
	D[0]=0;
	for(ll i=n-1;i>=n-k+1;i--){
		D[n-i]=D[n-i-1]+d[i].snd;
		q.push(d[i].snd);
	}
	for(ll i=n-k;i>=1;i--){
		q.push(d[i].snd);
		D[n-i]=D[n-i-1]+d[i].snd-q.top();
		q.pop();
	}
	
//	fore(i,0,n)cout<<D[i]<<" ";cout<<"\n";
	ll res=0;
	fore(i,0,n){
		if(i<n-k+1){
			res=max(res,(D[n-1-i]+d[i].snd)*d[i].fst);
		//	cout<<(D[n-i-1]+d[i].snd)*d[i].fst<<" ";
		}else{
			res=max(res,(D[n-i])*d[i].fst);
		//	cout<<(D[n-i])*d[i].fst<<" ";
		}
	}
	cout<<res;
	return 0;
}
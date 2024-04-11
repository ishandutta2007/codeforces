#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	ll q; cin>>q;
	pair<ll,ll> r[q];
	ll b,c;
	fore(i,0,q){
		cin>>b>>c;
		r[i].fst=c-b+1;
		r[i].snd=i;
	}
	//fore(i,0,q)cout<<r[i].fst<<" "; cout<<"\n";
	sort(r,r+q);
	ll d[n-1];
	fore(i,0,n-1){
		d[i]=a[i+1]-a[i];
	}
	sort(d,d+n-1);
	ll va=0;
	ll par[n]; par[0]=0;
	fore(i,1,n){
		par[i]=par[i-1]+d[i-1];
	}
	//fore(i,0,n)cout<<par[i]<<" "; cout<<"\n";
	fore(i,0,q){
		while(r[i].fst>d[va]&&va<n-1)va++;
	//	cout<<r[i].fst<<" "<<(n-va)<<" "<<par[va]<<"\n";
		r[i].fst=r[i].fst*(n-va)+par[va]; //cout<<r[i].fst<<" ";
	}
	fore(i,0,q){
		swap(r[i].fst,r[i].snd);
	}
	sort(r,r+q);
	fore(i,0,q){
		cout<<r[i].snd<<" ";
	}
	
	return 0;
}
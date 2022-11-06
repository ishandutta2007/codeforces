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

pair<ll,ll> a[200005];
pair<ll,ll> dp[200005];

pair<ll,ll> f(ll n){
	if(n<0)return {0,0};
	pair<ll,ll> &r=dp[n];
	if(r.fst>=0)return r;
	if(n<=2){
		r={0,0}; return r;
	}
	r.fst=max(f(n-1).fst,f(n-3).fst+a[n].fst-a[n-1].fst);
	if(r.fst==f(n-3).fst+a[n].fst-a[n-1].fst){
		r.snd=f(n-3).snd+1;
	}else{
		r.snd=f(n-1).snd;
	}
	return r;
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i].fst,a[i].snd=i;
	sort(a,a+n);
	mset(dp,-1);
	//fore(i,0,n)cout<<f(i).fst<<" "<<f(i).snd<<"\n";
	cout<<a[n-1].fst-a[0].fst-f(n-3).fst<<" "<<f(n-3).snd+1<<"\n";
	ll res[n];
	vector<ll> v;
	ll va=f(n-3).snd;
	//cout<<va<<endl;
	ll i=n-3;
	while(va>0){
		if(f(i).fst==f(i-3).fst+a[i].fst-a[i-1].fst){
			//cout<<"Estoy en "<<i<<" me voy al "<<i-3<<"\n";
			v.pb(i);
			i-=3;
			va--;
		}else{
			//cout<<"Estoy en "<<i<<" me voy al "<<i-1<<"\n";
			i--;
		}
	}
	//for(auto i:v)cout<<i<<" "; cout<<"\n";
	ll c=1;
	//reverse(ALL(v));
	fore(i,0,n){
		if(SZ(v)&&i==v.back()){
			c++;
			v.pop_back();
		}
		res[a[i].snd]=c;
	}
	fore(i,0,n)cout<<res[i]<<" ";
	return 0;
}
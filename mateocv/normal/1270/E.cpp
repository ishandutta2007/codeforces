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
	pair<ll,ll> a[n];
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	fore(i,0,n)a[i].fst+=1000000,a[i].snd+=1000000;
	fore(k,0,28){
		vector<ll> res;
		fore(i,0,n){
			if((a[i].fst+a[i].snd)&1)res.pb(i);
		}
		if(SZ(res)!=0&&SZ(res)!=n){
			cout<<SZ(res)<<"\n";
			for(auto i:res)cout<<i+1<<" ";
			return 0;
		}
		if((a[0].fst+a[0].snd)&1){
			fore(i,0,n)a[i].fst++;
		}
		//fore(i,0,n)cout<<a[i].fst<<" "<<a[i].snd<<"\n";
		res.clear();
		fore(i,0,n){
			if((a[i].fst)&1)res.pb(i);
		}
		if(SZ(res)!=0&&SZ(res)!=n){
			cout<<SZ(res)<<"\n";
			for(auto i:res)cout<<i+1<<" ";
			return 0;
		}
		if((a[0].fst)%1){
			fore(i,0,n)a[i].fst++,a[i].snd++;
		}
		fore(i,0,n){
			a[i].fst/=2,a[i].snd/=2;
		}
		//fore(i,0,n)cout<<a[i].fst<<" "<<a[i].snd<<"\n";
	}
	fore(k,0,28){
		vector<ll> res;
		fore(i,0,n){
			if((a[i].fst-a[i].snd+2000000)&1)res.pb(i);
		}
		if(SZ(res)!=0&&SZ(res)!=n){
			cout<<SZ(res)<<"\n";
			for(auto i:res)cout<<i+1<<" ";
			return 0;
		}
		if((a[0].fst+a[0].snd)&1){
			fore(i,0,n)a[i].fst++;
		}
		//fore(i,0,n)cout<<a[i].fst<<" "<<a[i].snd<<"\n";
		res.clear();
		fore(i,0,n){
			if((a[i].fst)&1)res.pb(i);
		}
		if(SZ(res)!=0&&SZ(res)!=n){
			cout<<SZ(res)<<"\n";
			for(auto i:res)cout<<i+1<<" ";
			return 0;
		}
		if((a[0].fst)%1){
			fore(i,0,n)a[i].fst++,a[i].snd++,a[i].fst/=2,a[i].snd/=2;
		}
		//fore(i,0,n)cout<<a[i].fst<<" "<<a[i].snd<<"\n";
	}
	/*fore(k,0,28){
		vector<ll> res;
		fore(i,0,n){
			if((a[i].fst-a[i].snd+2000000)&(1ll<<k))res.pb(i);
		}
		if(SZ(res)!=0&&SZ(res)!=n){
			cout<<SZ(res)<<"\n";
			for(auto i:res)cout<<i+1<<" ";
			return 0;
		}
	}*/
	assert(0);
	return 0;
}
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

const int MAXN=200005;

pair<ll,ll> pre[2][MAXN],suf[2][MAXN];

pair<ll,ll> comb(pair<ll,ll> a, pair<ll,ll> b){
	return {max(a.fst+b.snd,b.fst),a.snd+b.snd};
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a[2];
		fore(k,0,2){
			a[k].resize(n);
			fore(i,0,n)cin>>a[k][i],a[k][i]++;
		}
		a[0][0]=0;
		fore(k,0,2){
			//pre[k][n-1]={a[k][n-1],1};
			pre[k][n]={0,0};
			for(ll i=n-1;i>=0;i--)pre[k][i]=comb({a[k][i],1},pre[k][i+1]);
			//cout<<"pre "<<k<<"\n";
			//fore(i,0,n)cout<<pre[k][i].fst<<" "<<pre[k][i].snd<<"\n";
			//suf[k][n-1]={a[k][n-1],1};
			suf[k][n]={0,0};
			for(ll i=n-1;i>=0;i--)suf[k][i]=comb(suf[k][i+1],{a[k][i],1});
			//cout<<"suf "<<k<<"\n";
			//fore(i,0,n)cout<<suf[k][i].fst<<" "<<suf[k][i].snd<<"\n";
		}
		
		pair<ll,ll> pos={0,0};
		ll res=2e9;
		pair<ll,ll> va={0,0}; 
		while(pos.snd<n){
			va=comb(va,{a[pos.fst][pos.snd],pos.fst!=0||pos.snd!=0});
			if(pos.snd&1){
				if(pos.fst==1)res=min(res,comb(va,comb(pre[1][pos.snd+1],suf[0][pos.snd])).fst),pos.fst--;
				else pos.snd++;
			}else{
				if(pos.fst==0)res=min(res,comb(va,comb(pre[0][pos.snd+1],suf[1][pos.snd])).fst),pos.fst++;
				else pos.snd++;
			}
			//cout<<pos.fst<<" "<<pos.snd<<" : "<<va.fst<<" "<<va.snd<<"\n";
		}
		res=min(res,va.fst);
		cout<<res<<"\n";
	}
	
	return 0;
}
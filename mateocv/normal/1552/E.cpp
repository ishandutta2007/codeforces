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

vector<pair<ll,ll>> res;

vector<ll> a;

pair<ll,ll> solve(ll pos){
	vector<ll> ul(110);
	fore(i,0,SZ(ul))ul[i]=-1;
	fore(i,pos,SZ(a)){
		if(a[i]==-1)continue;
		if(ul[a[i]]==-1){
			ul[a[i]]=i;
		}else{
			res[a[i]]={ul[a[i]],i};
			ll aa=a[i];
			fore(j,0,SZ(a)){
				if(a[j]==aa)a[j]=-1;
			}
			return {i+1,1};
		}
	}
	return {SZ(a),0};
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	a.resize(n*k);
	fore(i,0,n*k)cin>>a[i],a[i]--;
	res.resize(n);
	fore(i,0,n)res[i]={-1,-1};
	ll pos=0;
	ll tot=n;
	while(tot){
		auto s=solve(pos);
		pos=s.fst;
		tot-=s.snd;
		if(pos==SZ(a))pos=0;
		/*
		cout<<"res:\n";
		for(auto i:res)cout<<i.fst<<" "<<i.snd<<"\n";
		cout<<"a:\n";
		for(auto i:a)cout<<i<<" ";
		cout<<"\n";
		*/
	}
	for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	
	return 0;
}
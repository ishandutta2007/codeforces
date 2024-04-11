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

vector<ll> a;

ll solve(ll l, ll r, ll ofs){
	//cout<<"so "<<l<<" "<<r<<" "<<ofs<<endl;
	if(l+1==r)return 0;
	ll mini0=SZ(a),maxi0=-1;
	ll mini1=SZ(a),maxi1=-1;
	ll m=(l+r)/2;
	fore(i,l,m){
		mini0=min(mini0,a[i]+ofs);
		maxi0=max(maxi0,a[i]+ofs);
	}
	fore(i,m,r){
		mini1=min(mini1,a[i]+ofs);
		maxi1=max(maxi1,a[i]+ofs);
	}
	if(mini0==l&&maxi0==m-1&&mini1==m&&maxi1==r-1){
		auto sl=solve(l,m,ofs),sr=solve(m,r,ofs);
		if(sl==-1||sr==-1)return -1;
		return sl+sr;
	}
	if(mini0==m&&maxi0==r-1&&mini1==l&&maxi1==m-1){
		auto sl=solve(l,m,ofs-r+m),sr=solve(m,r,ofs+m-l);
		if(sl==-1||sr==-1)return -1;
		return sl+sr+1;
	}
	return -1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		a.clear();
		a.resize(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		cout<<solve(0,n,0)<<"\n";
	}
	
	return 0;
}
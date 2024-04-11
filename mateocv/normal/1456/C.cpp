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

ll a[500005];

ll n,k; 

vector<ll> v[2];

ll solve(ll m){
	ll res=0;
	assert(SZ(v[0])>=m&&(k+1)*m>=SZ(v[0]));
	if(m>0){
	/*	ll cant=SZ(v[0])%m;
		ll va=0,vam=0,ya=0,p=SZ(v[0])/m;
		if(!cant)ya=1;
		fore(i,0,SZ(v[0])){
			res+=va*v[0][i];
			vam++;
			if(ya){
				if(vam==p){
					va++; vam=0;
				}
			}else{
				if(vam==p+1){
					va++; vam=0;
					cant--;
					if(cant==0)ya=1;
				}
			}
		}
	*/
		vector<ll> mul;
		fore(i,0,m)mul.pb(i);
		fore(i,0,SZ(v[0])-m)mul.pb(i/k);
		sort(ALL(mul));
		fore(i,0,SZ(v[0]))res+=mul[i]*v[0][i];
	}
	fore(i,0,SZ(v[1]))res+=(m+i)*v[1][i];
	return res;
}

int main(){FIN;
	cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n){
		v[a[i]>=0].pb(a[i]);
	}
	fore(k,0,2)sort(ALL(v[k]));
	/*
	fore(i,(SZ(v[0])+k)/(k+1),SZ(v[0])+1){
		cout<<i<<" "<<solve(i)<<"\n";
	}
	*/
	ll l=(SZ(v[0])+k)/(k+1),r=SZ(v[0]);
	while(r-l>=3){
		//cout<<l<<" "<<r<<"\n";
		ll m=(l+r)/2;
		if(solve(m)<solve(m+1))l=m;
		else r=m+1;
	}
	//cout<<l<<" "<<r<<"\n";
	ll res=-(1ll<<60);
	fore(i,l,r+1)res=max(res,solve(i));
	cout<<res<<"\n";
	
	return 0;
}
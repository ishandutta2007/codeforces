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

string s; 

ll sump[100005][2];

ll get(ll l, ll r, ll d, ll s){
	ll res=sump[r][s]-sump[l][s];
	if(d==0)res=r-l-res;
	//cout<<l<<" "<<r<<" "<<d<<" "<<s<<" "<<res<<endl;
	return res;
}

int main(){FIN;
	cin>>s;
	ll x,y; cin>>x>>y;
	fore(i,0,SZ(s)){
		sump[i+1][0]=sump[i][0];
		sump[i+1][1]=sump[i][1];
		if(s[i]=='1'){
			sump[i+1][0]++;
			sump[i+1][1]++;
		}else if(s[i]=='?'){
			sump[i+1][1]++;
		}
	}
	/*
	fore(i,0,SZ(s)+1){
		cout<<sump[i][0]<<" ";
	}
	cout<<"\n";
	fore(i,0,SZ(s)+1){
		cout<<sump[i][1]<<" ";
	}
	cout<<"\n";
	*/
	ll res=9e18;
	//todo con ceros
	ll va=0;
	ll n=SZ(s);
	fore(i,0,SZ(s)){
		if(s[i]=='1'){
			va+=get(0,i,0,0)*x+get(i+1,n,0,0)*y;
		}else{
			va+=get(0,i,1,0)*y+get(i+1,n,1,0)*x;
		}
	}
	//cout<<va<<"\n";
	va/=2;
	res=min(res,va);
	fore(i,0,SZ(s)){
		if(s[i]=='?'){
			va-=get(0,i,1,1)*y+get(i+1,n,1,0)*x;
			va+=get(0,i,0,1)*x+get(i+1,n,0,0)*y;
		}
		res=min(res,va);
	}
	//todo unos
	va=0;
	fore(i,0,SZ(s)){
		if(s[i]=='1'||s[i]=='?'){
			va+=get(0,i,0,1)*x+get(i+1,n,0,1)*y;
		}else{
			va+=get(0,i,1,1)*y+get(i+1,n,1,1)*x;
		}
	}
	va/=2;
	res=min(res,va);
	fore(i,0,SZ(s)){
		if(s[i]=='?'){
			va+=get(0,i,1,0)*y+get(i+1,n,1,1)*x;
			va-=get(0,i,0,0)*x+get(i+1,n,0,1)*y;
		}
		res=min(res,va);
	}
	cout<<res<<"\n";
	
	return 0;
}
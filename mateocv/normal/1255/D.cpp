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

pair<ll,ll> next(ll i, ll j, ll r, ll c){
	if(i%2==0){
		if(j<c-1)return {i,j+1};
		else return {i+1,j};
	}else{
		if(j>0)return {i,j-1};
		else return {i+1,j};
	}
}

char next(char c){
	if(c=='z')return 'A';
	if(c=='Z')return '0';
	c++;
	return c;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll c,r,k; cin>>r>>c>>k;
		char t[r][c];
		ll tot=0;
		fore(i,0,r){
			fore(j,0,c){
				cin>>t[i][j];
				tot+=t[i][j]=='R';
			}	
		}
		vector<ll> v;
		fore(i,0,k){
			if(i<tot%k)v.pb(tot/k+1);
			else v.pb(tot/k);
		}
		//for(auto i:v)cout<<i<<" "; cout<<"\n";
		ll i=0,j=0;
		reverse(ALL(v));
		ll va='a';
		while(i<r&&j<c){
			if(t[i][j]=='.'){
				t[i][j]=va;
			}else{
				t[i][j]=va;
				if(SZ(v))v[SZ(v)-1]--;
				if(v.back()==0){
					v.pop_back();
					if(SZ(v))va=next(va);
				}
			}
			pair<ll,ll> p=next(i,j,r,c);
			i=p.fst; j=p.snd;
		}
		fore(i,0,r){
			fore(j,0,c){
				cout<<t[i][j];
			}
			cout<<"\n";
		}	
	}
	return 0;
}
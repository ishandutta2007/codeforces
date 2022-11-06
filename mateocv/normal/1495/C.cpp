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

char c[505][505];

ll n,m; 

void fix(ll pos){
	fore(j,0,m){
		if(c[pos][j]=='X'||c[pos+1][j]=='X'){
			c[pos][j]='X';
			c[pos+1][j]='X';
			return;
		}
	}
	c[pos][0]='X';
	c[pos+1][0]='X';
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		fore(i,0,n){
			fore(j,0,m)cin>>c[i][j];
		}
		ll r=1;
		if(n%3==1)r=0;
		fore(i,0,n){
			if(i%3==r){
				fore(j,0,m)c[i][j]='X';
			}
		}
		fore(i,0,n-1){
			if(i%3==(r+1)%3)fix(i);
		}
		fore(i,0,n){
			fore(j,0,m)cout<<c[i][j];
			cout<<"\n";
		}
	}
	
	return 0;
}
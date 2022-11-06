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

const int MAXN=1010;

ll a[MAXN][MAXN],b[MAXN][MAXN];

ll n;

void ver(ll j){
	fore(i,0,n)a[i][j]^=1;
}

void hor(ll i){
	fore(j,0,n)a[i][j]^=1;
}

bool eq(){
	fore(i,0,n){
		fore(j,0,n){
			if(a[i][j]!=b[i][j])return false;
		}
	}
	return true;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n){
			fore(j,0,n){
				char c; cin>>c;
				a[i][j]=c-'0';
			}
		}
		fore(i,0,n){
			fore(j,0,n){
				char c; cin>>c;
				b[i][j]=c-'0';
			}
		}
		fore(j,0,n){
			if(a[0][j]!=b[0][j])ver(j);
		}
		fore(i,1,n){
			if(a[i][0]!=b[i][0])hor(i);
		}
		if(eq())cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
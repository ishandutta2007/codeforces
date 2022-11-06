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
	ll r,c; cin>>r>>c;
	if(r==1&&c==1){
		cout<<0; return 0;
	}
	if(c==1){
		fore(i,0,r)cout<<i+2<<"\n";
		return 0;
	}
	fore(i,0,r){
		fore(j,0,c){
			cout<<(i+1)*(j+1+r)<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}
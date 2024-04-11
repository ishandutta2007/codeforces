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
	ll q; cin>>q;
	while(q--){
		ll c,m,x; cin>>c>>m>>x;
		if(m<=c)swap(c,m);
		if(x+m-c>=c){
			cout<<c<<"\n";
		}else{
			cout<<(x+c+m)/3<<"\n";
		}
	}
	
	return 0;
}
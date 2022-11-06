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
	ll n; cin>>n;
	vector<ll> v={1200,1400,1600,1900,2100,2300,2400,2600,3000};
	fore(i,0,SZ(v)){
		if(n<v[i]){
			cout<<v[i]<<"\n";
			break;
		}
	}
	
	return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll q; cin>>q;
	while(q--){
		ll k,n,a,b; cin>>k>>n>>a>>b;
		k-=b*n;
		if(k<=0){
			cout<<-1<<"\n"; continue;
		}
		cout<<min((k-1)/(a-b),n)<<"\n";
	}
	
	return 0;
}
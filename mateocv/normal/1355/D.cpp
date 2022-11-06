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
	ll n,s; cin>>n>>s;
	if(s>=2*n){
		cout<<"YES\n";
		fore(i,0,n-1)cout<<"2 ";
		cout<<s-2*(n-1)<<"\n";
		cout<<1;
		return 0;
	}else{
		cout<<"NO";
	}
	
	return 0;
}
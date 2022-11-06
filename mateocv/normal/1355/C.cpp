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
	ll a,b,c,d; cin>>a>>b>>c>>d;
	ll res=0;
	fore(i,a+b,b+c+1){
		ll tot=min(min(i-a-b,b+c-i),min(b-a,c-b))+1;
		res+=tot*min(max(0ll,i-c),d-c+1);
	}
	cout<<res<<"\n";
	return 0;
}
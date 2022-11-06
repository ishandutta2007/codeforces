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
	ll n,x; cin>>n>>x;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	//sort(ALL(a));
	vector<ll> c(x+10,0);
	for(auto i:a)c[i]++;
	ll res=1;
	fore(i,1,x){
		if(c[i]%(i+1))res=0;
		c[i+1]+=c[i]/(i+1);
	}
	if(res)cout<<"Yes\n";
	else cout<<"No\n";
	
	return 0;
}
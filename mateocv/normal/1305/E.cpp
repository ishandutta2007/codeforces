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
	ll n,m; cin>>n>>m;
	ll tot=0;
	/*fore(i,2,n+1){
		tot+=(i-1)/2;
	}
	cout<<tot<<endl;*/
	ll cap[n];
	mset(cap,0);
	fore(i,0,n)cap[i]=i/2;
	ll va=0;
	ll res[n];
	ll M=2e4+10;
	fore(i,0,n){
		if(va==m){
			res[i]=1e9-M*M+M*i;
		}else if(va+cap[i]<m){
			res[i]=i+1;
			va+=cap[i];
		}else{
			res[i]=i+1+2*(cap[i]-(m-va));
			va=m;
		}
	}
	if(va<m){
		cout<<-1; return 0;
	}
	fore(i,0,n)cout<<res[i]<<" ";
	return 0;
}
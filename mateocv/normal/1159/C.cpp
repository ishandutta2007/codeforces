#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
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
	ll n,m; cin>>n>>m;
	ll b[n],g[m];
	fore(i,0,n)cin>>b[i];
	fore(i,0,m)cin>>g[i];
	ll maxb=0,sumb=0,maxb2=0,ya=0;
	fore(i,0,n)maxb=max(maxb,b[i]);
	fore(i,0,n){
		if(b[i]==maxb&&ya==0){
			ya++;
		}else{
			maxb2=max(maxb2,b[i]);
		}
	}
	fore(i,0,n)sumb+=b[i];
	ll r[m];
	ll res=sumb*m;
	ya=0;
	fore(i,0,m){
		if(maxb>g[i]){
			cout<<-1; return 0;
		}else{
			res+=g[i]-maxb;
			if(g[i]==maxb)ya++;
		}
	}
	if(ya==0){
		res+=maxb-maxb2;
	}
	cout<<res;
	return 0;
}
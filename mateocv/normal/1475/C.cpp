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

const int MAXN=200005;

ll ca[MAXN],cb[MAXN];

pair<ll,ll> p[MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,b,k; cin>>a>>b>>k;
		fore(i,0,k)cin>>p[i].fst,p[i].fst--;
		fore(i,0,k)cin>>p[i].snd,p[i].snd--;
		fore(i,0,a)ca[i]=0;
		fore(i,0,b)cb[i]=0;
		//fore(i,0,k)cout<<p[i].fst<<" "<<p[i].snd<<"\n";
		fore(i,0,k){
			ca[p[i].fst]++;
			cb[p[i].snd]++;
		}
		//fore(i,0,a)cout<<ca[i]<<" "; cout<<"\n";
		//fore(i,0,b)cout<<cb[i]<<" "; cout<<"\n";
		ll res=0;
		fore(i,0,k)res+=k+1-ca[p[i].fst]-cb[p[i].snd];
		cout<<res/2<<"\n";
	}
	
	return 0;
}
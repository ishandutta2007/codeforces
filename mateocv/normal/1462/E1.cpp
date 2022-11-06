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
ll a[MAXN],c[MAXN];

ll tom(ll n, ll k){
	ll res=1;
	fore(i,0,k)res*=(n-i);
	fore(i,0,k)res/=i+1;
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n+2)c[i]=0;
		fore(i,0,n)c[a[i]]++;
		ll res=0;
		fore(i,0,n){
			res+=tom(c[i],3);
			res+=tom(c[i],2)*c[i+1];
			res+=tom(c[i+1],2)*c[i];
			res+=tom(c[i],2)*c[i+2];
			res+=tom(c[i+2],2)*c[i];
			res+=c[i]*c[i+1]*c[i+2];
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
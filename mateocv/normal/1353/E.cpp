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

ll n,k; 
string s;

ll sump[1000006];

ll dp[1000006];

ll f(ll x){
	ll &r=dp[x];
	if(r>=0)return r;
	r=0;
	if(s[x]=='0')r++;
	if(x-k+1>=0)r+=min(sump[x],f(x-k)+sump[x]-sump[x-k+1]);
	else r+=sump[x];
	//cout<<x<<" "<<r<<endl;
	return r;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k>>s;
		fore(i,0,n){
			sump[i+1]=sump[i]+(s[i]=='1');
		}
		fore(i,0,n)dp[i]=-1;
		ll res=n;
		fore(i,0,n)res=min(res,f(i)+sump[n]-sump[i+1]);
		res=min(res,sump[n]);
		cout<<res<<"\n";
	}
	
	return 0;
}
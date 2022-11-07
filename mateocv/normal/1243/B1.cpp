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
	ll q; cin>>q;
	while(q--){
	    ll n; cin>>n;
	    string s,t; cin>>s>>t;
	    ll res=0;
	    fore(i,0,n){
	        res+=(s[i]==t[i]);
	    }
	    if(res==n){
	       cout<<"Yes\n";
	    }else if(res==n-2){
	        vector<ll>v;
	        fore(i,0,n){
	            if(s[i]!=t[i]){
	                v.pb(i);
	            }   
	        }
	        if(s[v[0]]==s[v[1]]&&t[v[0]]==t[v[1]])cout<<"Yes\n";
	        else cout<<"No\n";
	    }else{
	        cout<<"No\n";
	    }
	}
	return 0;
}
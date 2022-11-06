#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;


int main(){FIN;
    ll t; cin>>t;
    while(t--){
        ll a,b; cin>>a>>b;
        ll r=abs(a-b);
        ll res=r/5;
        if(r%5==1||r%5==2){
            res++;
        }else if(r%5==3||r%5==4){
            res++; res++;
        }
        cout<<res<<"\n";
    }
	return 0;
}
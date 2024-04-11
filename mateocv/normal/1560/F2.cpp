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

ll cant(string s){
	ll mk=0;
	for(auto i:s)mk=(mk|(1ll<<(i-'0')));
	return __builtin_popcount(mk);
}

ll solve(ll n, ll k){
	string s=to_string(n);
	ll res=1e18;
	ll mk=0;
	fore(i,0,SZ(s)){
		if(s[i]!='9'){
			vector<ll> d={s[i]-'0'+1};
			fore(jj,s[i]-'0'+1,10){
				if((1ll<<jj)&mk){
					d.pb(jj);
					break;
				}
			}
			for(auto jj:d){
				auto ss=s;
				ss[i]='0'+jj;
				vector<ll> dd={0,jj};
				fore(ii,0,10){
					if((1ll<<ii)&mk){
						dd.pb(ii);
						break;
					}
				}
				for(auto ii:dd){
					fore(j,i+1,SZ(s))ss[j]='0'+ii;
					if(cant(ss)<=k)res=min(res,stoll(ss));
				}
			}
		}
		mk=(mk|(1ll<<(s[i]-'0')));
	}
	string ss="1";
	fore(i,0,SZ(s))ss+="0";
	if(cant(ss)<=k)res=min(res,stoll(ss));
	ss="1";
	fore(i,0,SZ(s))ss+="1";
	if(cant(ss)<=k)res=min(res,stoll(ss));
	if(cant(s)<=k)res=min(res,stoll(s));
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		cout<<solve(n,k)<<"\n";
	}
	
	return 0;
}
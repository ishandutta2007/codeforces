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
	ll n; cin>>n;
	string s,t; cin>>s>>t;
	if(s==t){
		cout<<0;
		return 0;
	}
	deque<ll> r;
	ll sum=0;
	fore(i,0,n){
		sum+=s[i]-t[i];
	}
	if(sum!=0){
		cout<<-1; return 0;
	}
	fore(i,0,n){
		if(s[i]!=t[i]){
			r.pb(s[i]=='1');
		}
	}
	deque<ll> d;
	ll sal=0;
	while(SZ(r)){
		if(sal>=0){
			ll f=r.front();
			d.pb(f);
			if(f)sal--;
			else sal++;
			r.pop_front();
		}else{
			ll b=r.back();
			d.push_front(b);
			if(b)sal--;
			else sal++;
			r.pop_back();
		}
	}
	ll res=0,va=0;
	for(auto i:d){
		if(i==0){
			va++; res=max(res,abs(va));
		}else if(i==1){
			va--; res=max(res,abs(va));
		}
	}
	cout<<res;
	return 0;
}
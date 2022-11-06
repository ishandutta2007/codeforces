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

ll solve(string s){
	ll a=0,b=0;
	fore(i,0,10){
		if(s[i]=='1'){
			if(i&1)b++;
			else a++;
		}
		ll aa=a,bb=b;
		fore(j,i+1,10){
			if(j&1)bb++;
		}
		if(aa>bb)return i+1;
		aa=a,bb=b;
		fore(j,i+1,10){
			if(!(j&1))aa++;
		}
		if(bb>aa)return i+1;
	}
	return 10;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		string s0=s,s1=s;
		fore(i,0,10){
			if(s[i]=='?'){
				if(i&1)s0[i]='1',s1[i]='0';
				else s0[i]='0',s1[i]='1';
			}
		}
		ll res=min(solve(s0),solve(s1));
		cout<<res<<"\n";
	}
	
	return 0;
}
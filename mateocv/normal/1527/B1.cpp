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

ll cant(string s, char c){
	ll res=0;
	for(auto i:s)res+=(i==c);
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		ll c=cant(s,'0');
		if(c==0){
			cout<<"DRAW\n";
		}else{
			if(n%2==1&&s[n/2]=='0'){
				if(c==1)cout<<"BOB\n";
				else cout<<"ALICE\n";
			}else cout<<"BOB\n";
		}
	}
	
	return 0;
}
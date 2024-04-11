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
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll st=-1,en=-1;
		fore(i,0,SZ(s)){
			if(s[i]=='1'){
				st=i; break;
			}
		}
		fore(i,0,SZ(s)){
			if(s[SZ(s)-1-i]=='1'){
				en=SZ(s)-1-i; break;
			}
		}
		if(st==-1&&en==-1){
			cout<<"0\n"; continue;
		}
		ll res=0;
		fore(i,st,en+1){
			res+=(s[i]=='0');
		}
		cout<<res<<"\n";
	}
	
	
	return 0;
}
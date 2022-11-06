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

bool isr(string s){
	ll c=0;
	for(auto i:s){
		if(i=='(')c++;
		else c--;
		if(c<0)return 0;
	}
	return c==0;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll br=0;
		fore(m,0,8){
			string t(SZ(s),'.');
			fore(i,0,SZ(s)){
				if(s[i]=='A'){
					if(m&1)t[i]='(';
					else t[i]=')';
				}else if(s[i]=='B'){
					if(m&2)t[i]='(';
					else t[i]=')';
				}else if(s[i]=='C'){
					if(m&4)t[i]='(';
					else t[i]=')';
				}
			}
			if(isr(t)){
				br++; break;
			}
		}
		if(br)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
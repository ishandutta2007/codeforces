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
		ll br=0;
		fore(i,0,SZ(s)-1){
			if(s[i]==s[i+1]&&s[i]!='?'){
				br++; break;
			}
		}
		if(br){
			cout<<"-1\n";
			continue;
		}
		fore(i,0,SZ(s)){
			if(s[i]=='?'){
				fore(k,0,3){
					if((i==0||s[i-1]!='a'+k)&&(i==SZ(s)-1||s[i+1]!='a'+k)){
						s[i]='a'+k; break;
					}
				}
			}
		}
		cout<<s<<"\n";
	}
	
	return 0;
}
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
		string a,s; cin>>a>>s;
		reverse(ALL(a));
		reverse(ALL(s));
		string res;
		ll ul=0,br=0;
		fore(i,0,SZ(a)){
			if(ul>=SZ(s)){
				br++; break;
			}
			if(a[i]<=s[ul]){
				res+='0'+s[ul]-a[i];
				ul++;
			}else{
				if(ul+1>=SZ(s)||s[ul+1]!='1'){
					br++; break;
				}
				res+='0'+10+s[ul]-a[i];
				ul+=2;
			}
		}
		if(br){
			cout<<"-1\n";
			continue;
		}
		while(ul<SZ(s))res+=s[ul],ul++;
		while(SZ(res)&&res.back()=='0')res.pop_back();
		reverse(ALL(res));
		cout<<res<<"\n";
	}
	
	return 0;
}
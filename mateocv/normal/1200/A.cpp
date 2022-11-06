#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	string res="0000000000";
	fore(i,0,SZ(s)){
		if(s[i]=='L'){
			fore(j,0,10){
				if(res[j]=='0'){
					res[j]='1'; break;
				}
			}
		}else if(s[i]=='R'){
			fore(j,0,10){
				if(res[9-j]=='0'){
					res[9-j]='1'; break;
				}
			}
		}else{
			res[s[i]-'0']='0';
		}
	}
	cout<<res;
	
	return 0;
}
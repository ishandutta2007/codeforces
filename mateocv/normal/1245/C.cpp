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

ll f[100005];
const ll MOD=1000000007;

int main(){FIN;
	string s; cin>>s;
	fore(i,0,SZ(s)){
		if(s[i]=='m'||s[i]=='w'){
			cout<<0; return 0;
		}
	}
	f[0]=1;
	f[1]=1;
	fore(i,2,100005){
		f[i]=(f[i-1]+f[i-2])%MOD;
	}
	vector<ll> v;
	char va='.'; ll van='0';
	fore(i,0,SZ(s)){
		if(s[i]==va){
			van++;
		}else{
			if(va=='u'||va=='n'){
				v.pb(van);
			}
			van=1;
			va=s[i];
		}
		if(i==SZ(s)-1){
			if(va=='u'||va=='n'){
				v.pb(van);
			}
		}
	}
	ll res=1;
	fore(i,0,SZ(v)){
		res*=f[v[i]];
		res%=MOD;
	}
	cout<<res;
	return 0;
}
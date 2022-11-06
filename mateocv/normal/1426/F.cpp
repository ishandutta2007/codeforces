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

ll n; 
string s;
ll MOD=1000000007;

int main(){FIN;
	cin>>n>>s;
	ll cant[4]={1,0,0,0};
	fore(i,0,n){
		if(s[i]=='c'){
			cant[3]=(cant[3]+cant[2])%MOD;
		}
		if(s[i]=='b'){
			cant[2]=(cant[2]+cant[1])%MOD;
		}
		if(s[i]=='a'){
			cant[1]=(cant[1]+cant[0])%MOD;
		}
		if(s[i]=='?'){
			cant[3]=(3ll*cant[3]+cant[2])%MOD;
			cant[2]=(3ll*cant[2]+cant[1])%MOD;
			cant[1]=(3ll*cant[1]+cant[0])%MOD;
			cant[0]=(3ll*cant[0])%MOD;
		}
		//fore(j,0,4)cout<<cant[j]<<" "; cout<<"\n";
	}
	cout<<cant[3]<<"\n";
	
	return 0;
}
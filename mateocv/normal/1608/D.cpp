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

const ll MOD=998244353;

const int MAXN=200005;

ll fact[MAXN],facti[MAXN];

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

ll comb(ll n, ll k){
	if(k>n||n<0||k<0)return 0;
	return fact[n]*(facti[k]*facti[n-k]%MOD)%MOD;
}

int main(){FIN;
	fact[0]=1;
	fore(i,1,MAXN)fact[i]=fact[i-1]*i%MOD;
	fore(i,0,MAXN)facti[i]=fpow(fact[i],MOD-2);
	ll n; cin>>n;
	ll cb[2]={0,0};
	ll cw[2]={0,0};
	ll cant=1;
	fore(i,0,n){
		string s; cin>>s;
		if(s[1]=='B')s[1]='W';
		else if(s[1]=='W')s[1]='B';
		fore(k,0,2){
			if(s[k]=='B')cb[k]++;
			if(s[k]=='W')cw[k]++;
		}
		if(s[0]!='?'&&s[1]!='?'&&s[0]!=s[1])cant=cant*0%MOD;
		if(s[0]==s[1]&&s[0]=='?')cant=cant*2%MOD;
	}
	ll res=0;
	fore(i,0,n+1){
		ll t=1;
		t=t*comb(n-cb[0]-cw[0],i-cb[0])%MOD;
		t=t*comb(n-cb[1]-cw[1],i-cb[1])%MOD;
		res=(res+t)%MOD;
	}
	//cout<<res<<"\n";
	res=(res+MOD-cant)%MOD;
	//cout<<res<<"\n";
	if(cb[0]+cb[1]==0)res=(res+1)%MOD;
	if(cw[0]+cw[1]==0)res=(res+1)%MOD;
	cout<<res<<"\n";
	return 0;
}
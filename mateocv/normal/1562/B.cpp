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

bool isp(ll n){
	if(n==1)return 0;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0)return 0;
	}
	return 1;
}

const int MAXN=10004;

ll esp[MAXN];

int main(){FIN;
	fore(i,1,MAXN)esp[i]=isp(i);
	ll t; cin>>t;
	while(t--){
		ll k; cin>>k;
		string s; cin>>s;
		vector<ll> c(10);
		for(auto i:s)c[i-'0']++;
		ll br=0;
		fore(i,1,10){
			ll mini=esp[i]+1;
			if(mini>1)continue;
			if(c[i]>=mini){
				cout<<mini<<"\n";
				fore(_,0,mini)cout<<char('0'+i);
				cout<<"\n";
				br++; break;
			}
		}
		if(br)continue;
		fore(i,1,10){
			ll mini=esp[i]+1;
			if(c[i]>=mini){
				cout<<mini<<"\n";
				fore(_,0,mini)cout<<char('0'+i);
				cout<<"\n";
				br++; break;
			}
		}
		if(br)continue;
		string res="1111111111111";
		fore(i,1,(1ll<<k)){
			string ss;
			fore(j,0,k){
				if((1ll<<j)&i)ss+=s[j];
			}
			if(!esp[stoll(ss)]){
				if(SZ(ss)<SZ(res))res=ss;
			}
		}
		cout<<SZ(res)<<"\n"<<res<<"\n";
	}
	
	return 0;
}
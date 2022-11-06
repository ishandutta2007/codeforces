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

ll getca[22];

ll get(string s, ll mk){
	ll res=1;
	fore(i,0,SZ(s)){
		ll cant=s[i]-'0';
		if(i-2>=0&&(1ll<<(i-2))&mk)cant+=10;
		if((1ll<<i)&mk){
			if(cant==0)return 0;
			cant--;
		}
		res*=getca[cant];
	}
	return res;
}

int main(){FIN;
	fore(i,0,20){
		fore(j,0,10){
			if(i-j>=0&&i-j<10)getca[i]++;
		}
	}
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll res=get(s,0)-2;
		if(SZ(s)>=3){
			fore(i,1,(1ll<<(SZ(s)-2))){
				res+=get(s,i);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
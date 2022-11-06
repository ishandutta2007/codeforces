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

ll pares(string s){
	ll res=0;
	fore(i,0,SZ(s)){
		if((s[i]-'0')%2==0)res++;
	}
	return res;
}

ll ceros(string s){
	ll res=0;
	fore(i,0,SZ(s)){
		if((s[i]-'0')==0)res++;
	}
	return res;
}

ll tres(string s){
	ll res=0;
	fore(i,0,SZ(s)){
		res+=s[i]-'0';
	}
	return res%3;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		if(pares(s)>=2&&ceros(s)&&tres(s)==0){
			cout<<"red\n";
		}else{
			cout<<"cyan\n";
		}
	}
	
	return 0;
}
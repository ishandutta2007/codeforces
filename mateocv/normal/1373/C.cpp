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
/*
ll brute(string s){
	ll res = 0;
	fore(i,0,1000000000){
		ll cur = i;
		bool ok = true;
		fore(i,0,SZ(s)){
			res = res + 1;
	        if(s[i] == '+')cur = cur + 1;
	        else cur = cur - 1;
	        if(cur < 0){
	        	ok = false;
	            break;
	        }  	
		} 
	    if(ok)break;
	}
    return res;
}*/

vector<ll> mini(string s){
	ll va=0;
	set<ll> st;
	vector<ll> res;
	fore(i,0,SZ(s)){
		if(s[i]=='-')va--;
		else va++;
		if(!st.count(va)&&va<0){
			st.insert(va);
			res.pb(i);
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll res=0;
		auto v=mini(s);
		for(auto i:v)res+=i+1;
		res+=SZ(s);
		cout<<res<<"\n";
	}
	
	return 0;
}
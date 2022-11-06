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

string filt(string s, char c){
	string res;
	for(auto i:s){
		if(i!=c)res+=i;
	}
	return res;
}

vector<ll> cont(string s, char c){
	vector<ll> res;
	ll va=0;
	for(auto i:s){
		if(i!=c)res.pb(va);
		else va++;
	}
	return res;
}

int main(){FIN;
	ll tt; cin>>tt;
	while(tt--){
		ll n; cin>>n;
		string s,t; cin>>s>>t;
		auto fs=filt(s,'b');
		auto ft=filt(t,'b');
		if(fs!=ft){
			cout<<"NO\n";
			continue;
		}
		auto cs=cont(s,'b');
		auto ct=cont(t,'b');
		ll br=0;
		fore(i,0,SZ(fs)){
			if(fs[i]=='a'&&cs[i]>ct[i])br++;
			if(fs[i]=='c'&&cs[i]<ct[i])br++;
		}
		if(br)cout<<"NO\n";
		else cout<<"YES\n";
	}
	
	return 0;
}
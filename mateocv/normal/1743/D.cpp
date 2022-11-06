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
	ll n; cin>>n;
	string s; cin>>s;
	reverse(ALL(s));
	while(SZ(s)&&s.back()=='0')s.pop_back();
	reverse(ALL(s));
	if(SZ(s)==0){
		cout<<"0\n";
		return 0;
	}
	vector<ll> v;
	fore(i,0,SZ(s)){
		if(s[i]=='0')v.pb(i);
	}
	if(SZ(v)==0){
		cout<<s<<"\n";
		return 0;
	}
	string res=s;
	fore(i,0,v[0]){
		ll d=v[0]-i;
		string t=s;
		fore(_,0,d)t.pop_back();
		string va=s;
		fore(i,0,SZ(t)){
			if(t[SZ(t)-1-i]=='1'){
				va[SZ(s)-1-i]='1';
			}
		}
		res=max(res,va);
	}
	cout<<res<<"\n";
	
	return 0;
}
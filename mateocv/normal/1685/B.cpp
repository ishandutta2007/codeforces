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
	ll t; cin>>t;
	while(t--){
		ll a,b,c,d; cin>>a>>b>>c>>d;
		string s; cin>>s;
		ll cant[2]={0,0};
		fore(i,0,SZ(s)){
			cant[s[i]=='B']++;
		}
		if(a+c+d!=cant[0]||b+c+d!=cant[1]){
			cout<<"NO\n";
			continue;
		}
		vector<string> v={string(1,s[0])};
		fore(i,1,SZ(s)){
			if(v.back().back()!=s[i])v.back()+=s[i];
			else v.pb(string(1,s[i]));
		}
		vector<ll> vc[3];
		for(auto i:v){
			if(!(SZ(i)&1))vc[i[0]=='B'].pb((SZ(i)-1)/2);
			else vc[2].pb((SZ(i)-1)/2);
		}
		ll su=0;
		fore(k,0,3){
			for(auto i:vc[k])su+=i;
		}
		if(c+d<=su){
			cout<<"YES\n";
			continue;
		}
		fore(k,0,2)sort(ALL(vc[k]));
		ll tot=c+d-su;
		vector<ll> sump[2]={{0},{0}};
		fore(k,0,2){
			for(auto i:vc[k])sump[k].pb(sump[k].back()+i);
		}
		ll res=0;
		fore(i,0,SZ(vc[0])+1){
			ll j=max(0ll,tot-i);
			if(j>SZ(vc[1]))continue;
			if(max(0ll,c-i-sump[0][i])+max(0ll,d-j-sump[1][j])<=su-sump[0][i]-sump[1][j]){
				res++;
			}
		}
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
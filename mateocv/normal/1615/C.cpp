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

ll INF=1e18;

ll cont(string s){
	return count(ALL(s),'1');
}

ll solve(string a, string b){
	ll res=0;
	fore(i,0,SZ(a))res+=(a[i]!=b[i]);
	if(res&1)res=INF;
	return res;
}

string tr(string s, ll pos){
	fore(i,0,SZ(s)){
		if(i!=pos)s[i]^='0'^'1';
	}
	return s;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string a,b; cin>>a>>b;
		ll res=INF;
		auto ca=cont(a),cb=cont(b);
		if(ca==cb){
			res=min(res,solve(a,b));
		}
		if(1+n-1-(ca-1)==cb){
			ll pos[2]={-1,-1};
			fore(i,0,SZ(a)){
				if(a[i]=='1'){
					pos[b[i]-'0']=i;
				}
			}
			fore(k,0,2){
				if(pos[k]!=-1)res=min(res,solve(tr(a,pos[k]),b)+1);
			}
		}
		if(res<INF)cout<<res<<"\n";
		else cout<<"-1\n";
	}
	
	return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll q; cin>>q;
	while(q--){
		ll n,m; cin>>n>>m;
		char t[n][m];
		fore(i,0,n){
			fore(j,0,m){
				cin>>t[i][j];
			}
		}
		set<ll> c,f;
		ll maxc=0,maxf=0;
		fore(i,0,n){
			ll tot=0;
			fore(j,0,m)tot+=(t[i][j]=='*');
			if(tot>maxf){
				f.clear();
				f.insert(i);
				maxf=tot;
			}else if(tot==maxf){
				f.insert(i);
			}
		}
		fore(j,0,m){
			ll tot=0;
			fore(i,0,n)tot+=(t[i][j]=='*');
			if(tot>maxc){
				c.clear();
				c.insert(j);
				maxc=tot;
			}else if(tot==maxc){
				c.insert(j);
			}
		}
		ll br=0;
		//cout<<"Set c tiene: "; for(auto i:c)cout<<i<<" "; cout<<"\n";
		//cout<<"Set f tiene: "; for(auto j:f)cout<<j<<" "; cout<<"\n";
		for(auto i:f){
			for(auto j:c){
				if(t[i][j]=='.'){
					cout<<n+m-maxf-maxc-1<<"\n";
					br++; break;
				}
			}
			if(br)break;
		}
		if(br)continue;
		else{
			cout<<n+m-maxf-maxc<<"\n";
			//cout<<"Ya lo vemos\n";
		}
	}
	
	return 0;
}
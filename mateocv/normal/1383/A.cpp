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
		ll n; cin>>n;
		string a,b; cin>>a>>b;
		ll tot=0;
		fore(i,0,n){
			tot+=(a[i]>b[i]);
		}
		if(tot){
			cout<<-1<<"\n";
			continue;
		}
		set<char> st[26];
		fore(i,0,n){
			if(a[i]!=b[i]){
				st[a[i]-'a'].insert(b[i]);
			}
		}
		ll res=0;
		fore(i,0,26){
			if(SZ(st[i])){
				res++;
				char c=*st[i].begin();
				st[i].erase(c);
				for(auto j:st[i]){
					st[c-'a'].insert(j);
				}	
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
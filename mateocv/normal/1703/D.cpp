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
		vector<string> a(n);
		set<string> st;
		fore(i,0,n){
			cin>>a[i];
			st.insert(a[i]);
		}
		string res;
		fore(i,0,n){
			ll br=0;
			fore(j,1,SZ(a[i])){
				if(st.count(a[i].substr(0,j))&&st.count(a[i].substr(j,SZ(a[i])-j)))br++;
			}
			if(br)res+='1';
			else res+='0';
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
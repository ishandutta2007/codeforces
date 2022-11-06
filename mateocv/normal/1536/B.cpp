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
	vector<string> v;
	fore(i,0,26){
		string s;
		s+='a'+i;
		v.pb(s);
	}
	fore(i,0,26){
		fore(j,0,26){
			string s;
			s+='a'+i;
			s+='a'+j;
			v.pb(s);
		}
	}
	fore(i,0,26){
		fore(j,0,26){
			fore(k,0,26){
				string s;
				s+='a'+i;
				s+='a'+j;
				s+='a'+k;
				v.pb(s);
			}
		}
	}
	//sort(ALL(v));
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		set<string> st;
		fore(i,0,n){
			string ss;
			ss+=s[i];
			st.insert(ss);
			if(i+1<n)ss+=s[i+1];
			st.insert(ss);
			if(i+2<n)ss+=s[i+2];
			st.insert(ss);
		}
		for(auto i:v){
			if(!st.count(i)){
				cout<<i<<"\n";
				break;
			}
		}
	}
	
	return 0;
}
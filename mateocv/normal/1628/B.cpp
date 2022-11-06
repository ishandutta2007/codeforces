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

string rev(string s){
	reverse(ALL(s));
	return s;
}

bool ispal(string s){
	return s==rev(s);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<string> s(n);
		fore(i,0,n)cin>>s[i];
		ll br=0;
		for(auto i:s){
			if(ispal(i)){
				br++;
				break;
			}
		}
		if(br){
			cout<<"YES\n";
			continue;
		}
		map<string,ll> mp,mpl;
		fore(i,0,SZ(s)){
			mp[s[i]]=i;
			if(!mpl.count(s[i]))mpl[s[i]]=i;
		}
		for(auto i:s){
			if(mp.count(rev(i))){
				br++;
				break;
			}
		}
		if(br){
			cout<<"YES\n";
			continue;
		}
		fore(i,0,SZ(s)){
			if(SZ(s[i])==3){
				string s0=s[i],s1=s[i];
				s0.pop_back();
				s0=rev(s0);
				s1=rev(s1);
				s1.pop_back();
				if(mp.count(s0)&&mp[s0]>i){
					br++;
					break;
				}
				if(mp.count(s1)&&mpl[s1]<i){
					br++;
					break;
				}
			}
		}
		if(br){
			cout<<"YES\n";
			continue;
		}
		cout<<"NO\n";
	}
	
	return 0;
}
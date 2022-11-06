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

string gen(string s, string ord){
	string res;
	fore(i,0,SZ(ord)){
		res+=s;
		string ss;
		fore(j,0,SZ(s)){
			if(s[j]!=ord[i])ss+=s[j];
		}
		s=ss;
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		set<char> vis;
		string ord;
		reverse(ALL(s));
		vector<ll> c(26);
		for(auto i:s){
			if(!vis.count(i)){
				vis.insert(i);
				ord+=i;
			}
			c[i-'a']++;
		}
		reverse(ALL(s));
		ll tot=0;
		reverse(ALL(ord));
		ll br=0;
		fore(i,0,SZ(ord)){
			if(c[ord[i]-'a']%(i+1)!=0){
				br++; break;
			}
			tot+=c[ord[i]-'a']/(i+1);
		}
		if(br){
			cout<<"-1\n";
			continue;
		}
		string ss;
		fore(i,0,tot)ss+=s[i];
		if(gen(ss,ord)==s){
			cout<<ss<<" "<<ord<<"\n";
		}else{
			cout<<"-1\n";
		}
	}
	
	return 0;
}
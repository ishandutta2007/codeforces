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

string solve(string s){
	string res;
	vector<ll> c(26);
	for(auto i:s)c[i-'a']++;
	fore(i,0,26){
		if(c[i]==1){
			res+='a'+i;
			c[i]--;
			fore(j,0,26){
				fore(_,0,c[j])res+='a'+j;
			}
			return res;
		}
	}
	ll a=-1;
	fore(i,0,26){
		if(c[i]){
			a=i;
			break;
		}
	}
	ll b=-1;
	fore(i,0,26){
		if(c[i]&&i!=a){
			b=i;
			break;
		}
	}
	if(b==-1){
		fore(i,0,c[a])res+='a'+a;
		return res;
	}
	if(c[a]>=2){
		ll s=0;
		fore(i,a+1,26)s+=c[i];
		if(c[a]-2<=s){
			vector<ll> v;
			fore(i,a+1,26){
				fore(j,0,c[i])v.pb(i);
			}
			reverse(ALL(v));
			res+='a'+a;
			res+='a'+a;
			c[a]-=2;
			fore(i,0,c[a]){
				res+='a'+v.back();
				res+='a'+a;
				v.pop_back();
			}
			while(SZ(v)){
				res+='a'+v.back();
				v.pop_back();
			}
			return res;
		}
	}
	ll d=-1;
	fore(i,0,26){
		if(c[i]&&i!=a&&i!=b){
			d=i;
			break;
		}
	}
	res+='a'+a;
	res+='a'+b;
	c[a]--;
	c[b]--;
	if(d==-1){
		fore(_,0,c[b])res+='a'+b;
		fore(_,0,c[a])res+='a'+a;
		return res;
	}
	fore(_,0,c[a])res+='a'+a;
	res+='a'+d;
	c[d]--;
	fore(_,0,c[b])res+='a'+b;
	fore(i,b+1,26){
		fore(_,0,c[i])res+='a'+i;
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		cout<<solve(s)<<"\n";
	}
	
	return 0;
}
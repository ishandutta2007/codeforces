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

vector<pair<ll,string>> res;
vector<char> v,dc;

string gets(){
	string res;
	if(SZ(v)<=10){
		for(auto i:v)res+=i;
		reverse(ALL(res));
	}else{
		fore(i,0,5)res+=v[SZ(v)-1-i];
		res+="...";
		res+=v[1];
		res+=v[0];
	}
	return res;
} 

int main(){FIN;
	string s; cin>>s;
	reverse(ALL(s));
	bool can=1;
	fore(i,0,SZ(s)){
		if(can&&SZ(v)&&v.back()==s[i]){
			if(SZ(dc)>1&&dc[SZ(dc)-2]>s[i]){
				if(!SZ(v)||v.back()!=s[i])dc.pb(s[i]);
				v.pb(s[i]);
				can=1;
			}else{
				v.pop_back();
				if(!SZ(v)||v.back()!=dc.back()){
					dc.pop_back();
				}
				can=0;
			}
		}else{
			if(!SZ(v)||v.back()!=s[i])dc.pb(s[i]);
			v.pb(s[i]);
			can=1;
		}
		res.pb({SZ(v),gets()});
	}
	reverse(ALL(res));
	for(auto i:res)cout<<i.fst<<" "<<i.snd<<"\n";
	
	return 0;
}
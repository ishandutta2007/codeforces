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

string inp(){
	string s;
	getline(cin,s);
	return s;
}

vector<string> spl(string s, char c){
	vector<string> res={""};
	for(auto i:s){
		if(i==c)res.pb("");
		else res[SZ(res)-1]+=i;
	}
	//cout<<s<<": ";
	//for(auto i:res)cout<<i<<endl;
	return res;
}

vector<string> par(string s){
	auto v=spl(s,' ');
	if(SZ(v)==3){
		return {".",v[0],v[2]};
	}else{
		return {v[0],v[2],v[4]};
	}
}

ll oc(string s){
	ll res=0;
	fore(i,0,SZ(s)-3){
		string t;
		fore(j,i,i+4){
			t+=s[j];
		}
		if(t=="haha")res++;
	}
	return res;
}

string tr(string s, bool b){
	if(b){
		while(SZ(s)>3)s.pop_back();
	}else{
		reverse(ALL(s));
		while(SZ(s)>3)s.pop_back();
		reverse(ALL(s));
	}
	return s;
}

pair<ll,string> comb(pair<ll,string> a, pair<ll,string> b){
	auto aa=spl(a.snd,'.');
	auto bb=spl(b.snd,'.');
	if(SZ(aa)==2&&SZ(bb)==2){
		return {a.fst+b.fst+oc(aa[1]+bb[0]),aa[0]+"."+bb[1]};
	}else if(SZ(aa)==2&&SZ(bb)==1){
		return {a.fst+b.fst+oc(aa[1]+bb[0]),aa[0]+"."+tr(aa[1]+bb[0],0)};
	}else if(SZ(aa)==1&&SZ(bb)==2){
		return {a.fst+b.fst+oc(aa[0]+bb[0]),tr(aa[0]+bb[0],1)+"."+bb[1]};
	}else if(SZ(aa)==1&&SZ(bb)==1){
		string s=aa[0]+bb[0];
		if(SZ(s)<=6){
			return {0,s};
		}else{
			return {oc(s),tr(s,1)+"."+tr(s,0)};
		}
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<string> v;
		cin.ignore();
		fore(i,0,n)v.pb(inp());
		//for(auto i:v)cout<<i<<"\n";
		//cout<<"HOLAs"<<endl;
		map<string,pair<ll,string>> mp;
		string ls=".";
		for(auto i:v){
			auto p=par(i);
			if(p[0]=="."){
				mp[p[1]]={0,p[2]};
				ls=p[1];
			}else{
				mp[p[0]]=comb(mp[p[1]],mp[p[2]]);
				ls=p[0];
			}
			//cout<<"HOLA"<<endl;
		}
		auto sp=spl(mp[ls].snd,'.');
		if(SZ(sp)==2)cout<<mp[ls].fst<<"\n";
		else cout<<oc(sp[0])<<"\n";
	}
	return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll sumd(string s){
	ll res=0;
	fore(i,0,SZ(s)){
		//cout<<"w "<<s[i]<<" "<<ll(s[i])<<" "<<ll('0')<<" "<<SZ(s)<<endl;
		res+=s[i]-'0';
	}
	//cout<<s<<" "<<res<<endl;
	return res;
}

string cr(string s){
	reverse(ALL(s));
	while(s.back()=='0')s.pop_back();
	reverse(ALL(s));
	return s;
}

pair<string,string> sp(string s){
	assert(SZ(s)&&s[0]>'0');
	pair<string,string> res;
	res.fst=s;
	res.fst[0]--;
	res.fst=cr(res.fst);
	fore(i,0,SZ(s))res.snd+='0';
	res.snd[0]='1';
	//cout<<s<<": "<<res.fst<<" "<<res.snd<<endl;
	return res;
}

vector<string> upg(vector<string> a){
	pair<ll,ll> mini={15,-1};
	fore(i,0,SZ(a)){
		if(sumd(a[i])>1){
			auto p=sp(a[i]);
			a[i]=p.fst;
			a.pb(p.snd);
			return a;
		}
		if(SZ(a[i])>1)mini=min(mini,{SZ(a[i]),i});
	}
	string nn;
	fore(i,0,mini.fst-2)nn+='0';
	assert(mini.snd!=-1);
	a[mini.snd]='9'+nn;
	a.pb('1'+nn);
	return a;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll s,n; cin>>s>>n;
		vector<string> a={to_string(s)};
		fore(i,0,n-1){
			/*
			cout<<"antes:\n";
			for(auto i:a)cout<<i<<" ";
			cout<<endl;
			*/
			a=upg(a);
			/*
			cout<<"desp:\n";
			for(auto i:a)cout<<i<<" ";
			cout<<endl;
			*/
		}
		for(auto i:a)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}
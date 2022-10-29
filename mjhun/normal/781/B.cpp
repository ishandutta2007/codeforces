#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

void perdi(){puts("NO");exit(0);}

map<string,vector<pair<int,char> > > w;
set<string> a;
string r[1024];
int n;

void doit(int k, string s){
	if(a.count(s))perdi();
	a.insert(s);
	r[k]=s;
	if(w.count(s)){
		auto it=w.find(s);
		if(it->snd.size()==1){
			auto p=it->snd[0];
			if(!r[p.fst].size()){
				doit(p.fst,it->fst.substr(0,2)+p.snd);
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		char s[32],t[32];
		scanf("%s%s",s,t);
		w[string(s).substr(0,3)].pb(mp(i,t[0]));
	}
	for(auto p:w){
		if(p.snd.size()<2)continue;
		for(auto pp:p.snd){
			doit(pp.fst,p.fst.substr(0,2)+pp.snd);
		}
	}/*
	for(auto p:w){
		if(p.snd.size()>=2)continue;
		auto pp=p.snd[0];
		if(!a.count(p.fst))doit(pp.fst,p.fst);
		else doit(pp.fst,p.fst.substr(0,2)+pp.snd);
	}*/
	for(auto p:w){
		if(p.snd.size()>=2)continue;
		auto pp=p.snd[0];
		if(r[pp.fst].size())continue;
		if(a.count(p.fst))doit(pp.fst,p.fst.substr(0,2)+pp.snd);
	}
	for(auto p:w){
		if(p.snd.size()>=2)continue;
		auto pp=p.snd[0];
		if(r[pp.fst].size())continue;
		if(!a.count(p.fst))doit(pp.fst,p.fst);
		else doit(pp.fst,p.fst.substr(0,2)+pp.snd);
	}
	puts("YES");
	fore(i,0,n){
		printf("%s\n",r[i].c_str());
	}
	return 0;
}
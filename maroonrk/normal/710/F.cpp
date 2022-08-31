#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define PB push_back
using ll=long long;
int read(){
	int i;
	scanf("%d",&i);
	return i;
}

string readString(){
	static char str[334893];
	scanf("%s",str);
	return string(str);
}

struct Aho{
	struct State{
		int sum;
		State* nx[26];
		State* fail;
		State(){
			sum=0;
			fill(nx,nx+26,(State*)NULL);
			fail=NULL;
		}
	};
	vector<State> buf;
	int bufUsed;
	State* newState(){
		return &buf[bufUsed++];
	}
	State* root;
	void trieDfs(State* cur,const string& s,int i){
		if(i==(int)s.size())
			cur->sum++;
		else{
			if(!(cur->nx[(int)s[i]]))
				cur->nx[(int)s[i]]=newState();
			trieDfs(cur->nx[(int)s[i]],s,i+1);
		}
	}
	void Init(const vector<string>& strs){
		int sz=1;
		for(auto&& s:strs)
			sz+=s.size();
		buf.resize(sz);
		root=newState();
		for(auto&& s:strs)
			trieDfs(root,s,0);
		queue<State*> q;
		q.push(root);
		while(!q.empty()){
			State* cur=q.front();
			q.pop();
			REP(i,26)if(cur->nx[i]){
				State* x=cur->nx[i];
				State* f=cur->fail;
				while(f&&(!f->nx[i]))
					f=f->fail;
				if(f){
					x->fail=f->nx[i];
					x->sum+=x->fail->sum;
				}else
					x->fail=root;
				q.push(x);
			}
		}
	}
	ll Count(const string& s) const{
		ll ret=0;
		State* cur=root;
		REP(i,(int)s.size()){
			while(cur&&!cur->nx[(int)s[i]])
				cur=cur->fail;
			if(cur)
				cur=cur->nx[(int)s[i]];
			else
				cur=root;
			ret+=cur->sum;
		}
		return ret;
	}
};

void Set(const string& s,vector<vector<string>>& vs,vector<Aho>& va){
	vector<string> b;
	b.PB(s);
	while(!vs.empty()){
		if(vs.back().size()==b.size()){
			copy(vs.back().begin(),vs.back().end(),back_inserter(b));
			vs.pop_back();
			va.pop_back();
		}else
			break;
	}
	vs.PB(b);
	va.PB(Aho());
	va.back().Init(b);
}

int main(){
	vector<vector<string>> avs,rvs;
	vector<Aho> ava,rva;
	int m=read();
	REP(i,m){
		int t=read();
		string s=readString();
		for(auto& c:s)
			c-='a';
		if(t==1)
			Set(s,avs,ava);
		else if(t==2)
			Set(s,rvs,rva);
		else{
			ll ans=0;
			for(auto&& v:ava)
				ans+=v.Count(s);
			for(auto&& v:rva)
				ans-=v.Count(s);
			printf("%lld\n",ans);
			fflush(stdout);
		}
	}
}
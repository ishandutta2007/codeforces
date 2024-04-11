#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back

using uint=unsigned int;
using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

const int Nmax=201919;
vi t[Nmax];
pii dfs1(int v,int p){
	int s0=0,s1=0,s2=0,df=-Nmax,ds=-Nmax;
	for(auto c:t[v])if(c!=p){
		pii g=dfs1(c,v);
		s0+=g.first;
		if(df<g.second)swap(df,g.second);
		if(ds<g.second)swap(ds,g.second);
	}
	s1=max(s0,s0+df+1);
	s2=max(s1,s0+df+ds+2);
	return MP(s2,s1-s2);
}
void dfs2(int v,int p,vi& x,vi& y){
	x.PB(v);
	for(auto c:t[v])if(c!=p)
		dfs2(c,v,y,x);
}

int main(){
	int n=read(),x=read(),y=read();
	REP(i,n-1){
		int a=read()-1,b=read()-1;
		t[a].PB(b);
		t[b].PB(a);
	}
	int k;
	if(x<=y)
		k=dfs1(0,-1).first;
	else{
		vi o,e;
		dfs2(0,-1,o,e);
		if(o.size()==1||e.size()==1)
			k=1;
		else
			k=0;
	}
	cout<<ll(x)*k+ll(y)*(n-1-k)<<endl;
}
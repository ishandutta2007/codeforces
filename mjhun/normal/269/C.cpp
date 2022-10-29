#include <cassert>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#define mp make_pair
#define fst first
#define snd second
#define pb push_back
using namespace std;

vector<pair<int,int> > graph[200005];
bool ecalc[200005];
bool edir[200005];
int ea[200005];
int eb[200005];
int ec[200005];
int sc[200005];
set<pair<int,int> > vert;

int main(){
	int n,m,i,j,a,b,c,v,s,e;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;++i){
		scanf("%d %d %d",ea+i,eb+i,ec+i);
		graph[ea[i]].pb(mp(eb[i],i));
		graph[eb[i]].pb(mp(ea[i],i));
		sc[ea[i]]+=ec[i];
		sc[eb[i]]+=ec[i];
	}
	sc[1]=0;
	vert.insert(mp(0,1));
	for(i=2;i<=n;++i){
		if(i!=n)sc[i]/=2;
		vert.insert(mp(sc[i],i));
	}
	
	for(i=1;i<=n;++i){
		v=vert.begin()->snd;
		vert.erase(vert.begin());
		for(j=0;j<graph[v].size();++j){
			s=graph[v][j].fst;
			e=graph[v][j].snd;
			if(!ecalc[e]){
				ecalc[e]=true;
				if(v!=ea[e])
					edir[e]=true;
				vert.erase(mp(sc[s],s));
				sc[s]-=ec[e];
				vert.insert(mp(sc[s],s));
			}
		}
	}
	assert(vert.empty());
	for(i=0;i<m;++i){
		putchar(edir[i]?'1':'0');
		putchar('\n');
	}
	
	return 0;
}
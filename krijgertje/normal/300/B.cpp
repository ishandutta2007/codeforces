#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;  

vector<int> parent;
vector<int> rnk;

int find(int x) { if(parent[x]==x) return x; else return parent[x]=find(parent[x]); }
void unite(int a,int b) {
	a=find(a); b=find(b); if(a==b) return;
	if(rnk[b]>rnk[a]) swap(a,b);
	parent[b]=a; if(rnk[a]==rnk[b]) ++rnk[a];
}

void run() {
	int n,m; scanf("%d%d",&n,&m);
	parent=vector<int>(n); REP(i,n) parent[i]=i; rnk=vector<int>(n,0);
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		unite(a,b);
	}
	vector<int> size(n,0); REP(i,n) size[find(i)]++;
	vector<int> singles,doubles,triples;
	REP(i,n) if(size[i]>=4) { printf("-1\n"); return; }
	REP(i,n) if(size[i]==1) singles.PB(i); else if(size[i]==2) doubles.PB(i); else if(size[i]==3) triples.PB(i);
	if(SZ(doubles)>SZ(singles)) { printf("-1\n"); return; }
	
	int at=0;
	vector<int> mapping(n,-1);
	REPSZ(i,triples) mapping[triples[i]]=at++;
	REPSZ(i,doubles) mapping[doubles[i]]=mapping[singles[i]]=at++; 
	for(int i=SZ(doubles);i<SZ(singles);i+=3) mapping[singles[i]]=mapping[singles[i+1]]=mapping[singles[i+2]]=at++;
	
	vector<vector<int> > groups(at);
	REP(i,n) groups[mapping[find(i)]].PB(i+1);
	REPSZ(i,groups) { REPSZ(j,groups[i]) { if(j!=0) printf(" "); printf("%d",groups[i][j]); } puts(""); }
}

int main() {
	run();
	return 0;
}
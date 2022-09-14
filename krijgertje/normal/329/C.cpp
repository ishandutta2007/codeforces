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
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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

int n,m;
int adj[100000][2];
int color[100000];

int cnt[4];
int frst[4];
int nxt[100000];

void output(int &last,int x,int &left) {
	if(x==last) return;
	if(left>0&&last!=-1) {
		assert(adj[x][0]!=last&&adj[x][1]!=last);
		printf("%d %d\n",last+1,x+1);
		--left;
	}
	last=x;
}

void run(int casenr) {
	scanf("%d%d",&n,&m);
	memset(adj,-1,sizeof(adj));
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; if(adj[a][0]==-1) adj[a][0]=b; else adj[a][1]=b; if(adj[b][0]==-1) adj[b][0]=a; else adj[b][1]=a; }

	memset(color,-1,sizeof(color));
	REP(i,n) if(color[i]==-1) {
		color[i]=2;
		REP(j,2) if(adj[i][j]!=-1) {
			int at=adj[i][j],prev=i;
			while(at!=-1&&color[at]==-1) {
				int next=adj[at][0]==prev?adj[at][1]:adj[at][0];
				if(next==-1||color[next]==-1||color[next]==color[prev]) color[at]=3-color[prev]; else color[at]=3;
				prev=at,at=next;
			}
		}
	}
//	REP(i,n) printf("%d = %d\n",i+1,color[i]);

	memset(cnt,0,sizeof(cnt));
	memset(frst,-1,sizeof(frst));
	REP(i,n) { nxt[i]=frst[color[i]]; frst[color[i]]=i; cnt[color[i]]++; }

	bool can12=false,can23=false,can31=false,can21=false;
	int first12=-1,second12=-1,first23=-1,second23=-1,first31=-1,second31=-1,first21=-1,second21=-1;
	for(int x=frst[1];x!=-1&&!can12;x=nxt[x]) for(int y=frst[2];y!=-1&&!can12;y=nxt[y]) if(adj[x][0]!=y&&adj[x][1]!=y) { can12=true; first12=x; second12=y; }
	for(int x=frst[2];x!=-1&&!can23;x=nxt[x]) for(int y=frst[3];y!=-1&&!can23;y=nxt[y]) if(adj[x][0]!=y&&adj[x][1]!=y&&(cnt[2]==1||x!=second12)) { can23=true; first23=x; second23=y; }
	for(int x=frst[3];x!=-1&&!can31;x=nxt[x]) for(int y=frst[1];y!=-1&&!can31;y=nxt[y]) if(adj[x][0]!=y&&adj[x][1]!=y&&(cnt[3]==1||x!=second23)&&(cnt[1]==1||y!=first12)) { can31=true; first31=x; second31=y; }
	if(cnt[3]==0) for(int x=frst[2];x!=-1&&!can21;x=nxt[x]) for(int y=frst[1];y!=-1&&!can21;y=nxt[y]) if(adj[x][0]!=y&&adj[x][1]!=y&&(cnt[2]==1||x!=second12)&&(cnt[1]==1||y!=first12)) { can21=true; first21=x; second21=y; }

//	printf("%d %d %d => %d + %d + %d  +  %d + %d + %d + %d\n",cnt[1],cnt[2],cnt[3],max(0,cnt[1]-1),max(0,cnt[2]-1),max(0,cnt[3]-1),(can12?1:0),(can23?1:0),(can31?1:0),(can21?1:0));
	int maxm=max(0,cnt[1]-1)+max(0,cnt[2]-1)+max(0,cnt[3]-1)+(can12?1:0)+(can23?1:0)+(can31?1:0)+(can21?1:0);
	if(m>maxm) { printf("-1\n"); return; }

	int left=m,last=-1;
	if(can31) { output(last,second31,left); }
	if(can21) { output(last,second21,left); }
	for(int x=frst[1];x!=-1;x=nxt[x]) {
		if(x==first12||x==second31||x==second21) continue;
		output(last,x,left);
	}
	if(can12) { output(last,first12,left); output(last,second12,left); }
	for(int x=frst[2];x!=-1;x=nxt[x]) {
		if(x==second12||x==first23||x==first21) continue;
		output(last,x,left);
	}
	if(can23) { output(last,first23,left); output(last,second23,left); }
	for(int x=frst[3];x!=-1;x=nxt[x]) {
		if(x==second23||x==first31) continue;
		output(last,x,left);
	}
	if(can31) { output(last,first31,left); output(last,second31,left); }
	if(can21) { output(last,first21,left); output(last,second21,left); }
	assert(left==0);
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
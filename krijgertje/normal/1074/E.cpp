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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};
const int NSTATE=362880;

vector<vector<int>> moves;
map<ll,int> mp;

int state[3][3];
void rec(int x,int y,vector<int> &move) {
	if(state[x][y]==1) { moves.PB(move); return; }
	if(state[x][y]!=0) return;
	move.PB(3*x+y); state[x][y]=SZ(move);
	REP(k,4) {
		int nx=x+DX[k],ny=y+DY[k];
		if(nx<0||nx>=3||ny<0||ny>=3) continue;
		rec(nx,ny,move);
	}
	move.pop_back(); state[x][y]=0;
}

void genmoves() {
	moves.clear();
	REP(x,3) REP(y,3) state[x][y]=0;
	REP(x,3) REP(y,3) { vector<int> move; rec(x,y,move); state[x][y]=-1; }
	//printf("nmoves=%d\n",SZ(moves));
	//REPSZ(i,moves) { printf("%d:",i); REPSZ(j,moves[i]) printf(" (%d,%d)",moves[i][j]/3,moves[i][j]%3); puts(""); }
}

int dst[NSTATE],act[NSTATE],nxt[NSTATE];

ll encode(const vector<int> &p) {
	ll ret=0; REPSZ(i,p) ret=9*ret+p[i]; return ret;
}
void decode(vector<int> &p,ll code) {
	for(int i=SZ(p)-1;i>=0;--i) p[i]=code%9,code/=9;
}

void doreverse(vector<int> &p,const vector<int> &move) {
	FORSZ(i,1,move) { int a=move[i],b=move[(i+1)%SZ(move)]; swap(p[a],p[b]); }
}

void precalcsmall() {
	{ vector<int> p(9); REP(i,9) p[i]=i; int nstate=0; mp.clear(); do { mp[encode(p)]=nstate++; } while(next_permutation(p.begin(),p.end())); assert(nstate==NSTATE); }
	REP(i,NSTATE) dst[i]=INT_MAX,act[i]=-2,nxt[i]=-2;
	queue<ll> q;
	vector<int> p(9); REP(i,9) p[i]=i; int sid=mp[encode(p)]; dst[sid]=0,act[sid]=-1,nxt[sid]=-1,q.push(encode(p));
	while(!q.empty()) {
		ll pcode=q.front(); q.pop();
		int at=mp[pcode];
		REPSZ(i,moves) {
			if(i>3) continue;
			decode(p,pcode);
			doreverse(p,moves[i]);
			ll tocode=encode(p); int to=mp[tocode]; if(dst[to]==INT_MAX) dst[to]=dst[at]+1,act[to]=i,nxt[to]=at,q.push(tocode);
		}
	}
	int mx=0;
	REP(i,NSTATE) mx=max(mx,dst[i]);
	//printf("mx=%d\n",mx);
}

const int MAXH=20;
const int MAXW=20;

int h,w;
int g[MAXH][MAXW];
int og[MAXH][MAXW];
int tg[MAXH][MAXW];
vector<vector<int>> ans;

void print() {
	printf("after %d moves:\n",SZ(ans));
	REP(x,h) { REP(y,w) { if(y!=0) printf(" "); printf("%2d",g[x][y]); } puts(""); }
}
pair<int,int> find(int val) { REP(x,h) REP(y,w) if(g[x][y]==val) return MP(x,y); assert(false); return MP(-1,-1); }

void domove(vector<pair<int,int>> move,bool addtoans=true) {
	REPSZ(i,move) assert(move[i].first>=0&&move[i].first<h&&move[i].second>=0&&move[i].second<w);
	vector<int> vals(SZ(move)); REPSZ(i,move) vals[i]=g[move[i].first][move[i].second];
	//if(addtoans) { printf("vals:"); REPSZ(i,vals) printf(" %d",vals[i]); puts(""); }
	if(addtoans) ans.PB(vals);
	REPSZ(i,move) g[move[i].first][move[i].second]=vals[(i+SZ(move)-1)%SZ(move)];
}



void verify() {
	REP(x,h) REP(y,w) tg[x][y]=g[x][y];
	REP(x,h) REP(y,w) g[x][y]=og[x][y];
	REPSZ(i,ans) {
		vector<int> vals=ans[i];
		vector<pair<int,int>> pos(SZ(vals)); REPSZ(j,vals) pos[j]=find(vals[j]);
		assert(SZ(pos)>=4);
		set<pair<int,int>> seen;
		REPSZ(j,vals) {
			int k=(j+1)%SZ(vals); assert(!seen.count(pos[j])); seen.insert(pos[j]);
			//printf("(%d,%d)-(%d,%d)\n",pos[j].first,pos[j].second,pos[k].first,pos[k].second);
			assert(abs(pos[j].first-pos[k].first)+abs(pos[j].second-pos[k].second)==1);
		}
		domove(pos,false);
	}
	print();
	REP(x,h) REP(y,w) assert(g[x][y]==x*w+y+1);
	REP(x,h) REP(y,w) g[x][y]=tg[x][y];
}

void solvesmall(int cx,int cy,bool rot=false) {
	vector<int> vals(9); REP(dx,3) REP(dy,3) vals[3*dx+dy]=g[cx+dx][cy+dy];
	vector<pair<int,int>> o(9); REP(i,9) o[i]=MP(vals[i],i); sort(o.begin(),o.end());
	vector<int> p(9); REP(i,9) p[o[i].second]=i; // p[x]=y : now at x goes to y

	if(rot) {
		REP(i,9) if(vals[i]==vals.back()-w) {
			// i->5
			int oth=-1; REP(j,9) if(p[j]==5) { oth=j; break; }
			swap(p[oth],p[i]);
			break;
		}
		REP(i,9) if(vals[i]==vals.back()-2*w) {
			// i->2
			int oth=-1; REP(j,9) if(p[j]==2) { oth=j; break; }
			swap(p[oth],p[i]);
			break;
		}
	}


	//printf("vals:"); REPSZ(i,vals) printf(" %d",vals[i]); puts("");
	//printf("o:"); REPSZ(i,o) printf(" (%d,%d)",o[i].first,o[i].second); puts("");
	//printf("p:"); REPSZ(i,p) printf(" %d",p[i]); puts("");
	int at=mp[encode(p)];
	//printf("at=%d dst=%d\n",at,dst[at]);
	while(act[at]>=0) {
		vector<pair<int,int>> move;
		REPSZ(i,moves[act[at]]) { int idx=moves[act[at]][i]; move.PB(MP(cx+idx/3,cy+idx%3)); }
		//printf("doing move %d\n",act[at]);
		//printf("move:"); REPSZ(i,move) printf(" (%d,%d)",move[i].first,move[i].second); puts("");
		//print();
		domove(move);
		//verify();
		at=nxt[at];
	}
}

void solve() {
	ans.clear();
	for(int x=h-1;x>=3;--x) {
		for(int y=w-1;y>=0;--y) {
			int want=x*w+y+1;
			//printf("want=%d\n",want);
			pair<int,int> pos=find(want);
			while(pos.first<x-1) {
				int oy=pos.second==0?1:pos.second-1;
				vector<pair<int,int>> move; move.PB(pos); move.PB(MP(pos.first+1,pos.second)); move.PB(MP(pos.first+1,oy)); move.PB(MP(pos.first,oy));
				domove(move);
				pos=find(want);
			}
			while(pos.second<y-1) {
				vector<pair<int,int>> move; move.PB(pos); move.PB(MP(pos.first,pos.second+1)); move.PB(MP(pos.first-1,pos.second+1)); move.PB(MP(pos.first-1,pos.second));
				domove(move);
				pos=find(want);
			}
			while(pos.second>y) {
				vector<pair<int,int>> move; move.PB(pos); move.PB(MP(pos.first,pos.second-1)); move.PB(MP(pos.first-1,pos.second-1)); move.PB(MP(pos.first-1,pos.second));
				domove(move);
				pos=find(want);
			}
			solvesmall(x-2,max(0,y-2));
			//print();
		}
	}
	for(int y=w-1;y>=3;--y) {
		for(int x=2;x>=0;--x) {
			int want=x*w+y+1;
			pair<int,int> pos=find(want);
			while(pos.second<y-1) {
				int ox=pos.first==0?1:pos.first-1;
				vector<pair<int,int>> move; move.PB(pos); move.PB(MP(pos.first,pos.second+1)); move.PB(MP(ox,pos.second+1)); move.PB(MP(ox,pos.second));
				//printf("move:"); REPSZ(i,move) printf(" (%d,%d)",move[i].first,move[i].second); puts("");
				domove(move);
				pos=find(want);
			}
			//verify();
			//printf("here y=%d x=%d want=%d pos=(%d,%d)\n",y,x,want,pos.first,pos.second);
			//print();
			solvesmall(0,y-2,true);
			//verify();
			//print();
		}
	}
	solvesmall(0,0);
	//print();
}

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) REP(y,w) scanf("%d",&g[x][y]);
	REP(x,h) REP(y,w) og[x][y]=g[x][y];
	solve();
	//verify();
	printf("%d\n",SZ(ans));
	REPSZ(i,ans) { printf("%d",SZ(ans[i])); REPSZ(j,ans[i]) printf(" %d",ans[i][j]); puts(""); }
}

void stress() {
	REP(rep,1000) {
		h=3+rand()%5,w=3+rand()%5;
		vector<int> vals(h*w); REPSZ(i,vals) vals[i]=i+1; random_shuffle(vals.begin(),vals.end()); REP(x,h) REP(y,w) og[x][y]=g[x][y]=vals[x*w+y];
		printf("%d %d\n",h,w); REP(x,h) { REP(y,w) { if(y!=0) printf(" "); printf("%d",g[x][y]); } puts(""); }
		solve();
		verify();
	}
}

int main() {
	genmoves();
	precalcsmall();
	run();
	//stress();
	return 0;
}
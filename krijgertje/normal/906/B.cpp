#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
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
#include <ctime>
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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};
int h,w;

vector<vector<int> > transpose(vector<vector<int> > &g) {
	vector<vector<int> > ret(w,vector<int>(h,-1));
	REP(x,h) REP(y,w) ret[y][x]=g[x][y];
	return ret;
}
vector<vector<int> > solveeven(vector<vector<int> > &g) {
	vector<vector<int> > ret(h,vector<int>(w,-1));
	REP(x,h) {
		int at=0;
		for(int y=1;y<w;y+=2) ret[x][at++]=g[x][y];
		for(int y=0;y<w;y+=2) ret[x][at++]=g[x][y];
		if(x%2==1) reverse(ret[x].begin(),ret[x].end());
	}
	return ret;
}
vector<vector<int> > solveodd(vector<vector<int> > &g) {
	vector<vector<int> > ret(h,vector<int>(w,-1));
	REP(x,h) {
		int at=0;
		for(int y=1-x%2;y<w;y+=2) ret[x][at++]=g[x][y];
		for(int y=x%2;y<w;y+=2) ret[x][at++]=g[x][y];
	}
	return ret;
}
bool chk(vector<vector<int> > &g,vector<vector<int> > &ret) {
	int n=h*w;
	vector<int> mask(n+1,0);
	REP(x,h) REP(y,w) {
		REP(k,4) {
			int nx=x+DX[k],ny=y+DY[k]; if(nx<0||nx>=h||ny<0||ny>=w) continue;
			mask[g[x][y]]|=1<<g[nx][ny];
		}
	}
	REP(x,h) REP(y,w) {
		REP(k,4) {
			int nx=x+DX[k],ny=y+DY[k]; if(nx<0||nx>=h||ny<0||ny>=w) continue;
			if(mask[ret[x][y]]&(1<<ret[nx][ny])) return false;
		}
	}
	return true;
}
void print(vector<vector<int> > &ret) {
	printf("YES\n");
	REP(x,h) { REP(y,w) { if(y!=0) printf(" "); printf("%d",ret[x][y]); } puts(""); }
}
void solvebrute(vector<vector<int> > &g) {
	int n=h*w;
	vector<int> p(n); REP(i,n) p[i]=i;
	do {
		vector<vector<int> > ret(h,vector<int>(w,-1));
		REP(i,n) ret[i/w][i%w]=g[p[i]/w][p[i]%w];
		if(chk(g,ret)) {
			print(ret);
			return;
		}
	} while(next_permutation(p.begin(),p.end()));
	printf("NO\n");
}

void run() {
	scanf("%d%d",&h,&w);
	vector<vector<int> > g(h,vector<int>(w)); REP(x,h) REP(y,w) g[x][y]=x*w+y+1;
	if(max(h,w)<=3) { solvebrute(g); return; }
	bool trans=false;
	if(w<4) { trans=true; g=transpose(g); swap(w,h); }
	vector<vector<int> > ret;
	if(w%2==0) ret=solveeven(g); else ret=solveodd(g);
	if(trans) { ret=transpose(ret); g=transpose(g); swap(w,h); }
	//if(h*w<=30) assert(chk(g,ret));
	print(ret);
}

int main() {
	run();
	return 0;
}
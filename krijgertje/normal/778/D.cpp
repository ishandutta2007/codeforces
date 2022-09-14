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

const int MAXH=50;
const int MAXW=50;

int h,w;
char a[MAXH][MAXW+1];
char b[MAXH][MAXW+1];
char t[MAXH][MAXW+1];
void rotate(char g[MAXH][MAXW+1]) {
	REP(x,h) REP(y,w) t[x][y]=g[x][y];
	REP(x,h) REP(y,w) g[y][h-x-1]=t[x][y];
	REP(y,w) g[y][h]='\0';
	REP(x,w) REP(y,h) if(g[x][y]=='D') g[x][y]='L'; else if(g[x][y]=='U') g[x][y]='R'; else if(g[x][y]=='L') g[x][y]='U'; else if(g[x][y]=='R') g[x][y]='D'; else assert(false);
}

void toggle(char g[MAXH][MAXW+1],int x,int y,vector<pair<int,int> > &ret) {
	if(g[x][y]=='L') {
		assert(x+1<h);
		if(g[x+1][y]=='U') toggle(g,x+1,y,ret);
		assert(g[x+1][y]=='L');
		ret.PB(MP(x,y)); g[x][y]=g[x][y+1]='U',g[x+1][y]=g[x+1][y+1]='D';
	} else if(g[x][y]=='U') {
		assert(y+1<w);
		if(g[x][y+1]=='L') toggle(g,x,y+1,ret);
		assert(g[x][y+1]=='U');
		ret.PB(MP(x,y)); g[x][y]=g[x+1][y]='L',g[x][y+1]=g[x+1][y+1]='R';
	} else assert(false);
}

vector<pair<int,int> > norm(char g[MAXH][MAXW+1]) {
	assert(h%2==0);
	vector<pair<int,int> > ret;
	for(int x=0;x<h;x+=2) REP(y,w) if(g[x][y]!='U') {
		assert(g[x][y]=='L');
		toggle(g,x,y,ret);
	}
	return ret;
}


void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) scanf("%s",a[x]);
	REP(x,h) scanf("%s",b[x]);
	bool swapped=false;
	if(h%2!=0) { rotate(a); rotate(b); swap(h,w); swapped=true; }
	//printf("a:\n"); REP(x,h) printf("%s\n",a[x]); printf("b:\n"); REP(x,h) printf("%s\n",b[x]);

	vector<pair<int,int> > u=norm(a),v=norm(b);
	vector<pair<int,int> > ret=u; reverse(v.begin(),v.end()); REPSZ(i,v) ret.PB(v[i]);
	if(swapped) REPSZ(i,ret) ret[i]=MP(w-ret[i].second-1-1,ret[i].first);
	printf("%d\n",SZ(ret));
	REPSZ(i,ret) printf("%d %d\n",ret[i].first+1,ret[i].second+1);
}

int main() {
	run();
	return 0;
}
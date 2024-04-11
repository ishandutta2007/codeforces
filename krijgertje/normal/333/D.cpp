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


#define MAX_BUF 1024*1024

char buf_in[MAX_BUF],*next_in,buf_out[MAX_BUF],*next_out;

void read_buf() {
	buf_in[fread(buf_in,1,MAX_BUF-1,stdin)]=0;
	next_in=buf_in;
}

void read_char() {
	next_in++;
	if (!*next_in)
		read_buf();
}

int read_int() {
	int x=0;
	
	while (*next_in<'0' || *next_in>'9')
		read_char();
	while (*next_in>='0' && *next_in<='9') {
		x=10*x+*next_in-'0';
		read_char();
	}
	
	return x;
}


int h,w;
int a[1000][1000];

int bx[1000000];
int by[1000000];
int bz[1000000];
int b[1000000];
bool bcmp(const int &p,const int &q) {
//	int px=p/w,py=p%w,qx=q/w,qy=q%w;
//	int px=bx[p],py=by[p],qx=bx[q],qy=by[q];
	return bz[p]>bz[q];
}

bool c[1000000];
int ckey[1000][1000];

int frst[1000];
int nxt[1000000];

void run(int casenr) {
	h=read_int(); w=read_int();
	//scanf("%d%d",&h,&w);
	REP(i,h) REP(j,w) a[i][j]=read_int(); //scanf("%d",&a[i][j]);

	int n=h*w;
	REP(x,h) REP(y,w) { int key=x*w+y; b[key]=key; bx[key]=x; by[key]=y; bz[key]=a[x][y]; }
	sort(b,b+n,bcmp);

	memset(c,false,sizeof(c));
	memset(frst,-1,sizeof(frst));

	REP(y,w) FOR(y2,y,w) ckey[y][y2]=ckey[y2][y]=y*w+y2;
	REP(i,n) {
		int x=bx[b[i]],y=by[b[i]];
//		printf("processing %d: (%d,%d) = %d\n",i,x,y,a[x][y]);
		for(int z=frst[x];z!=-1;z=nxt[z]) {
			int x2=bx[b[z]],y2=by[b[z]];
			int key=ckey[y][y2];
//			printf("\twith %d: (%d,%d) = %d -> %d\n",z,x2,y2,a[x2][y2],key);
			if(c[key]) { printf("%d\n",a[x][y]); return; } else c[key]=true;
		}
		nxt[i]=frst[x]; frst[x]=i;
	}
	assert(false);
}

void gen() {
	h=w=1000; REP(i,h) REP(j,w) a[i][j]=rand();
	printf("%d %d\n",h,w);
	REP(i,h) { REP(j,w) { if(j!=0) printf(" "); printf("%d",a[i][j]); } puts(""); }
}


int main() {
	read_buf();
	next_out=buf_out;
//	gen();
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
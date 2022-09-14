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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int n;
int c[52][52];
int cx[52],cy[52]; // c*[x][y]=c[x][y]-cx[x]-cy[u]>=0
int mx[52],my[52];

int q[52],qhead,qtail;
bool S[52],T[52];
int px[52];
int slack[52],pslack[52];

void addx(int x,int px) {
	S[x]=true; q[qhead++]=x; ::px[x]=px;
	REP(y,n) if(c[x][y]-cx[x]-cy[y]<slack[y]) { slack[y]=c[x][y]-cx[x]-cy[y]; pslack[y]=x; }
}

pair<int,int> findy(int sx) {
	qhead=qtail=0;
	memset(S,false,sizeof(S));
	memset(T,false,sizeof(T));
	memset(px,-1,sizeof(px));
	REP(i,n) slack[i]=INT_MAX;
	memset(pslack,-1,sizeof(pslack));
	addx(sx,-2);
	while(true) {
		while(qtail<qhead) {
			int x=q[qtail++];
			REP(y,n) if(c[x][y]==cx[x]+cy[y]&&!T[y]) {
				if(my[y]==-1) return MP(x,y);
				T[y]=true; addx(my[y],x);
			}
		}
		int delta=INT_MAX;
		REP(y,n) if(!T[y]&&slack[y]<delta) delta=slack[y];
		REP(x,n) if(S[x]) cx[x]+=delta;
		REP(y,n) if(T[y]) cy[y]-=delta; else slack[y]-=delta;
		REP(y,n) if(slack[y]==0&&!T[y]) {
			if(my[y]==-1) return MP(pslack[y],y);
			T[y]=true; addx(my[y],pslack[y]);
		}
	}
}

void augment(int sx) {
	pair<int,int> t=findy(sx);
	for(int x=t.first,y=t.second,ny;x!=-2;x=px[x],y=ny) {
		ny=mx[x]; my[y]=x; mx[x]=y;
	}
}

int len;
char a[2000001],b[2000001];
int conv(char c) { if('a'<=c&&c<='z') return c-'a'; if('A'<=c&&c<='Z') return 26+c-'A'; assert(false); }
char conv(int x) { if(x<26) return 'a'+x; if(x<=52) return 'A'+x-26; assert(false); }

void run() {
	scanf("%d%d",&len,&n);
	scanf("%s%s",a,b);
	REP(x,n) REP(y,n) c[x][y]=len;
	REP(i,len) c[conv(a[i])][conv(b[i])]--;
//	REP(x,n) { REP(y,n) printf("%3d",c[x][y]); puts(""); }

	memset(cx,0,sizeof(cx));
	memset(cy,0,sizeof(cy));
	memset(mx,-1,sizeof(mx));
	memset(my,-1,sizeof(my));
	REP(i,n) augment(i);
//	printf("x:"); REP(x,n) printf("%3d",cx[x]); puts("");
//	printf("y:"); REP(y,n) printf("%3d",cy[y]); puts("");

	int ret=n*len; REP(i,n) ret-=cx[i]+cy[i];
	printf("%d\n",ret);
	REP(i,n) printf("%c",conv(mx[i])); puts("");
}

int main() {
	run();
	return 0;
}
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

typedef struct Node {
	int nxt[26],idx;
} Node;

int nlect,nlang;
char a[3000][11],b[3000][11];
char c[3000][11];
bool same[3000];
int idx[3000];

int root,nnodes;
Node nodes[3000*10+1];
int create() { int ret=nnodes++; nodes[ret].idx=-1; memset(nodes[ret].nxt,-1,sizeof(nodes[ret].nxt)); return ret; }



void run() {
	scanf("%d%d",&nlect,&nlang);
	REP(i,nlang) scanf("%s%s",a[i],b[i]);
	REP(i,nlect) scanf("%s",c[i]);
	REP(i,nlang) { int alen=strlen(a[i]),blen=strlen(b[i]); same[i]=alen<=blen; }

	nnodes=0;
	root=create();
	REP(i,nlang) { int at=root; for(int j=0;a[i][j]!='\0';++j) { int x=a[i][j]-'a'; if(nodes[at].nxt[x]==-1) nodes[at].nxt[x]=create(); at=nodes[at].nxt[x]; } assert(nodes[at].idx==-1); nodes[at].idx=i; }
	REP(i,nlect) { int at=root; for(int j=0;c[i][j]!='\0';++j) { int x=c[i][j]-'a'; assert(nodes[at].nxt[x]!=-1); at=nodes[at].nxt[x]; } assert(nodes[at].idx!=-1); idx[i]=nodes[at].idx; }

	REP(i,nlect) {
		if(i!=0) printf(" ");
		printf("%s",same[idx[i]]?a[idx[i]]:b[idx[i]]);
	}
	puts("");
}

int main() {
	run();
	return 0;
}
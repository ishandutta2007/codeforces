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

int p[100000],r[100000];
int find(int x) { if(p[x]==x) return x; return p[x]=find(p[x]); }
void unite(int a,int b) {
	a=find(a),b=find(b);
	if(a==b) return;
	if(r[a]<r[b]) swap(a,b);
	p[b]=a; if(r[a]==r[b]) ++r[a];
}

int tcnt[500],tfirst[501];
int a[100000],b[100000],c[100000],t[100000];
int d[500][500];

void run(int casenr) {
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	REP(i,k) scanf("%d",&tcnt[i]);
	tfirst[0]=0; REP(i,k) tfirst[i+1]=tfirst[i]+tcnt[i];
	REP(i,k) FOR(j,tfirst[i],tfirst[i+1]) t[j]=i;
	REP(i,m) { scanf("%d%d%d",&a[i],&b[i],&c[i]); --a[i]; --b[i]; }

	REP(i,n) p[i]=i,r[i]=0;
	REP(i,m) if(c[i]==0) unite(a[i],b[i]);
	REP(i,n) if(find(i)!=find(tfirst[t[i]])) { printf("No\n"); return; }

	REP(i,k) REP(j,k) d[i][j]=i==j?0:-1;
	REP(i,m) { int A=t[a[i]],B=t[b[i]]; if(A!=B&&(d[A][B]==-1||c[i]<d[A][B])) d[A][B]=c[i]; }
	REP(i,m) { int B=t[a[i]],A=t[b[i]]; if(A!=B&&(d[A][B]==-1||c[i]<d[A][B])) d[A][B]=c[i]; }
	REP(z,k) REP(x,k) REP(y,k) if(d[x][z]!=-1&&d[z][y]!=-1&&(d[x][y]==-1||d[x][z]+d[z][y]<d[x][y])) d[x][y]=d[x][z]+d[z][y];

	printf("Yes\n");
	REP(i,k) { REP(j,k) { if(j!=0) printf(" "); printf("%d",d[i][j]); } puts(""); }
}

int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
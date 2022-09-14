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
#include <climits>
#include <cstring>
#include <stack>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

int k;
char res[51][51];

void test(bool print,int k) {
	if(k==-1) scanf("%d",&k);
	FORE(i,1,50) FORE(j,1,50) {
		res[i][j]='-';
		if(i-1>=1&&res[i-1][j]=='-') res[i][j]='+';
		if(j-1>=1&&res[i][j-1]=='-') res[i][j]='+';
		if(i>k&&j>k&&res[i-k][j-k]=='-') res[i][j]='+';
	}
	if(print) FORE(i,1,50) { FORE(j,1,50) printf("%c",res[i][j]==1?'V':'.'); puts(""); }
}

void run() {
	int nq,k; scanf("%d%d",&nq,&k);
//	test(false,k);
	REP(q,nq) {
		int h,w; scanf("%d%d",&h,&w);
		//printf("want %c, get ",res[h][w]);
		if(h<w) swap(h,w);
		if(w%(k+1)==0) { printf("+\n"); continue; }
		int times=w/(k+1);
		w-=times*(k+1);
		h-=times*(k+1);
		int sgn=(w+h)%2;
		int winsgn=k==1?1:1-times%2;
		printf("%c\n",sgn==winsgn?'+':'-');
	}
}

int main() {
	//test(true,-1);
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
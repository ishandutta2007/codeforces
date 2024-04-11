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

const int MAXBIT=22;
const int MAXNODE=2<<MAXBIT;

int nbit,nel;
int el[1<<MAXBIT];

int nnode;
int idx[1<<MAXBIT];
//vector<int> e[MAXNODE];

bool done[MAXNODE];
int q[MAXNODE],qhead,qtail;


void run() {
	scanf("%d%d",&nbit,&nel); REP(i,nel) scanf("%d",&el[i]);

	nnode=(1<<nbit)+nel;
	REP(i,1<<nbit) idx[i]=-1; REP(i,nel) idx[el[i]]=i;
	//REP(mask,1<<nbit) REP(i,nbit) if(mask&(1<<i)) e[mask].PB(mask^(1<<i));
	//REP(i,nel) e[(1<<nbit)+i].PB((1<<nbit)-1-el[i]),e[el[i]].PB((1<<nbit)+i);

	int ret=0;
	REP(i,nnode) done[i]=false; qhead=qtail=0;
	REP(s,nnode) if(s>=(1<<nbit)&&!done[s]) {
		done[s]=true,q[qhead++]=s,++ret;
		//printf("s=%x\n",s);
		while(qtail<qhead) {
			int at=q[qtail++];
			//printf("\tat=%x\n",at);
			if(at<(1<<nbit)) {
				REP(i,nbit) if(at&(1<<i)) {
					int to=at^(1<<i);
					if(!done[to]) done[to]=true,q[qhead++]=to;
				}
				if(idx[at]!=-1) {
					int to=(1<<nbit)+idx[at];
					if(!done[to]) done[to]=true,q[qhead++]=to;
				}
			} else {
				int to=(1<<nbit)-el[at-(1<<nbit)]-1;
				if(!done[to]) done[to]=true,q[qhead++]=to;
			}
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
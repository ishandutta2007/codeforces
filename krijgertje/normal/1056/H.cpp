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
#include <bitset>
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

const int MAXVAL=300000;
const int MAXROAD=300000;

int nval,nroad;
vector<int> road[MAXROAD];

int biglim;
int big[MAXROAD],nbig;
int small[MAXROAD],nsmall;

int idx[MAXVAL];
vector<pair<int,int>> pos[MAXVAL];
int mark[MAXVAL],curmark;
int nxt[MAXVAL];

bool issurelyhuman() {
	biglim=0; while(biglim*biglim<=nval) ++biglim;
	//biglim=nval; // TMP
	nbig=nsmall=0; REP(i,nroad) if(SZ(road[i])>=biglim) big[nbig++]=i; else small[nsmall++]=i;
	//printf("biglim=%d -> %d big and %d small\n",biglim,nbig,nsmall);

	REP(i,nbig) {
		int me=big[i];
		REP(k,nval) idx[k]=-1;
		REPSZ(j,road[me]) idx[road[me][j]]=j;
		REP(oth,nroad) {
			int common=-1;
			for(int j=SZ(road[oth])-1;j>=0;--j) {
				int k=road[oth][j];
				if(idx[k]==-1) continue;
				if(common!=-1&&idx[k]<common&&road[me][idx[k]+1]!=road[oth][j+1]) return true;
				if(common==-1||idx[k]>common) common=idx[k];
			}
		}
	}
	REP(i,nsmall) {
		int me=small[i];
		REPSZ(j,road[me]) pos[road[me][j]].PB(MP(me,j));
	}
	curmark=-1; REP(i,nval) mark[i]=-1;
	REP(i,nval) {
		++curmark;
		REPSZ(j,pos[i]) {
			int me=pos[i][j].first,idx=pos[i][j].second; if(idx+1>=SZ(road[me])) continue; int want=road[me][idx+1];
			FORSZ(jj,idx+1,road[me]) {
				int k=road[me][jj];
				if(mark[k]!=curmark) {
					mark[k]=curmark;
					nxt[k]=want;
				} else {
					if(nxt[k]!=want) return true;
				}
			}
		}
	}

	return false;
}

void run() {
	scanf("%d%d",&nval,&nroad);
	REP(i,nroad) { int cnt; scanf("%d",&cnt); road[i]=vector<int>(cnt); REP(j,cnt) { int x; scanf("%d",&x); --x; road[i][j]=x; } }
	printf("%s\n",issurelyhuman()?"Human":"Robot");
	REP(i,nroad) road[i]=vector<int>();
	REP(i,nval) pos[i]=vector<pair<int,int>>();
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}
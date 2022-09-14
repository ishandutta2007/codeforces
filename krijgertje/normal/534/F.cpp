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

int h,w;
int rwant[5],cwant[20];

int mem[20][1<<5][7776];
int ans[20][1<<5][7776];

int encode(int cnt[5],int col) {
	int maxval=col<w/2?(col+1)/2:(w-col+1)/2,mult=maxval+1;
	int ret=0;
	REP(i,h) {
		int val=-1;
		if(col<w/2) if(cnt[i]>maxval) return -1; else val=cnt[i];
		if(col>=w/2) if(cnt[i]>rwant[i]||cnt[i]+maxval<rwant[i]) return -1; else val=rwant[i]-cnt[i];
		ret=ret*mult+val;
	}
	return ret;
}

void decode(int state,int cnt[5],int col) {
	int maxval=col<w/2?(col+1)/2:(w-col+1)/2,mult=maxval+1;
	for(int i=h-1;i>=0;--i) {
		int val=state%mult; state/=mult;
		if(col<w/2) cnt[i]=val;
		if(col>=w/2) cnt[i]=rwant[i]-val;
	}
}

int ncolpat[6];
int colpat[6][1<<5];

void print(int cnt[5]) { printf("["); REP(j,h) printf("%d%c",cnt[j],j==h-1?']':' '); }
void print(int col,int mask,int state,int cnt[5]) {
	printf("%d %d %d=",col,mask,state); print(cnt);
}

bool solve(int col,int pmask,int state) {
	if(col>=w) return state==0;
	int &ret=mem[col][pmask][state];
	if(ret==-1) {
		ret=0;
		int cnt[5]; decode(state,cnt,col);
		REP(i,ncolpat[cwant[col]]) {
			int mask=colpat[cwant[col]][i];
			int ncnt[5];
			REP(j,h) ncnt[j]=cnt[j]+(((mask&(1<<j))!=0)&&((pmask&(1<<j))==0)?1:0);
			int nstate=encode(ncnt,col+1); 
			//printf("\t"); print(col,pmask,state,cnt); printf(": %x -> ",mask); print(ncnt); printf(" = %d\n",nstate);
			if(nstate!=-1&&solve(col+1,mask,nstate)) { ans[col][pmask][state]=mask; ret=1; break; }
		}
		//print(col,pmask,state,cnt); printf(" -> %d (%x)\n",ret,ans[col][pmask][state]);
	}
	return ret==1;
}

char g[5][21];

void run() {
	scanf("%d%d",&h,&w);
	REP(i,h) scanf("%d",&rwant[i]); REP(i,w) scanf("%d",&cwant[i]);

	REPE(i,h) ncolpat[i]=0;
	REP(mask,1<<h) {
		int cnt=0; REP(j,h) if(((mask&(1<<j))!=0)&&(j==0||((mask&(1<<(j-1)))==0))) ++cnt;
		colpat[cnt][ncolpat[cnt]++]=mask;
	}
	//REPE(i,h) { printf("%d:",i); REP(j,ncolpat[i]) printf(" %x",colpat[i][j]); puts(""); }

	memset(mem,-1,sizeof(mem));
	int init[5]; REP(i,h) init[i]=0; 
	bool found=solve(0,0,encode(init,0));
	if(!found) { printf("ERROR: NOT FOUND\n"); return; }
	int col=0,pmask=0,state=encode(init,0);
	while(col<w) {
		int cnt[5]; decode(state,cnt,col);
		int mask=ans[col][pmask][state];
		REP(j,h) g[j][col]=((mask&(1<<j))!=0)?'*':'.';
		int ncnt[5]; REP(j,h) ncnt[j]=cnt[j]+(((mask&(1<<j))!=0)&&((pmask&(1<<j))==0)?1:0);
		int nstate=encode(ncnt,col+1);
		//print(col,pmask,state,cnt); printf(" -> %x -> ",mask); print(ncnt); printf("=%d\n",nstate);
		col=col+1,pmask=mask,state=nstate;
	}
	REP(j,h) g[j][w]='\0';
	REP(j,h) printf("%s\n",g[j]);
}

int main() {
	run();
	return 0;
}
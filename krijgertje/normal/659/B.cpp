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

const int MAXPART=100000;
const int MAXLEN=10;

int npart,nreg;
char name[MAXPART][MAXLEN+1];
int reg[MAXPART],score[MAXPART];
int p[MAXPART];
bool pcmp(const int &a,const int &b) { if(reg[a]!=reg[b]) return reg[a]<reg[b]; if(score[a]!=score[b]) return score[a]>score[b]; return a<b; }


void run() {
	scanf("%d%d",&npart,&nreg);
	REP(i,npart) scanf("%s%d%d",name[i],&reg[i],&score[i]),--reg[i];
	REP(i,npart) p[i]=i; sort(p,p+npart,pcmp);
	for(int at=0,to=at;at<npart;at=to) {
		while(to<npart&&reg[p[to]]==reg[p[at]]) ++to;
		if(at+2<to&&score[p[at+1]]==score[p[at+2]]) printf("?\n"); else printf("%s %s\n",name[p[at]],name[p[at+1]]);
	}
}

int main() {
	run();
	return 0;
}
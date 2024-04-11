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

const int MAXN=100;
const int MAXRET=10000;
typedef struct R { int id,r; void dec() { if(r!=0) --r; } } R;
bool operator<(const R &a,const R &b) { return a.r>b.r; }

int n;
R r[MAXN];

int nret; char ret[MAXRET][MAXN+1];

void play2(int a,int b) {
	REP(i,n) ret[nret][i]='0'; ret[nret][n]='\0'; ret[nret][r[a].id]='1'; ret[nret][r[b].id]='1'; ++nret;
	r[a].dec(),r[b].dec();
}
void playrange(int a,int b) {
	while(a<b) {
		//printf("c a=%d b=%d\n",a,b);
		int na=min(b,a+5); if(b-na==1) --na;
		REP(i,n) ret[nret][i]='0'; ret[nret][n]='\0'; FOR(i,a,na) ret[nret][r[i].id]='1',r[i].dec(); ++nret;
		a=na;
	}
}

void run() {
	scanf("%d",&n); REP(i,n) r[i].id=i,scanf("%d",&r[i].r); sort(r,r+n); nret=0;
	{
		int at=1,to=1; while(to<n&&r[at].r==r[to].r) ++to; int cur=to-1;
		while(r[0].r!=r[1].r) {
			//printf("a at=%d to=%d cur=%d\n",at,to,cur);
			play2(0,cur);
			if(cur==at) {
				while(to<n&&r[at].r==r[to].r) ++to; cur=to-1;
			} else {
				--cur;
			}
		}
	}
	{
		int at=0,to=0; while(to<n&&r[at].r==r[to].r) ++to;
		while(to!=n) {
			//printf("b at=%d to=%d\n",at,to);
			playrange(at,to);
			while(to<n&&r[at].r==r[to].r) ++to;
		}
	}
	printf("%d\n%d\n",r[0].r,nret); REP(i,nret) printf("%s\n",ret[i]);


}


int main() {
	run();
	return 0;
}
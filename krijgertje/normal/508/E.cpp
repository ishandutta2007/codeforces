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

int n;
int l[600],r[600];

int act[600][600];

char ret[1201];

int q[1200][3],qhead,qtail;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&l[i],&r[i]);
	REP(i,n) if(l[i]%2==0) ++l[i]; REP(i,n) if(r[i]%2==0) --r[i];
	FORE(len,1,n) REP(i,n-len+1) {
		int j=i+len-1;
		act[i][j]=-1;
		for(int k=l[i];k<=r[i];k+=2) {
			if((k+1)/2>len) break;
			if(k!=1&&act[i+1][i+(k-1)/2]==-1) continue;
			if((k+1)/2<len&&act[i+(k+1)/2][j]==-1) continue;
			act[i][j]=k; break;
		}
		//printf("%d %d = %d\n",i,j,act[i][j]);
	}
	if(act[0][n-1]==-1) { printf("IMPOSSIBLE\n"); return; }

	REP(i,2*n) ret[i]='?'; ret[2*n]='\0';
	qhead=qtail=0; q[qhead][0]=0,q[qhead][1]=n-1,q[qhead][2]=0; ++qhead;
	while(qtail<qhead) {
		int i=q[qtail][0],j=q[qtail][1],k=act[i][j],pos=q[qtail][2],len=j-i+1; ++qtail;
		//printf("%d %d %d %d %d\n",i,j,k,pos,len);
		ret[pos]='('; ret[pos+k]=')';
		if(k!=1) { q[qhead][0]=i+1,q[qhead][1]=i+(k-1)/2,q[qhead][2]=pos+1; ++qhead; }
		if((k+1)/2<len) { q[qhead][0]=i+(k+1)/2,q[qhead][1]=j,q[qhead][2]=pos+k+1; ++qhead; }
	}
	printf("%s\n",ret);
}

int main() {
	run();
	return 0;
}
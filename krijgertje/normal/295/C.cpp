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

const int MOD=1000000007;
int best[2][51][51];
ll ways[2][51][51];
ll choose[51][51];

void run(int casenr) {
	REPE(i,50) {
		choose[i][0]=choose[i][i]=1;
		FOR(j,1,i) { choose[i][j]=choose[i-1][j-1]+choose[i-1][j]; if(choose[i][j]>=MOD) choose[i][j]-=MOD; }
	}

	int n,k; scanf("%d%d",&n,&k);
	vector<int> w(n); REP(i,n) scanf("%d",&w[i]);
	int A=0,B=0; REP(i,n) if(w[i]==50) ++A; else ++B;

	memset(best,-1,sizeof(best));
	queue<pair<int,pair<int,int> > > q;
	best[0][A][B]=0; ways[0][A][B]=1; q.push(MP(0,MP(A,B)));
	while(!q.empty()) {
		int s=q.front().first,a=q.front().second.first,b=q.front().second.second; q.pop();
		ways[s][a][b]%=MOD;
		if(s==0) {
			REPE(aa,a) REPE(bb,b) if(aa*50+bb*100<=k&&aa+bb>=1) {
				int ns=1-s,na=a-aa,nb=b-bb;
				if(best[ns][na][nb]==-1) { best[ns][na][nb]=best[s][a][b]+1; q.push(MP(ns,MP(na,nb))); }
				if(best[ns][na][nb]==best[s][a][b]+1) ways[ns][na][nb]+=choose[a][aa]*choose[b][bb]%MOD*ways[s][a][b]%MOD;
			}
		} else {
			REPE(aa,A-a) REPE(bb,B-b) if(aa*50+bb*100<=k&&aa+bb>=1) {
				int ns=1-s,na=a+aa,nb=b+bb;
				if(best[ns][na][nb]==-1) { best[ns][na][nb]=best[s][a][b]+1; q.push(MP(ns,MP(na,nb))); }
				if(best[ns][na][nb]==best[s][a][b]+1) ways[ns][na][nb]+=choose[A-a][aa]*choose[B-b][bb]%MOD*ways[s][a][b]%MOD;
			}
		}
	}
	cout<<best[1][0][0]<<endl<<ways[1][0][0]<<endl;
}


int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
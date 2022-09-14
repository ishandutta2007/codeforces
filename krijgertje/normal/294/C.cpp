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

const int MOD=1000000007;

ll choose[1001][1001];

void run(int casenr) {
	REPE(i,1000) { choose[i][0]=choose[i][i]=1; FOR(j,1,i) if((choose[i][j]=choose[i-1][j-1]+choose[i-1][j])>=MOD) choose[i][j]-=MOD; }

	int n,m; scanf("%d%d",&n,&m);
	vector<int> on(m); REP(i,m) { scanf("%d",&on[i]); --on[i]; } sort(on.begin(),on.end());
	ll ret=1; int left=n-m;
	int at=0,pos=0;
	while(at<n) {
		if(pos<m&&on[pos]==at) { ++at; ++pos; continue; }
		int to=pos<m?on[pos]:n;
		int cnt=to-at;
		ret=ret*choose[left][cnt]%MOD; left-=cnt;
		if(at!=0&&to!=n) REP(j,cnt-1) { ret+=ret; if(ret>=MOD) ret-=MOD; }
		at=to;
	}
	cout<<ret<<endl;
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
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

char s[1000000],t[1000000];

void run() {
	scanf("%s%s",s,t);
	VVI d(26,VI(26,INT_MAX)); REP(i,26) d[i][i]=0;
	int n; scanf("%d",&n); REP(i,n) { char c1,c2; int cost; scanf(" %c %c%d",&c1,&c2,&cost); int &cur=d[c1-'a'][c2-'a']; if(cost<cur) cur=cost; }
	REP(k,26) REP(i,26) REP(j,26) if(d[i][k]!=INT_MAX&&d[k][j]!=INT_MAX) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
//	REP(i,26) { REP(j,26) printf("%d ",d[i][j]==INT_MAX?-1:d[i][j]); puts(""); }
	int slen=strlen(s),tlen=strlen(t);
	if(slen!=tlen) { printf("-1\n"); return; }
	
	int ret=0;
	REP(i,slen) {
		int best=INT_MAX; char bestc='?';
		REP(j,26) { int d1=d[s[i]-'a'][j],d2=d[t[i]-'a'][j]; if(d1!=INT_MAX&&d2!=INT_MAX&&d1+d2<best) best=d1+d2,bestc='a'+j; }
		if(best==INT_MAX) { printf("-1\n"); return; }
		ret+=best; s[i]=bestc;
	}
	printf("%d\n%s\n",ret,s);
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
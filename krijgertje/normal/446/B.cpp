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


int h,w,cnt,subcell;
int a[1000][1000];

int linecnt[2],linesum[2][1000];
int lineval[2][1000000];
ll linecum[2][1000001];


void run() {
	scanf("%d%d%d%d",&h,&w,&cnt,&subcell);
	REP(i,h) REP(j,w) scanf("%d",&a[i][j]);

	linecnt[0]=h; REP(i,h) { linesum[0][i]=0; REP(j,w) linesum[0][i]+=a[i][j]; }
	linecnt[1]=w; REP(j,w) { linesum[1][j]=0; REP(i,h) linesum[1][j]+=a[i][j]; }

	REP(x,2) {
		sort(linesum[x],linesum[x]+linecnt[x]);
		int i=linecnt[x]-1,j=0,subline=subcell*linecnt[1-x];
		REP(k,cnt) {
			assert(i>=0||j<k);
			if(j>=k||i>=0&&linesum[x][i]>=lineval[x][j]-subline) {
				lineval[x][k]=linesum[x][i--];
			} else {
				lineval[x][k]=lineval[x][j++]-subline;
			}
		}
		linecum[x][0]=0; REP(k,cnt) linecum[x][k+1]=linecum[x][k]+lineval[x][k];
	}

	ll ret=LLONG_MIN,cur=0;
	int i=0,j=0;
	REP(k,cnt) {
		if(lineval[0][i]>=lineval[1][j]) {
			ll cur2=cur+linecum[1][j+cnt-k]-linecum[1][j]-(ll)(cnt-k)*i*subcell; if(cur2>ret) ret=cur2;
			cur+=lineval[0][i++]-(ll)j*subcell;
		} else {
			ll cur2=cur+linecum[0][i+cnt-k]-linecum[0][i]-(ll)(cnt-k)*j*subcell; if(cur2>ret) ret=cur2;
			cur+=lineval[1][j++]-(ll)i*subcell;
		}
	}
	if(cur>ret) ret=cur;
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}
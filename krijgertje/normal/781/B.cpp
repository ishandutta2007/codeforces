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

const int MAXN=1000;
const int MAXLEN=20;

int n;
char a[MAXN][MAXLEN+1],b[MAXN][MAXLEN+1];
int ans[MAXN];

int cnta[26][26][26];
int fsta[26][26][26];
int used[26][26][26];


int q[26*26*26],qhead,qtail;

bool solve() {
	memset(cnta,0,sizeof(cnta));
	memset(fsta,-1,sizeof(fsta));
	memset(used,0,sizeof(used));
	memset(ans,0,sizeof(ans));
	REP(i,n) { int x=a[i][0]-'A',y=a[i][1]-'A',z=a[i][2]-'A'; ++cnta[x][y][z]; fsta[x][y][z]=i; }
	qhead=qtail=0;
	REP(i,n) {
		int x=a[i][0]-'A',y=a[i][1]-'A',z=a[i][2]-'A',w=b[i][0]-'A';
		//printf("A%d %c%c%c %c : %d %d\n",i,'A'+x,'A'+y,'A'+z,'A'+w,cnta[x][y][z],used[x][y][w]);
		if(cnta[x][y][z]>=2) if(used[x][y][w]!=0) return false; else ++used[x][y][w],q[qhead++]=x*26*26+y*26+w,ans[i]=1;
	}
	while(qtail<qhead) {
		int at=q[qtail++],x=at/26/26,y=at/26%26,z=at%26;
		if(cnta[x][y][z]==1) {
			int i=fsta[x][y][z],w=b[i][0]-'A';
			//printf("B%d %c%c%c %c : %d\n",i,'A'+x,'A'+y,'A'+z,'A'+w,used[x][y][w]);
			if(used[x][y][w]!=0) return false; else ++used[x][y][w],q[qhead++]=x*26*26+y*26+w,ans[i]=1;
		}
	}
	return true;
}


void run() {
	scanf("%d",&n); REP(i,n) scanf("%s%s",a[i],b[i]);

	if(!solve()) printf("NO\n"); else { printf("YES\n"); REP(i,n) printf("%c%c%c\n",a[i][0],a[i][1],ans[i]==0?a[i][2]:b[i][0]); }
}

int main() {
	run();
	return 0;
}
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

const int MAXN=9;
const int G[4][3]={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};

int n;
char s[MAXN+1];
int cx[10],cy[10];

void run() {
	scanf("%d%s",&n,s);
	int cnt=0;
	REP(i,4) REP(j,3) if(G[i][j]!=-1) cx[G[i][j]]=i,cy[G[i][j]]=j;
	REP(i,10) {
		int x=cx[i],y=cy[i]; bool ok=true;
		REP(i,n-1) {
			int a=s[i]-'0',b=s[i+1]-'0';
			int nx=x+cx[b]-cx[a],ny=y+cy[b]-cy[a];
			if(nx<0||nx>=4||ny<0||ny>=3||G[nx][ny]==-1) { ok=false; break; }
			x=nx,y=ny;
		}
		if(ok) ++cnt;
	}
	//printf("%d\n",cnt);
	printf("%s\n",cnt==1?"YES":"NO");
}

int main() {
	run();
	return 0;
}
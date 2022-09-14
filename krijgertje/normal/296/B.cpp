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

ll ways[2][4];

int cntgreater(char a,char b) {
	if(a=='?'&&b=='?') return 45;
	if(a=='?') return 9-(b-'0');
	if(b=='?') return a-'0';
	return a>b?1:0;
}

int cntequal(char a,char b) {
	if(a=='?'&&b=='?') return 10;
	return a=='?'||b=='?'||a==b?1:0;
}

void run(int casenr) {
	int n; scanf("%d",&n);
	string a(n,'.'); REP(i,n) scanf(" %c",&a[i]);
	string b(n,'.'); REP(i,n) scanf(" %c",&b[i]);
	
	int q=0;
	ways[q][0]=1; ways[q][1]=ways[q][2]=ways[q][3]=0;
	REP(i,n) {
		ways[1-q][0]=ways[1-q][1]=ways[1-q][2]=ways[1-q][3]=0;
		REP(j,4) {
			// a[i]>b[i]
			ways[1-q][j|1]+=ways[q][j]*cntgreater(a[i],b[i]);
			// a[i]<b[i]
			ways[1-q][j|2]+=ways[q][j]*cntgreater(b[i],a[i]);
			// a[i]==b[i]
			ways[1-q][j]+=ways[q][j]*cntequal(a[i],b[i]);
		}
		q=1-q;
		REP(j,4) ways[q][j]%=MOD;
	}
	cout<<ways[q][3]<<endl;
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
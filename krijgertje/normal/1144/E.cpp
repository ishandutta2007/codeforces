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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXLEN=200000;

int len;
char s[2][MAXLEN+1];

void inc(int z,int idx) { while(idx>=0) { if(s[z][idx]!='z') { ++s[z][idx]; return; } s[z][idx]='a'; --idx; } assert(false); }
void dec(int z,int idx) { while(idx>=0) { if(s[z][idx]!='a') { --s[z][idx]; return; } s[z][idx]='z'; --idx; } assert(false); }

void solve() {
	int smaller=-1;
	//printf("%s and %s (%d)\n",s[0],s[1],smaller);
	REP(i,len) {
		if(smaller!=-1) {
			char a=s[smaller][i],b=s[1-smaller][i];
			while(a<='y'&&b>='b') ++a,--b;
			int nsmaller=smaller;
			if(a=='z'&&b!='a') { inc(smaller,i-1); a='a'; --b; nsmaller=-1; } else if(b=='a'&&a!='z') { dec(1-smaller,i-1); ++a; b='z'; nsmaller=-1; }
			s[smaller][i]=a,s[1-smaller][i]=b,smaller=nsmaller;
			//printf("%s and %s (%d) [%d was diff]\n",s[0],s[1],smaller,i);
		}
		if(smaller==-1) {
			char a=s[0][i],b=s[1][i]; if(a==b) continue; smaller=0; if(a>b) smaller=1,swap(a,b);
			while(a+1<=b-1) ++a,--b;
			s[smaller][i]=a,s[1-smaller][i]=b;
			if(a==b) smaller=-1;
			//printf("%s and %s (%d) [%d was eq]\n",s[0],s[1],smaller,i);
		}
	}
}

void run() {
	scanf("%d",&len);
	scanf("%s",s[0]);
	scanf("%s",s[1]);
	solve();
	printf("%s\n",s[0]);
}

int main() {
	run();
	return 0;
}
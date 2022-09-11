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

int needgreen,neednonblack,needany;
int havegreen,havepurple,haveblack;

bool solve() {
	{ int cur=min(needgreen,havegreen); needgreen-=cur; havegreen-=cur; }
	{ int cur=min(neednonblack,havegreen); havegreen-=cur; neednonblack-=cur; }
	{ int cur=min(neednonblack,havepurple); havepurple-=cur; neednonblack-=cur; }
	{ int cur=min(needany,havegreen); havegreen-=cur; needany-=cur; }
	{ int cur=min(needany,havepurple); havepurple-=cur; needany-=cur; }
	{ int cur=min(needany,haveblack); haveblack-=cur; needany-=cur; }
	return needgreen==0&&neednonblack==0&&needany==0;
}

void run() {
	scanf("%d%d%d",&needgreen,&neednonblack,&needany);
	scanf("%d%d%d",&havegreen,&havepurple,&haveblack);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}
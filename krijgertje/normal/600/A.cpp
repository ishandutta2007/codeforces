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

const int MAXLEN=100000;

char s[MAXLEN+1]; int slen;

char a[MAXLEN+1]; int alen; bool havea;
char b[MAXLEN+1]; int blen; bool haveb;

void run() {
	scanf("%s",s); slen=strlen(s);
	alen=blen=0; havea=haveb=false;
	for(int at=0,to=0;at<=slen;at=++to) {
		while(to<slen&&s[to]!=','&&s[to]!=';') ++to;
		bool dig=at<to&&(s[at]!='0'||to-at==1); FOR(i,at,to) if(!isdigit(s[i])) dig=false;
		if( dig) { if(havea) a[alen++]=','; else a[alen++]='"'; FOR(i,at,to) a[alen++]=s[i]; havea=true; }
		if(!dig) { if(haveb) b[blen++]=','; else b[blen++]='"'; FOR(i,at,to) b[blen++]=s[i]; haveb=true; }
	}
	if(!havea) a[alen++]='-'; else a[alen++]='"'; if(!haveb) b[blen++]='-'; else b[blen++]='"';
	a[alen]=b[blen]='\0';
	printf("%s\n%s\n",a,b);
}

int main() {
	run();
	return 0;
}
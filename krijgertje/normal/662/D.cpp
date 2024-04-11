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

int n;
char buff[15];

string getfst(string s) {
	if(SZ(s)>=5) return s[0]=='0'?"1"+s:s;
	string a="1989";
	if(SZ(s)==4) return (s>=a?"":"1")+s;
	if(SZ(s)==3) return (s>=a.substr(1)?"1":"2")+s;
	if(SZ(s)==2) return (s>=a.substr(2)?"19":"20")+s;
	if(SZ(s)==1) return (s>=a.substr(3)?"198":"199")+s;
	return "?";
}

string getnxt(string s) {
	if(SZ(s)>=5) return (s[0]=='0'?"2":"1")+s;
	string a="1989";
	if(SZ(s)==4) return (s>=a?"1":"2")+s;
	if(SZ(s)==3) return (s>=a.substr(1)?"2":"3")+s;
	if(SZ(s)==2) return (s>=a.substr(2)?"20":"21")+s;
	if(SZ(s)==1) return (s>=a.substr(3)?"199":"200")+s;
	return "?";
}

string calc(string s) {
	string fst=getfst(s),sfst=fst;
	if(SZ(s)==1) return fst;
	for(int i=0;;++i) {
		string prv=getfst(s.substr(i+1));
		if(fst==prv) break;
		//printf("\t%c vs %c [%s %s]\n",i<SZ(s)-SZ(prv)?'0':prv[SZ(prv)-SZ(s)+i],fst[SZ(fst)-SZ(s)+i],fst.c_str(),prv.c_str());
		if(i+2>=SZ(s)||(i<SZ(s)-SZ(prv)?1:prv[SZ(prv)-SZ(s)+i]-'0'+1)%10!=fst[SZ(fst)-SZ(s)+i]-'0') return sfst;
		fst=prv;
	}
	string nxt=getnxt(s);
	return nxt;
}

void run() {
	scanf("%d",&n);
	REP(i,n) {
		scanf("%s",buff);
		printf("%s\n",calc(buff+4).c_str());
	}
}

int main() {
	run();
	return 0;
}
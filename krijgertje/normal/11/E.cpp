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

char buff[1000001];

int calc(string s) {
	int p=0,q=0,ones=0; bool flippedsingle=false;
	REPSZ(i,s) {
		char want=(q%2==0)?'L':'R';
		if(s[i]=='X') ++q;
		else if(s[i]==want) ++p,++q,flippedsingle=false;
		else {
			++q;
			++p,++q;
			if(flippedsingle) ++ones; flippedsingle=!flippedsingle;
		}
	}
	if(q%2==1) {
		++q;
		if(flippedsingle) ++ones;
	}
	if(2*p>q) p-=ones,q-=2*ones;
	
	return (ll)p*100*1000000/q;
}

void run() {
	scanf("%s",buff);
	string s;
	for(int i=0;buff[i]!='\0';++i) { if(i>0&&buff[i-1]==buff[i]&&buff[i]!='X') s+='X'; s+=buff[i]; }
	
	int res;
	if(s[0]==s[SZ(s)-1]&&s[0]!='X') {
		res=max(calc(s+'X'),calc('X'+s));
	} else {
		res=calc(s);
	}
	printf("%d.%06d\n",res/1000000,res%1000000);
}

int main() {
	run();
	return 0;
}
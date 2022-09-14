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

char buff[1000];

void run() {
	gets(buff); int nlines; sscanf(buff,"%d",&nlines);
	vector<int> tt;
	REP(i,nlines) {
		gets(buff);
		int h=(buff[1]-'0')*10+(buff[2]-'0'); if(h==12) h=0;
		int m=(buff[4]-'0')*10+(buff[5]-'0');
		bool ispm=buff[7]=='p';
		tt.PB(h*60+m+(ispm?12*60:0));
	}
	int ret=0,last=10000,cnt=0;
	REPSZ(i,tt) {
		int t=tt[i];
		if(t>last) last=t,cnt=1;
		else if(t==last&&cnt<10) ++cnt;
		else { ++ret; last=t; cnt=1; }
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
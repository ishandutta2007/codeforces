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
#include <stack>
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

const int MAXANS=100000;

char ans[MAXANS+1]; int nans;

void output(char c) {
	ans[nans++]=c;
}
void output(char *s) {
	while(*s!='\0') output(*s),++s;
}
char inv(char c) { if(c=='r') return 'l'; else if(c=='l') return 'r'; else if(c=='d') return 'u'; else if(c=='u') return 'd'; else assert(false); return '?'; }
void moveiffone(char dir) {
	output(dir); output(inv(dir)); output("st");
}
void moveiffempty(char dir) {
	output(inv(dir)); output("s"); output(dir); output("t"); output(dir);
}
void copyandmovethere(char dir) {
	output(dir); output("10"); output(inv(dir)); output("t");
}
void safecopyandmovethere(char dir) {
	output(dir); output("10"); output(inv(dir)); output("t"); moveiffempty(dir); copyandmovethere(inv(dir)); output(dir);
}

void solve() {
	nans=0;
	output("uu0");
	REP(bit,32) {
		REP(i,3) copyandmovethere('r');
		output("u1l1l0l0l0rdd");
		safecopyandmovethere('r'); REP(i,2) copyandmovethere('r');
		output("llld");
		safecopyandmovethere('r'); REP(i,2) copyandmovethere('r');
		output("d1l0l1l0l0ru");
		REP(i,3) { moveiffone('r'); output("u"); }
		REP(i,4) { copyandmovethere('l'); output("l"); moveiffempty('r'); output("r"); }
		copyandmovethere('l'); copyandmovethere('d'); output("r");
		REP(i,3) { moveiffone('r'); output("d"); }
		REP(i,4) { copyandmovethere('l'); output("l"); moveiffempty('r'); output("r"); }
		copyandmovethere('d'); output("uuuul");
	}
	output("ddddr");
	ans[nans]='\0';
}

map<pair<int,int>,char> g;
stack<char> hist;
int cx,cy;

void print(char c) {
	int lx=cx,ly=cy,hx=cx,hy=cy;
	for(auto it=g.begin();it!=g.end();++it) { int x=it->first.first,y=it->first.second; lx=min(lx,x); hx=max(hx,x); ly=min(ly,y); hy=max(hy,y); }
	vector<string> gg(hy-ly+1,string(hx-lx+1,'.'));
	for(auto it=g.begin();it!=g.end();++it) { int x=it->first.first,y=it->first.second; gg[hy-y][x-lx]=it->second; }
	printf("pos=(%d,%d)",cx,cy); if(c!='-') printf(" after %c",c); puts("");
	REPSZ(i,gg) printf("%s\n",gg[i].c_str()); 
}

void apply(char c) {
	printf("applying %c\n",c);
	if(c=='l') --cx; else if(c=='r') ++cx; else if(c=='u') ++cy; else if(c=='d') --cy; else if(c=='s') ;
	else if(c=='0') g[MP(cx,cy)]='0'; else if(c=='1') g[MP(cx,cy)]='1'; else if(c=='e') { auto it=g.find(MP(cx,cy)); if(it!=g.end()); g.erase(it); } else assert(false);
}
void simulate(int a,int b) {
	g.clear(); hist=stack<char>();
	for(int rem=a,x=0;rem!=0;rem/=2,--x) g[MP(x,1)]='0'+rem%2;
	for(int rem=b,x=0;rem!=0;rem/=2,--x) g[MP(x,0)]='0'+rem%2;
	cx=0,cy=0;
	print('-');
	REP(i,nans) {
		char c=ans[i];
		if(c=='l'||c=='r'||c=='u'||c=='d') { hist.push(inv(c)); apply(c); }
		else if(c=='0'||c=='1'||c=='e') { auto it=g.find(MP(cx,cy)); hist.push(it==g.end()?'e':it->second); apply(c); }
		else if(c=='s') { hist.push('s'); apply(c); }
		else if(c=='t') { auto it=g.find(MP(cx,cy)); int cnt=it==g.end()?0:it->second-'0'+1; while(cnt>0&&!hist.empty()) { char cc=hist.top(); hist.pop(); apply(cc); --cnt; } }
		else assert(false);

		print(c);
	}
}

void run() {
	solve();
	//printf("nans=%d\n",nans);
	//simulate(123789123,54538989);
	printf("%s\n",ans);
}

int main() {
	run();
	return 0;
}
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
#include <climits>
#include <cstring>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

char buff[100001];

bool contains(const string &s,const string &p) {
	int slen=SZ(s),plen=SZ(p);
	int at=1,len=0;
	vector<int> next(plen+1,-1); next[1]=0;
	while(at<plen) {
		while(len>0&&p[at]!=p[len]) len=next[len];
		if(p[at]==p[len]) ++len;
		next[at+1]=len;
		++at;
	}
	
	at=0,len=0;
	while(at<slen) {
		while(len>0&&s[at]!=p[len]) len=next[len];
		if(s[at]==p[len]) ++len;
		if(len==plen) return true;
		++at;
	}
	return false;
}

int append(const string &s,const string &p) {
	int slen=SZ(s),plen=SZ(p);
	int at=1,len=0;
	vector<int> next(plen+1,-1); next[1]=0;
	while(at<plen) {
		while(len>0&&p[at]!=p[len]) len=next[len];
		if(p[at]==p[len]) ++len;
		next[at+1]=len;
		++at;
	}
	at=0,len=0;
	while(at<slen) {
		while(len>0&&s[at]!=p[len]) len=next[len];
		if(s[at]==p[len]) ++len;
		++at;
	}
	return plen-len;
}

void run() {
	vector<string> s;
	scanf("%s",buff); s.PB(buff);
	scanf("%s",buff); s.PB(buff);
	scanf("%s",buff); s.PB(buff);
	REPSZ(i,s) for(int j=SZ(s)-1;j>i;--j) {
		if(contains(s[i],s[j])) s.erase(s.begin()+j);
		else if(contains(s[j],s[i])) { s.erase(s.begin()+i); --i; break; }
	}
	
	int n=SZ(s);
	vector<int> p(n); REP(i,n) p[i]=i;
	VVI d(n,VI(n,INT_MAX)); REP(i,n) REP(j,n) if(i!=j) d[i][j]=append(s[i],s[j]);
	int ret=INT_MAX;
	do {
		int cur=SZ(s[p[0]]);
		FORSZ(i,1,p) cur+=d[p[i-1]][p[i]];
		if(cur<ret) ret=cur;
	} while(next_permutation(p.begin(),p.end()));
	printf("%d\n",ret);
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
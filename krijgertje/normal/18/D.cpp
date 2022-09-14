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

void incr(string &a,string &b) {
	if(SZ(a)==0) { a=b; return; }
	assert(SZ(a)>=SZ(b));
	int ai=SZ(a)-1,bi=SZ(b)-1,c=0;
	while(bi>=0||c!=0) {
		if(bi>=0) c+=b[bi]-'0';
		if(ai<0) a="0"+a,++ai;
		c+=a[ai]-'0';
		a[ai]='0'+c%10;
		c/=10;
		--ai,--bi;
	}
}

string twice(string &s) {
	string ret=s; incr(ret,s); return ret;
}

void run() {
	int n; scanf("%d",&n);
	vector<int> x; REP(i,n) { char buff[10]; int val; scanf("%s%d",buff,&val); x.PB(buff[0]=='w'?+(val+1):-(val+1)); }
	int maxsell=0; REP(i,n) if(x[i]<0) maxsell=max(maxsell,-x[i]);
	vector<int> sellat(maxsell+1,-1); REP(i,n) if(x[i]<0) { assert(sellat[-x[i]]==-1); sellat[-x[i]]=i; }
	vector<int> winat(maxsell+1,-1); REP(i,n) if(x[i]>0&&x[i]<=maxsell&&sellat[x[i]]!=-1&&i<sellat[x[i]]) winat[x[i]]=i;
	vector<string> get(maxsell+1); get[1]="1"; FORE(i,2,maxsell) get[i]=twice(get[i-1]);
	string ret="";
	for(int i=maxsell;i>=1;--i) if(winat[i]!=-1&&sellat[i]!=-1) {
		int a=winat[i],b=sellat[i];
//		printf("%d\n",i-1);
		incr(ret,get[i]);
		for(int j=i-1;j>=1;--j) if(winat[j]!=-1&&sellat[j]!=-1) {
			int c=winat[j],d=sellat[j];
			if(!(d<a||b<c)) { winat[j]=-1,sellat[j]=-1; }			
		}
	}
	if(SZ(ret)==0) ret="0"; printf("%s\n",ret.c_str());
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
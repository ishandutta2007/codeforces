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
#include <climits>
#include <cassert>
#include <ctime>
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

typedef set<int> si;
typedef map<int,set<int> > misi;

int want,need;

misi can1;
misi can2;
misi can4;
misi can8;

void add(si &a,int mult, si &b,si &c) {
	for(si::iterator i=a.begin();i!=a.end();++i) {
		for(si::iterator j=b.begin();j!=b.end();++j) {
			c.insert((*i)*mult+(*j));
			if(SZ(c)>=need) return;
		}
	}
}

void makeall(misi &a,int mult,misi &b,misi &c) {
	for(misi::iterator i=a.begin();i!=a.end();++i) {
		for(misi::iterator j=b.begin();j!=b.end();++j) {
			add(i->second,mult,j->second,c[i->first+j->first]);
			add(i->second,mult,j->second,c[abs(i->first-j->first)]);
			add(i->second,mult,j->second,c[i->first*j->first]);
		}
	}
}

void print(si &a,int ndig,bool oneline,int cnt) {
	for(si::iterator i=a.begin();i!=a.end();++i) {
		char now[10];
		memset(now,'0',sizeof(now)); now[ndig]='\0';
		for(int j=ndig-1,x=*i;x!=0;x/=10,--j) now[j]='0'+x%10;
		if(oneline) printf(" "); 
		printf("%s",now);
		if(!oneline) puts("");
		if(cnt!=-1&&--cnt==0) return;
	}
}

void print(misi &a,int ndig) {
	for(misi::iterator i=a.begin();i!=a.end();++i) {
		printf("%d:",i->first);
		print(i->second,ndig,true,-1);
		puts("");
	}
}



void makewant(misi &a,int mult,misi &b,misi &c) {
	for(misi::iterator i=a.begin();i!=a.end();++i) {
		if(SZ(c[want])>=need) break;
		int test[10],ntest=0;
		if(want>=i->first) test[ntest++]=want-i->first;	//a+b
		test[ntest++]=want+i->first; // -a+b
		if(want<i->first) test[ntest++]=i->first-want; //a-b
		if(i->first!=0&&want%i->first==0) test[ntest++]=want/i->first; // a*b (a!=0)
		REP(j,ntest) add(i->second,mult,b[test[j]],c[want]);
	}
	if(want==0) for(misi::iterator j=b.begin();j!=b.end();++j) { // a*b (a==0)
		if(SZ(c[want])>=need) break;
		add(a[0],mult,j->second,c[want]);
	}
}

void run(int casenr) {
	scanf("%d%d",&want,&need);

	REP(i,10) can1[i].insert(i);
	REP(i,100) can2[i].insert(i);
	REP(i,10000) can4[i].insert(i);
	makeall(can1,10,can1,can2);
	makeall(can2,100,can2,can4);
	makewant(can4,10000,can4,can8);

//	printf("%d\n",SZ(can8[want]));
	print(can8[want],8,false,need);
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
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

bool done[10][20][10];
ll memval[10][20][10];
int memnlast[10][20][10];

ll calc2(int maxprefdig,int ninelen,int last,int &nlast) {
	if(done[maxprefdig][ninelen][last]) { nlast=memnlast[maxprefdig][ninelen][last]; return memval[maxprefdig][ninelen][last]; }
	nlast=last; ll ret=0;
	if(ninelen==0) {
		while(nlast>=0) {
			++ret; nlast-=max(nlast,maxprefdig);
		}
		nlast+=10;
	} else {
		REP(i,10) {
			int nnlast;
			ll cur=calc2(max(9-i,maxprefdig),ninelen-1,nlast,nnlast);
			ret+=cur; nlast=nnlast;
		}
	}
	done[maxprefdig][ninelen][last]=true; memval[maxprefdig][ninelen][last]=ret; memnlast[maxprefdig][ninelen][last]=nlast;
//	printf("\t"); printf("(%d)",maxprefdig); REP(i,ninelen) printf("9"); printf(" %d",last); printf(" => %lld (%d)\n",ret,nlast);
	return ret;
}

ll calc(ll prefix,int ninelen,int last,int &nlast) {
	int maxprefdig=-1;
	for(ll x=prefix;x!=0;x/=10) { int cur=x%10; if(cur>maxprefdig) maxprefdig=cur; }
	ll ret=calc2(maxprefdig,ninelen,last,nlast);
//	printf("%lld ",prefix); REP(i,ninelen) printf("9"); printf(" %d",last); printf(" => %lld (%d)\n",ret,nlast);
	return ret;
}

ll n;

ll bf(ll n) {
	ll ret=0;
	while(n!=0) {
		int cur=-1; for(ll x=n;x!=0;x/=10) cur=max(cur,(int)(x%10));
		++ret; n-=cur;
	}
	return ret;
}

void run(int casenr) {
	cin>>n;

	ll ret=0;
	ll prefix=n/10; int ninelen=0; int last=n%10;
	while(prefix!=0) {
		if(prefix%10==9) { prefix/=10; ++ninelen; continue; }
		int nlast;
		ll cur=calc(prefix,ninelen,last,nlast);
		ret+=cur; --prefix; last=nlast;
	}
	while(ninelen!=0) {
		REP(i,9) {
			int nlast;
			ll cur=calc(9-i,ninelen-1,last,nlast);
			ret+=cur; last=nlast;
		}
		--ninelen;
	}
	if(last!=0) {
		++ret;
		last=0;
	}

	cout<<ret<<endl;
//	cout<<bf(n)<<endl;
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
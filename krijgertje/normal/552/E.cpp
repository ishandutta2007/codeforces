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

const int MAXLEN=5001;
const int MAXN=2501;
const int MAXMULT=15;

char s[MAXLEN+1]; int n;

int mlt[MAXMULT+2],nmlt;

ull psum[MAXN+1];
ull pterm[MAXN+1];
ull nsum[MAXN+1];
ull nterm[MAXN+1];

void run() {
	scanf("%s",s); n=(strlen(s)+1)/2;

	nmlt=0; mlt[nmlt++]=0; mlt[nmlt++]=n; FOR(i,1,n) if(s[2*i-1]=='*') mlt[nmlt++]=i; sort(mlt,mlt+nmlt);

	psum[0]=pterm[0]=1;
	REP(i,n) {
		int dig=s[2*i]-'0';
		if(i==0||i==n||s[2*i-1]=='*') {
			pterm[i+1]=pterm[i]*dig;
			psum[i+1]=psum[i]-pterm[i]+pterm[i+1];
		} else {
			pterm[i+1]=dig;
			psum[i+1]=psum[i]+pterm[i+1];
		}
	}
	nsum[n]=nterm[n]=1;
	for(int i=n;i>0;--i) {
		int dig=s[2*(i-1)]-'0';
		if(i==0||i==n||s[2*i-1]=='*') {
			nterm[i-1]=nterm[i]*dig;
			nsum[i-1]=nsum[i]-nterm[i]+nterm[i-1];
		} else {
			nterm[i-1]=dig;
			nsum[i-1]=nsum[i]+nterm[i-1];
		}
	}
	//REPE(i,n) printf("%d: pterm=%llu, psum=%llu, nterm=%llu, nsum=%llu\n",i,pterm[i],psum[i],nterm[i],nsum[i]);

	ull ret=psum[n];
	REP(i,nmlt) FOR(j,i+1,nmlt) if(mlt[j]-mlt[i]>j-i) {
		ull cur=psum[mlt[i]]-pterm[mlt[i]]+nsum[mlt[j]]-nterm[mlt[j]], pa=pterm[mlt[i]],na=nterm[mlt[i]],pb=pterm[mlt[j]],nb=nterm[mlt[j]],c=psum[mlt[j]]-pb-psum[mlt[i]]+pa-pa*na;
		//printf("%d..%d -> %llu + %llu*(%llu+%llu+%llu)*%llu\n",mlt[i],mlt[j],cur,pa,na,c,pb,nb);
		cur+=pa*(na+c+pb)*nb;
		if(cur>ret) ret=cur;
	}
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}
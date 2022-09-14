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
const int MAXQ=50000;
const int MAXB=3*MAXQ;
typedef struct B { int cnt[26],dir; } B;

int n,nq;
char s[MAXLEN+1];
int ql[MAXQ],qr[MAXQ],qdir[MAXQ];


map<int,int> mp;
B b[MAXB]; int nb;

void make(int want) {
	map<int,int>::iterator at=mp.upper_bound(want); --at;
	if(at->first==want) return;
	if(at->second==-1) {
		mp[want]=-1;
	} else {
		REP(j,26) b[nb].cnt[j]=0; b[nb].dir=b[at->second].dir;
		int lft=want-at->first;
		if(b[at->second].dir==1) {
			REP(j,26) { int cur=min(lft,b[at->second].cnt[j]); b[nb].cnt[j]+=b[at->second].cnt[j]-cur; b[at->second].cnt[j]=cur; lft-=cur; }
		} else {
			for(int j=25;j>=0;--j) { int cur=min(lft,b[at->second].cnt[j]); b[nb].cnt[j]+=b[at->second].cnt[j]-cur; b[at->second].cnt[j]=cur; lft-=cur; }
		}
		mp[want]=nb++;
	}
}
void print() {
	map<int,int>::iterator at=mp.begin();
	while(at->first!=n) {
		map<int,int>::iterator to=at; ++to;
		if(at->second==-1) {
			FOR(j,at->first,to->first) printf("%c",s[j]);
		} else {
			if(b[at->second].dir==1) {
				REP(j,26) REP(k,b[at->second].cnt[j]) printf("%c",'a'+j);
			} else {
				for(int j=25;j>=0;--j) REP(k,b[at->second].cnt[j]) printf("%c",'a'+j);
			}
		}
		at=to;
	}
	puts("");
}

void run() {
	scanf("%d%d%s",&n,&nq,s);
	REP(i,nq) scanf("%d%d%d",&ql[i],&qr[i],&qdir[i]),--ql[i];

	mp[0]=mp[n]=-1; 
	REP(i,nq) {
//		print();
		make(ql[i]);
		make(qr[i]);
		REP(j,26) b[nb].cnt[j]=0; b[nb].dir=qdir[i];
		map<int,int>::iterator at=mp.find(ql[i]);
		while(at->first!=qr[i]) {
			map<int,int>::iterator to=at; ++to;
			if(at->second==-1) {
				FOR(j,at->first,to->first) b[nb].cnt[s[j]-'a']++;
			} else {
				REP(j,26) b[nb].cnt[j]+=b[at->second].cnt[j];
			}
			mp.erase(at); at=to;
		}
		mp[ql[i]]=nb++;
	}
	print();
}

int main() {
	run();
	return 0;
}
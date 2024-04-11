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

const int MAXN=300000;

int n,nq;
char s[MAXN+1];

int calc(int x) { return x>=3?x-2:0; }
void run() {
	scanf("%d%d",&n,&nq);
	scanf("%s",s);
	set<int> have; have.insert(-1); have.insert(n); REP(i,n) if(s[i]!='.') have.insert(i);
	int ret=0; for(set<int>::iterator i=have.begin(),j=have.begin();i!=have.end();j=i++) ret+=calc(*i-*j);
	REP(qi,nq) {
		int at; char c; scanf("%d %c",&at,&c); --at;
		if(c=='.'&&s[at]!='.') {
			set<int>::iterator i=have.find(at),prv=i,nxt=i; --prv,++nxt;
			ret+=calc(*nxt-*prv)-calc(*nxt-*i)-calc(*i-*prv);
			have.erase(i);
		}
		if(c!='.'&&s[at]=='.') {
			set<int>::iterator i=have.insert(at).first,prv=i,nxt=i; --prv,++nxt;
			ret-=calc(*nxt-*prv)-calc(*nxt-*i)-calc(*i-*prv);
		}
		s[at]=c;
		printf("%d\n",ret);
	}

}


int main() {
	run();
	return 0;
}
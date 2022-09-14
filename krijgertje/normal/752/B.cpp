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

const int MAXLEN=1000;

char s[MAXLEN+1],t[MAXLEN+1]; int len;
int mp[26];
int ret[26][2],nret;

void run() {
	scanf("%s%s",s,t); len=strlen(s);
	memset(mp,-1,sizeof(mp)); nret=0;
	REP(i,len) {
		int a=s[i]-'a',b=t[i]-'a';
		if(a==b) {
			if(mp[a]!=-1&&mp[a]!=a) { printf("-1\n"); return; }
			if(mp[a]!=-1) continue;
			mp[a]=a;
		} else {
			if(mp[a]!=-1&&mp[a]!=b) { printf("-1\n"); return; }
			if(mp[b]!=-1&&mp[b]!=a) { printf("-1\n"); return; }
			if(mp[a]!=-1&&mp[b]!=-1) continue;
			mp[a]=b,mp[b]=a,ret[nret][0]=a,ret[nret][1]=b,++nret;
		}
	}
	printf("%d\n",nret); REP(i,nret) printf("%c %c\n",ret[i][0]+'a',ret[i][1]+'a');

}

int main() {
	run();
	return 0;
}
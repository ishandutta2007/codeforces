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

const int MAXN=2000;
const int MAXRET=3*MAXN+10;

int n;
char s[MAXN+1];
char t[MAXN+1];
int cnt[26];

int ret[MAXRET],nret;

char tmp[MAXN];
void apply(int x) {
	if(x==0) return;
	ret[nret++]=x;
	REP(i,n-x) tmp[i+x]=s[i];
	REP(i,x) tmp[x-i-1]=s[n-x+i];
	REP(i,n) s[i]=tmp[i];
}

bool solve() {
	REP(i,26) cnt[i]=0; REP(i,n) ++cnt[s[i]-'a']; REP(i,n) --cnt[t[i]-'a']; REP(i,26) if(cnt[i]!=0) return false;
	int l=(n-1)/2,r=l,pos=0,len=1; bool rev=n%2==0; nret=0;
	int sidx=-1; REP(i,n) if(s[i]==t[l]) { sidx=i; break; } assert(sidx!=-1);
	apply(n-sidx-1);
	apply(1);
	FOR(i,1,n) {
		int a=i%2==1?r+1:l-1;
		int idx=-1; FOR(j,len,n) if(s[j]==t[a]) { idx=j; break; } assert(idx!=-1);
		apply(n-idx-1);
		apply(idx-len+1);
		apply(len);
		if(i%2==1) ++r; else --l; ++len; rev=!rev;
	}
	if(n%2==1) apply(n);
	//printf("%s\n",s);
	REP(i,n) assert(s[i]==t[i]);
	//REP(i,n) if(s[i]!=t[i]) return false;
	return true;
}

void run() {
	scanf("%d%s%s",&n,s,t);
	if(!solve()) { printf("-1\n"); return; }
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

char os[MAXN];
void stress() {
	REP(rep,10000) {
		//n=rand()%26+1; REP(i,n) os[i]=s[i]='a'+i,t[i]='a'+i; os[n]=s[n]=t[n]='\0';
		n=MAXN;
		REP(i,n) s[i]=os[i]=t[i]='a'+rand()%26; os[n]=s[n]=t[n]='\0';
		REP(i,n) { int j=(rand()%1000*1000+rand()%1000)%(i+1); swap(s[i],s[j]); }
		bool res=solve();
		if(res) { printf("."); continue; }
		printf("err\n");
		printf("%d\n%s\n%s\n",n,os,t);
		printf("%s\n",s);
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}
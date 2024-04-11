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

const int MAXN=3000;
const int MAXLEN=3000;

int n;
char a[MAXN][MAXLEN+1];
char b[MAXN][MAXLEN+1];
int len[MAXN];

int want[MAXN];
char changefrom[MAXLEN+1],changeto[MAXLEN+1]; int nchange;
char pref[MAXLEN+1]; int npref;
char suff[MAXLEN+1]; int nsuff;

char ansfrom[MAXLEN+1],ansto[MAXLEN+1]; int nans;

int nxt[MAXLEN+1]; // nxt[i] = length of longest proper border of ansfrom[0..i)



bool solve() {
	REP(i,n) len[i]=strlen(a[i]),assert(strlen(b[i])==len[i]);

	bool found=false;
	REP(i,n) {
		int l=-1,r=-1; REP(j,len[i]) if(a[i][j]!=b[i][j]) { r=j; if(l==-1) l=j; }
		want[i]=l; if(l==-1) continue;
		if(!found) {
			found=true;
			nchange=r-l+1; REP(j,nchange) changefrom[j]=a[i][l+j],changeto[j]=b[i][l+j]; changefrom[nchange]=changeto[nchange]='\0';
			npref=l; REP(j,npref) pref[j]=a[i][l-1-j]; pref[npref]='\0';
			nsuff=len[i]-r-1; REP(j,nsuff) suff[j]=a[i][r+1+j]; suff[nsuff]='\0';
		} else {
			if(r-l+1!=nchange) return false;
			REP(j,nchange) if(changefrom[j]!=a[i][l+j]||changeto[j]!=b[i][l+j]) return false;
			REP(j,npref) if(l-1-j<0||pref[j]!=a[i][l-1-j]) { npref=j; pref[npref]='\0'; break; }
			REP(j,nsuff) if(r+1+j>=len[i]||suff[j]!=a[i][r+1+j]) { nsuff=j; suff[nsuff]='\0'; break; }
		}
	}
	REP(i,n) if(want[i]!=-1) want[i]-=npref;
	assert(found);
	//printf("'%s' -> '%s' (%d) pref: '%s' (%d) suff: '%s' (%d)\n",changefrom,changeto,nchange,pref,npref,suff,nsuff);

	nans=0; for(int i=npref-1;i>=0;--i) ansfrom[nans]=ansto[nans]=pref[i],++nans; REP(i,nchange) ansfrom[nans]=changefrom[i],ansto[nans]=changeto[i],++nans; REP(i,nsuff) ansfrom[nans]=ansto[nans]=suff[i],++nans; ansfrom[nans]=ansto[nans]='\0';

	nxt[0]=nxt[1]=0; FORE(i,2,nans) { nxt[i]=nxt[i-1]; while(nxt[i]!=0&&ansfrom[nxt[i]]!=ansfrom[i-1]) nxt[i]=nxt[nxt[i]]; if(ansfrom[nxt[i]]==ansfrom[i-1]) ++nxt[i]; }
	//printf("nxt:"); REPE(i,nans) printf(" %d",nxt[i]); puts("");
	REP(i,n) {
		int at=0;
		int have=-1;
		REP(j,len[i]) {
			while(at!=0&&ansfrom[at]!=a[i][j]) at=nxt[at];
			if(ansfrom[at]==a[i][j]) ++at;
			if(at==nans) { have=j-nans+1; break; }
		}
		//printf("%d: have=%d want=%d\n",i,have,want[i]);
		if(have!=want[i]) return false;
	}

	return true;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%s",a[i]);
	REP(i,n) scanf("%s",b[i]);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n%s\n%s\n",ansfrom,ansto);

}

int main() {
	run();
	return 0;
}
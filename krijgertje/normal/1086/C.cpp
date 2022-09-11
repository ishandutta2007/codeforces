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

const int MAXLEN=1000000;
const int MAXALPH=26;

int nalph;
char s[MAXLEN+1],a[MAXLEN+1],b[MAXLEN+1]; int len;
char ans[MAXALPH+1];

bool used[MAXALPH];

char tans[MAXALPH]; bool tused[MAXALPH];

void makecomplete() {
	REP(i,nalph) if(ans[i]=='?') {
		REP(j,nalph) if(!used[j]) { ans[i]='a'+j; used[j]=true; break; }
	}
	ans[nalph]='\0';
}

bool go(int at,bool aeq,bool beq) {
	FOR(i,at,len) {
		int x=s[i]-'a';
		int aopt=-1,bopt=-1;
		REP(j,nalph) {
			if(ans[x]!='?'&&ans[x]!='a'+j) continue;
			if(ans[x]=='?'&&used[j]) continue;
			if(aeq&&j<a[i]-'a') continue;
			if(beq&&j>b[i]-'a') continue;
			bool extreme=false;
			if(aeq&&j==a[i]-'a') { aopt=j; extreme=true; }
			if(beq&&j==b[i]-'a') { bopt=j; extreme=true; }
			if(extreme) continue;
			//found in between
			ans[x]='a'+j; used[j]=true;
			makecomplete();
			return true;
		}
		if(aopt!=-1&&bopt!=-1&&aopt!=bopt) {
			REP(k,nalph) tans[k]=ans[k],tused[k]=used[k];
			ans[x]='a'+aopt; used[aopt]=true; if(go(at+1,true,false)) return true;
			REP(k,nalph) ans[k]=tans[k],used[k]=tused[k];
			ans[x]='a'+bopt; used[bopt]=true; if(go(at+1,false,true)) return true;
			return false;
		} else {
			if(aopt==-1&&bopt==-1) return false;
			int opt=aopt!=-1?aopt:bopt;
			ans[x]='a'+opt; used[opt]=true; if(opt>a[i]-'a') aeq=false; if(opt<b[i]-'a') beq=false;
		}
	}
	makecomplete();
	return true;
}

bool solve() {
	REP(i,nalph) used[i]=false,ans[i]='?';
	return go(0,true,true);
}

void run() {
	scanf("%d",&nalph);
	scanf("%s%s%s",s,a,b); len=strlen(s);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%s\n",ans);
}

bool verify(vector<int> p) {
	bool aeq=true,beq=true,ok=true;
	REP(i,len) {
		char c='a'+p[s[i]-'a'];
		if(aeq) { if(c<a[i]) { ok=false; break; } if(c>a[i]) aeq=false; }
		if(beq) { if(c>b[i]) { ok=false; break; } if(c<b[i]) beq=false; }
	}
	return ok;
}

bool bfsolve() {
	vector<int> p(nalph); REP(i,nalph) p[i]=i;
	do {
		if(verify(p)) return true;
	} while(next_permutation(p.begin(),p.end()));
	return false;
}

bool verify() {
	vector<int> p(nalph); REP(i,nalph) p[i]=ans[i]-'a';
	return verify(p);
}

void stress() {
	REP(rep,100000) {
		nalph=4; len=10;
		REP(i,len) s[i]='a'+rand()%nalph; s[len]='\0';
		REP(i,len) a[i]='a'+rand()%nalph; a[len]='\0';
		REP(i,len) b[i]='a'+rand()%nalph; b[len]='\0';
		REP(i,len) if(a[i]!=b[i]) { if(a[i]>b[i]) REP(j,len) swap(a[j],b[j]); break; }
		bool have=solve();
		bool want=bfsolve();
		if(have==want&&(!have||verify())) { printf("."); continue; }
		printf("err\n");
		printf("%s %s %s -> have=%s want=%s\n",s,a,b,have?"yes":"no",want?"yes":"no"); if(have) printf("ans=%s\n",ans);
		break;
	}
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	//stress();
	return 0;
}
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

const int MAXN=100000;
const int ALPH=8;
const int MAXDST=ALPH*2-1;

int n; char s[MAXN+1];

int mxdst; ll cntdst;
bool have[ALPH];
int d[MAXN][ALPH]; // d[a][c]=dd[s[a]][c]+((id[a]>>c)&1)
int dd[ALPH][ALPH];
int id[MAXN];
int cnt[ALPH][1<<ALPH];

int q[MAXN],qhead,qtail;

void init() {
	mxdst=0,cntdst=0;
	memset(have,false,sizeof(have)); REP(i,n) have[s[i]-'a']=true;
	REP(a,n) REP(c,ALPH) d[a][c]=INT_MAX; REP(sc,ALPH) REP(tc,ALPH) dd[sc][tc]=INT_MAX;
	REP(tc,8) if(have[tc]) {
		qhead=qtail=0; REP(a,n) if(s[a]=='a'+tc) { d[a][tc]=0; q[qhead++]=a; }
		while(qtail<qhead) {
			int a=q[qtail++],c=s[a]-'a'; //printf("\t%d->%c=%d\n",a,'a'+tc,d[a][tc]);
			if(a-1>=0&&d[a-1][tc]==INT_MAX) { d[a-1][tc]=d[a][tc]+1; q[qhead++]=a-1; }
			if(a+1< n&&d[a+1][tc]==INT_MAX) { d[a+1][tc]=d[a][tc]+1; q[qhead++]=a+1; }
			if(dd[c][tc]==INT_MAX) { dd[c][tc]=d[a][tc]; REP(b,n) if(s[b]-'a'==c&&d[b][tc]==INT_MAX) { d[b][tc]=d[a][tc]+1; q[qhead++]=b; } }
		}
	}
	REP(a,n) { int msk=0; REP(c,ALPH) if(have[c]) { int diff=d[a][c]-dd[s[a]-'a'][c]; assert(diff==0||diff==1); if(diff==1) msk|=1<<c; } id[a]=msk; }
	memset(cnt,0,sizeof(cnt)); REP(a,n) ++cnt[s[a]-'a'][id[a]];
	//printf("%s\n",s);
	//REP(sc,ALPH) if(have[sc]) { printf("%c:",'a'+sc); REP(tc,ALPH) if(have[tc]) printf("%3d",dd[sc][tc]); puts(""); }
	//REP(a,n) { printf("%d=%c",a,s[a]); REP(c,ALPH) if(have[c]) printf("%d",(id[a]>>c)&1); REP(c,ALPH) if(have[c]) printf("%3d",d[a][c]); puts(""); }
}
int solve1(int a,int b) {
	int ret=abs(a-b);
	REP(c,8) if(have[c]) {
		int cur=d[a][c]+1+d[b][c];
		if(cur<ret) ret=cur;
	}
//	if(ret==4) printf("solve1 %d->%d\n",a,b);
	return ret;
}
int solve2(int a,int sb,int msk) {
	int ret=INT_MAX;
	REP(c,8) if(have[c]) {
		int cur=d[a][c]+dd[sb][c]+1+((msk>>c)&1);
		if(cur<ret) ret=cur;
	}
//	if(ret==4) printf("solve2 %d->%c (%x)\n",a,'a'+sb,msk);
	return ret;
}
void update(int cur,int cnt) {
	if(cur>mxdst) mxdst=cur,cntdst=0;
	if(cur==mxdst) cntdst+=cnt;
}

void run() {
	scanf("%d%s",&n,s); n=strlen(s); //n=MAXN; REP(i,n) s[i]='a'+rand()%8; s[n]='\0';
	init();
	//REP(i,n) FOR(j,i+1,n) if(solve1(i,j)==4) printf("ans==%d %d\n",i,j);
	REP(i,n) {
		FORE(j,i-MAXDST,i+MAXDST) if(j>=0&&j!=i&&j<n) update(solve1(i,j),1);
		FORE(j,i-MAXDST,i+MAXDST) if(j>=0&&j<n) --cnt[s[j]-'a'][id[j]];

		REP(sb,ALPH) if(have[sb]) {
			int lb=INT_MAX,need=0; REP(c,ALPH) if(have[c]) { int cur=d[i][c]+dd[sb][c]+2; if(cur<lb) lb=cur; if(cur==mxdst) need|=1<<c; } if(lb<mxdst) continue;
			//REP(msk,1<<ALPH) 
			for(int msk=need;msk<(1<<ALPH);msk=(msk+1)|need)
				if(cnt[sb][msk]) update(solve2(i,sb,msk),cnt[sb][msk]);
		}
		FORE(j,i-MAXDST,i+MAXDST) if(j>=0&&j<n) ++cnt[s[j]-'a'][id[j]];
	}
	assert(cntdst%2==0); printf("%d %lld\n",mxdst,cntdst/2);
}

int main() {
	run();
	return 0;
}
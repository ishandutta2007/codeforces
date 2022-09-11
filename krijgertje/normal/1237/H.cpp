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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }
 
const int MAXN=4000;
 
int n;
char a[MAXN+1];
char b[MAXN+1];
vector<int> ans;
 
int last;
int delta[2][2];
 
void perform(int revlen) {
	ans.PB(revlen);
	reverse(a,a+revlen);
}
void performb(int revlen) {
	last=revlen;
	reverse(b,b+revlen);
}
 
bool solve() {
	ans.clear(); last=-1;
	REP(x,2) REP(y,2) delta[x][y]=0;
	for(int i=0;i<n;i+=2) { int x=a[i]-'0',y=a[i+1]-'0'; ++delta[x][y]; }
	for(int i=0;i<n;i+=2) { int x=b[i]-'0',y=b[i+1]-'0'; swap(x,y); --delta[x][y]; }
	if(delta[0][0]!=0||delta[1][1]!=0) return false;
	assert(delta[0][1]+delta[1][0]==0);
	if(delta[0][1]!=0) {
		//printf("\n%s\n%s\n",a,b);
		int cura=0,posa=-1; for(int i=0;i<n;i+=2) { int x=a[i]-'0',y=a[i+1]-'0'; if(x==0&&y==1) ++cura; else if(x==1&&y==0) --cura; if(cura==delta[0][1]) { posa=i+2; break; } }
		int curb=0,posb=-1; for(int i=0;i<n;i+=2) { int x=b[i]-'0',y=b[i+1]-'0'; if(x==0&&y==1) ++curb; else if(x==1&&y==0) --curb; if(curb==delta[0][1]) { posb=i+2; break; } }
		if(posa!=-1) perform(posa); else if(posb!=-1) performb(posb); else assert(false);
	}

	REP(x,2) REP(y,2) delta[x][y]=0;
	for(int i=0;i<n;i+=2) { int x=a[i]-'0',y=a[i+1]-'0'; ++delta[x][y]; }
	for(int i=0;i<n;i+=2) { int x=b[i]-'0',y=b[i+1]-'0'; swap(x,y); --delta[x][y]; }
	REP(x,2) REP(y,2) assert(delta[x][y]==0);
 
	for(int have=0;have<n;have+=2) {
		int x=b[n-have-2]-'0',y=b[n-have-1]-'0';
		int pos=-1; for(int i=have;i<n;i+=2) { int xx=a[i]-'0',yy=a[i+1]-'0'; if(xx==y&&yy==x) { pos=i; break; } } assert(pos!=-1);
		if(pos!=0) perform(pos);
		perform(pos+2);
		//printf("\t%s\n\t%s\n\n",a,b);
	}
	//printf("%s\n%s\n",a,b);
	if(last!=-1) perform(last),performb(last),last=-1;
	return true;
}
 
void run() {
	scanf("%s",a); n=strlen(a);
	scanf("%s",b); assert(strlen(b)==n);
	if(!solve()) { printf("-1\n"); return; }
	printf("%d\n",SZ(ans)); REPSZ(i,ans) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}
 
int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}
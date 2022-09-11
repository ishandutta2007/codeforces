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

const int MAXN=1000000;

char s[MAXN+1]; int n;

char t[2*MAXN+1];

char u[4*MAXN];
int p[4*MAXN-1];

int c[MAXN];

int ans[MAXN];

void run() {
	scanf("%d%s",&n,s); n=strlen(s);
	//printf("%s\n",s);

	REP(i,n) t[2*i+0]=t[2*(n-i-1)+1]=s[i]; t[2*n]='\0';
	//printf("%s\n",t);
	REP(i,2*n) u[2*i+0]=t[i]; REP(i,2*n-1) u[2*i+1]='#'; u[4*n-1]='\0';
	//printf("%s\n",u);

	int bcent=0,br=-1,crad=0,nu=4*n-1;
	REP(i,nu) {
		if(i<=br) crad=min(p[2*bcent-i],br-i); else crad=0;
		while(i+crad<nu&&i-crad>=0&&u[i+crad]==u[i-crad]) ++crad;
		p[i]=crad;
		if(i+crad-1>br) bcent=i,br=i+crad-1;
	}
	//printf("p:"); REP(i,nu) printf(" %d",p[i]); puts("");

	REP(i,n) {
		int ulen=p[4*i+1]; if(ulen%2==1) --ulen; if(ulen!=0&&ulen%4==0) ulen-=2; c[i]=(ulen/2+1)/2;
		//printf("%d: %d -> %d\n",i,ulen,c[i]);
	}
	int nc=n/2;
	//printf("c:"); REP(i,nc) printf(" %d",c[i]); puts("");

	REP(i,n) ans[i]=0;
	REP(i,nc) if(c[i]!=0) { int idx=i-c[i]+1; ans[idx]=max(ans[idx],2*c[i]-1); }
	FOR(i,1,n) ans[i]=max(ans[i],ans[i-1]-2);
	//printf("ans:"); REPE(i,nc) printf(" %d",ans[i]);

	int nret=(n+1)/2;
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ans[i]==0?-1:ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}
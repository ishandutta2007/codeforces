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

const int MAXX=200000;
const int MAXV=400000;

int nx;
int x[MAXX];
int nv;
int v[MAXV];
int cnt[MAXX];

void run() {
	scanf("%d",&nx);
	REP(i,nx) scanf("%d",&x[i]);
	scanf("%d",&nv);
	REP(i,nv) { scanf("%d",&v[i]); --v[i]; }
	REP(i,nx) cnt[i]=0; REP(i,nv) cnt[v[i]]++;

	if(nv==1) {
		printf("0\n");
		return;
	}
	if(nx==2) {
		ll ret=(ll)(x[1]-x[0])*(nv-1);
		cout<<ret<<endl;
		return;
	}
	//REP(i,nx) printf("%d ",cnt[i]); puts("");

	int a=1;
	while(a<nx-2&&cnt[a]==cnt[a+1]) ++a;
	if(a>=nx-2) {
		int minend=(cnt[1]-1)/2;
		if(cnt[1]%2==1) {
			ll ret=(ll)(x[nx-1]-x[0])*cnt[1];
			assert(cnt[0]==minend||cnt[0]==minend+1); if(cnt[0]==minend) ret-=x[1]-x[0];
			assert(cnt[nx-1]==minend||cnt[nx-1]==minend+1); if(cnt[nx-1]==minend) ret-=x[nx-1]-x[nx-2];
			cout<<ret<<endl;
			return;
		}
		assert(cnt[0]==minend||cnt[0]==minend+1||cnt[0]==minend+2);
		assert(cnt[nx-1]==minend||cnt[nx-1]==minend+1||cnt[nx-1]==minend+2);
		assert(cnt[0]==minend+1||cnt[nx-1]==minend+1);
		if(cnt[0]==minend||cnt[nx-1]==minend) {
			ll ret=(ll)(x[nx-1]-x[0])*cnt[1];
			if(cnt[0]==minend) ret-=2*(x[1]-x[0]);
			if(cnt[nx-1]==minend) ret-=2*(x[nx-1]-x[nx-2]);
			cout<<ret<<endl;
			return;
		}
		if(cnt[0]==minend+2||cnt[nx-1]==minend+2) {
			ll ret=(ll)(x[nx-1]-x[0])*cnt[1];
			cout<<ret<<endl;
			return;
		}
		bool allsame=true; FOR(i,2,nx) if(x[i]-x[i-1]!=x[1]-x[0]) allsame=false;
		if(allsame) {
			ll ret=(ll)(x[nx-1]-x[0])*cnt[1];
			ret-=x[1]-x[0];
			cout<<ret<<endl;
			return;
		}
		cout<<-1<<endl;
		return;
	}
	{
		int at,dir;
		if(cnt[a]>cnt[a+1]) at=a,dir=-1; else at=a+1,dir=+1;
		//printf("%d %d (%d: %d %d)\n",at,dir,a,cnt[a],cnt[a+1]);
		ll ret=0; --cnt[at];
		while(true) {
			int nat=at+dir; if(cnt[nat]==0) break;
			--cnt[nat]; ret+=abs(x[at]-x[nat]); at=nat; if(at==0||at==nx-1) dir=-dir;
		}
		REP(i,nx) assert(cnt[i]==0);
		cout<<ret<<endl;
		return;
	}
}

int main() {
	run();
	return 0;
}
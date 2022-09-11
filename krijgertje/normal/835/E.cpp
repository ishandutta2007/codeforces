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

const int MAXLG=9;
const int MAXN=1<<(MAXLG+1);

int n,x,y;
vector<int> q;
vector<int> qq;
map<vector<int>,bool> mem;

bool query() {
	qq.clear(); REPSZ(i,q) if(0<=q[i]&&q[i]<n) qq.PB(q[i]);
	if(SZ(qq)==0) return false;
	if(mem.count(qq)) return mem[qq];
	printf("? %d",SZ(qq)); REPSZ(i,qq) printf(" %d",qq[i]+1); puts(""); fflush(stdout);
	int expect=SZ(qq)%2==0?0:x;
	int actual; scanf("%d",&actual);
	bool ret=expect!=actual;
	//printf("%s\n",ret?"odd":"even");
	return mem[qq]=ret;
}

void run() {
	scanf("%d%d%d",&n,&x,&y);

	vector<bool> diff(MAXLG+1);
	REPE(i,MAXLG) {
		q.clear();
		REP(j,MAXN) if(((j>>i)&1)==0) q.PB(j);
		diff[i]=query();
	}
	//printf("diff:"); REPE(i,MAXLG) printf(" %d",diff[i]?1:0); puts("");
	vector<int> fix(MAXLG+1,-1);
	REPE(i,MAXLG) if(diff[i]) { fix[i]=0; break; }
	REPE(i,MAXLG) if(fix[i]==-1) {
		q.clear(); fix[i]=0;
		REP(j,MAXN) {
			bool ok=true;
			REPE(k,MAXLG) if(fix[k]!=-1&&((j>>k)&1)!=fix[k]) ok=false;
			if(ok) q.PB(j);
		}
		fix[i]=query()?0:1;
	}
	int a=0; REPE(i,MAXLG) if(fix[i]==1) a|=1<<i;
	int b=a; REPE(i,MAXLG) if(diff[i]) b^=1<<i;
	if(a>b) swap(a,b);
	printf("! %d %d\n",a+1,b+1); fflush(stdout);
}

int main() {
	run();
	return 0;
}
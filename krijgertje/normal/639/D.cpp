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

const int MAXN=200000;

int n,want,t5,t1;
int x[MAXN];

ll q[5][MAXN]; int qhead[5],qtail[5];

void run() {
	scanf("%d%d%d%d",&n,&want,&t5,&t1);
	REP(i,n) scanf("%d",&x[i]); sort(x,x+n);
	if(5*t1<t5) t5=5*t1;

	ll ret=LLONG_MAX;
	REP(off,5) {
		//printf("off=%d\n",off);
		REP(k,5) qhead[k]=qtail[k]=0; int cnt=0; ll sum=0;
		REP(i,n) {
			int n1=(off-x[i])%5; if(n1<0) n1+=5;
			ll cost=n1*t1-(ll)(x[i]+n1-off)/5*t5;
			q[n1][qhead[n1]++]=cost; sum+=cost; ++cnt; //printf("\t%d->%d (%d) [%I64d] (%d,%I64d)\n",x[i],x[i]+n1,n1,cost,cnt,sum);
			if(cnt>want) {
				int idx=-1; REP(k,5) if(qtail[k]<qhead[k]&&(idx==-1||q[k][qtail[k]]>q[idx][qtail[idx]])) idx=k; assert(idx!=-1); //printf("\t\tremoving %d\n",idx);
				sum-=q[idx][qtail[idx]++]; --cnt;
			}
			if(cnt==want) {
				ll cur=sum+(ll)(x[i]+n1-off)/5*t5*cnt;
				//printf("\t\t->%I64d\n",cur);
				if(cur<ret) ret=cur;
			}
		}
	}
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}
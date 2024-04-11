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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int n;

int nsuff;
int suffgcd[100000];
int suffcnt[100000];

map<int,ll> cnt;

void run() {
	nsuff=0;

	scanf("%d",&n);
	REP(i,n) {
		int a; scanf("%d",&a);

		int at=0;
		REP(j,nsuff) {
			int ngcd=gcd(suffgcd[j],a),ncnt=suffcnt[j];
			if(at!=0&&suffgcd[at-1]==ngcd) suffcnt[at-1]+=ncnt; else suffgcd[at]=ngcd,suffcnt[at]=ncnt,++at;
		}
		if(at!=0&&suffgcd[at-1]==a) suffcnt[at-1]++; else suffgcd[at]=a,suffcnt[at]=1,++at;
		nsuff=at;

		REP(j,nsuff) cnt[suffgcd[j]]+=suffcnt[j];

		//REP(j,nsuff) printf("%d*%d ",suffcnt[j],suffgcd[j]); puts("");
	}

	int nq; scanf("%d",&nq);
	REP(i,nq) {
		int q; scanf("%d",&q);
		cout<<cnt[q]<<endl;
	}



}

int main() {
	run();
	return 0;
}
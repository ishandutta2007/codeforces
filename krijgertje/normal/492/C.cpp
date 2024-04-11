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

typedef struct E {
	int have,each;
} E;
bool operator<(const E &p,const E &q) { return p.each<q.each; }
E e[100000]; int ne;

ll lim,want,have;

void run() {
	cin>>ne>>lim>>want; want*=ne;
	REP(i,ne) scanf("%d%d",&e[i].have,&e[i].each); sort(e,e+ne);
	have=0; REP(i,ne) have+=e[i].have;
	int at=0; ll ret=0;
	while(at<ne&&have<want) {
		ll cur=(ll)min((ll)lim-e[at].have,want-have);
		ret+=cur*e[at].each; have+=cur; e[at].have+=cur; ++at;
	}
	cout<<ret<<endl;

}

int main() {
	run();
	return 0;
}
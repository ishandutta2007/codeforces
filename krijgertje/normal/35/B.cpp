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
#include <list>
#include <cassert>
#include <climits>
#include <cstring>
#include <stack>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

char buff[100];

void run() {
	int H,W,nq; scanf("%d%d%d",&H,&W,&nq);
	int nshelve=H*W;
	map<string,int> where;
	vector<bool> have(nshelve,false);
	REP(i,nq) {
		int type; scanf("%d",&type);
		if(type==+1) {
			int x,y; scanf("%d%d %s",&x,&y,buff); int z=(x-1)*W+(y-1); string s=buff;
			while(z<nshelve&&have[z]) ++z; if(z==nshelve) continue;
			have[z]=true; where[s]=z;
		}
		if(type==-1) {
			scanf(" %s",buff); string s=buff;
			if(where.count(s)) {
				int z=where[s];
				where.erase(s);
				have[z]=false;
				printf("%d %d\n",z/W+1,z%W+1);
			} else {
				printf("%d %d\n",-1,-1);
			}
		}
	}
}

void gen() {
	printf("%d %d %d\n",30,30,1000);
	REP(i,1000) {
		printf("+1 %d %d x",1,1); for(int x=i;x!=0;x/=10) printf("%c",'a'+x%10); puts("");
	}
}

int main() {
//	gen(); return 0;
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
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

int nperson,nteam;

ll calc(ll x) { return x*(x-1)/2; }

void run() {
	scanf("%d%d",&nperson,&nteam);
	ll ansl,ansh;
	int sz1=nperson/nteam,n1=nteam-nperson%nteam,sz2=sz1+1,n2=nteam-n1;
	ansl=n1*calc(sz1)+n2*calc(sz2);
	ansh=(nteam-1)*calc(1)+(1)*calc(nperson-nteam+1);
	cout<<ansl<<" "<<ansh<<endl;
}

int main() {
	run();
	return 0;
}
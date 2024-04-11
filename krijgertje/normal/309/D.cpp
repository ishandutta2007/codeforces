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
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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

int nholes,nskip;

void run(int casenr) {
	scanf("%d%d",&nholes,&nskip);
	int L=nholes+1;
	ll ret=0;
	// FORE(a,1+nskip,nholes-nskip) FORE(b,1+nskip,nholes-nskip) FORE(c,1+nskip,nholes-nskip) if((b-2*a)*(2*L-c-2*a)+3*b*c<0) ret+=3;
//		int val=c*(a+b)+(b-2*a)*(L-a);
	FORE(a,1+nskip,nholes-nskip) {
		if(nholes-a+1<a) continue;
		int maxb=min(nholes-nskip,2*a-1);
		ll cur=0;
		FORE(b,1+nskip,maxb) {
			int minc=1+nskip;
			int maxc=min(nholes-nskip,((2*a-b)*(L-a)-1)/(a+b));
			if(minc<=maxc) cur+=maxc-minc+1;
		}
//		printf("%d -> %lld [%d]\n",a,cur,nholes-a+1);
		ret+=cur;
		if(nholes-a+1>a) ret+=cur;
	}
	cout<<(3*ret)<<endl;
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
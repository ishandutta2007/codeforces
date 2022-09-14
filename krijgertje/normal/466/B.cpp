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

int n,a,b;
ll need;

void run() {
	scanf("%d%d%d",&n,&a,&b); need=(ll)6*n;
	
	ll ra=-1,rb=-1;
	if((ll)a*b>=need) ra=a,rb=b;
	for(int i=min(a,b);;++i) {
		ll j=(need+i-1)/i;
		if(i>j) break;
		if(j<max(a,b)) j=max(a,b);
		if(ra==-1||rb==-1||(ll)i*j<ra*rb) ra=a<b?i:j,rb=a<b?j:i;
	}
	cout<<(ra*rb)<<endl<<ra<<" "<<rb<<endl;
	
}

int main() {
	run();
	return 0;
}
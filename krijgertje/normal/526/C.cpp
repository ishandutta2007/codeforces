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

int maxw,v[2],w[2];

void run() {
	scanf("%d%d%d%d%d",&maxw,&v[0],&v[1],&w[0],&w[1]);
	if((ll)v[0]*w[1]<(ll)v[1]*w[0]) swap(v[0],v[1]),swap(w[0],w[1]);
	ll ret=0;
	if(maxw/w[0]<w[0]) {
		for(int n0=0;n0*w[0]<=maxw;++n0) {
			int n1=(maxw-n0*w[0])/w[1];
			ll cur=(ll)n0*v[0]+(ll)n1*v[1];
			if(cur>ret) ret=cur;
		}
	} else {
		for(int n1=0;n1*w[1]<=maxw&&n1<w[0];++n1) {
			int n0=(maxw-n1*w[1])/w[0];
			ll cur=(ll)n0*v[0]+(ll)n1*v[1];
			if(cur>ret) ret=cur;
		}
	}
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}
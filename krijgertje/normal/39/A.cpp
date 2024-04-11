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

char s[100000];

void run() {
	int a; scanf("%d",&a);
	scanf("%s",s+1); s[0]='+';
	int ret=0;
	vector<int> mult;
	int at=0;
	while(s[at]!='\0') {
		//printf("\t%d\n",at);
		assert(s[at]=='+'||s[at]=='-'); 
		int sgn=s[at]=='+'?+1:-1; ++at;
		int x;
		if(isdigit(s[at])) {
			x=0;
			while(isdigit(s[at])) x=x*10+s[at++]-'0';
			assert(s[at++]=='*');
		} else {
			x=1;
		}
		if(s[at+0]=='+'&&s[at+1]=='+'&&s[at+2]=='a') {
			ret+=sgn*x; mult.PB(sgn*x); at+=3; continue;
		} else if(s[at+0]=='a'&&s[at+1]=='+'&&s[at+2]=='+') {
			mult.PB(sgn*x); at+=3; continue;
		} else assert(false);
	}
	sort(mult.begin(),mult.end());
	//REPSZ(i,mult) printf("%d\n",mult[i]); printf("=%d\n",ret);
	REPSZ(i,mult) { ret+=a*mult[i]; ++a; }
	printf("%d\n",ret);
}


int main() {
//	freopen ("input.txt","r",stdin);
//	freopen ("output.txt","w",stdout);
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
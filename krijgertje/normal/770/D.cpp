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

const int MAXLEN=100;

char s[MAXLEN+1]; int slen;
int d[MAXLEN],match[MAXLEN],dmx;
int stck[MAXLEN],nstck;

vector<string> solve(int h,int l,int r) {
	if(match[l]==r) {
		int w; vector<string> ret;
		if(l+1==r) {
			w=5; ret=vector<string>(h,string(w,' '));
		} else {
			vector<string> sub=solve(h-2,l+1,r-1);
			w=SZ(sub[0])+2; ret=vector<string>(h,string(w,' ')); REPSZ(i,sub) REPSZ(j,sub[i]) ret[i+1][j+1]=sub[i][j];
		}
		ret[0][0]=ret[0][w-1]=ret[h-1][0]=ret[h-1][w-1]='+'; ret[0][1]=ret[0][w-2]=ret[h-1][1]=ret[h-1][w-2]='-'; FOR(x,1,h-1) ret[x][0]=ret[x][w-1]='|'; return ret;
	} else {
		assert(match[l]>l&&match[l]<r);
		vector<string> a=solve(h,l,match[l]),b=solve(h,match[l]+1,r);
		vector<string> ret(h); REPSZ(i,ret) ret[i]=a[i]+b[i]; return ret;
	}
}

void run() {
	scanf("%d%s",&slen,s); slen=strlen(s);
	nstck=0;
	REP(i,slen) if(s[i]=='[') { d[i]=nstck; stck[nstck++]=i; } else { assert(nstck>0); int j=stck[--nstck]; d[i]=d[j]; match[i]=j,match[j]=i; } assert(nstck==0);
	dmx=0; FOR(i,1,slen) if(d[i]>dmx) dmx=d[i];
	vector<string> ret=solve(3+2*dmx,0,slen-1);
	REPSZ(i,ret) printf("%s\n",ret[i].c_str());
}

int main() {
	run();
	return 0;
}
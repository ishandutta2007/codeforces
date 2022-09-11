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

const int MAXLEN=10;

int nq; char buff[MAXLEN+1];

int n;
map<string,int> mp;
vector<string> name;
vector<vector<string> > have;

void run() {
	mp.clear();
	name.clear(); n=0;
	have.clear();
	scanf("%d",&nq);
	REP(i,nq) {
		scanf("%s",buff); if(!mp.count(buff)) mp[buff]=n++,name.PB(buff),have.PB(vector<string>()); int id=mp[buff];
		int cnt; scanf("%d",&cnt); REP(j,cnt) { scanf("%s",buff); have[id].PB(buff); }
	}
	REP(i,n) REPSZ(j,have[i]) reverse(have[i][j].begin(),have[i][j].end());
	REP(i,n) sort(have[i].begin(),have[i].end());
	REP(i,n) { int cnt=0; REPSZ(j,have[i]) { while(cnt>0&&SZ(have[i][j])>=SZ(have[i][cnt-1])&&have[i][j].substr(0,SZ(have[i][cnt-1]))==have[i][cnt-1]) --cnt; have[i][cnt++]=have[i][j]; } have[i].resize(cnt); }
	REP(i,n) REPSZ(j,have[i]) reverse(have[i][j].begin(),have[i][j].end());
	printf("%d\n",n); REP(i,n) { printf("%s %d",name[i].c_str(),SZ(have[i])); REPSZ(j,have[i]) printf(" %s",have[i][j].c_str()); puts(""); }
}

int main() {
	run();
	return 0;
}
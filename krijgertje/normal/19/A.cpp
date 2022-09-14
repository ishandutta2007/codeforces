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
typedef struct Team {
	string name;
	int points,scored,against;
} Team;
bool operator<(const Team &a,const Team &b) {
	if(a.points!=b.points) return a.points>b.points;
	if(a.scored-a.against!=b.scored-b.against) return a.scored-a.against>b.scored-b.against;
	if(a.scored!=b.scored) return a.scored>b.scored;
	return false;
}

void run() {
	int n; scanf("%d",&n);
	vector<Team> teams;
	map<string,int> name2id;
	
	REP(i,n) { scanf("%s",buff); teams.PB((Team){buff,0,0,0}); name2id[buff]=i; }
	REP(i,n*(n-1)/2) {
		int a,b; scanf("%s %d:%d",buff,&a,&b);
		char *pos=strchr(buff,'-');
		int ai=name2id[string(buff,pos)];
		int bi=name2id[string(pos+1)];
		teams[ai].scored+=a,teams[ai].against+=b;
		teams[bi].scored+=b,teams[bi].against+=a;
		if(a>b) teams[ai].points+=3; else if(b>a) teams[bi].points+=3; else teams[ai].points++,teams[bi].points++;
	}
	sort(teams.begin(),teams.end());
	
	vector<string> res;
	REP(i,n/2) res.PB(teams[i].name);
	sort(res.begin(),res.end());
	REPSZ(i,res) printf("%s\n",res[i].c_str());
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
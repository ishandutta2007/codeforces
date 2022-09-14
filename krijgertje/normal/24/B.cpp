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

int get[]={25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

typedef struct Driver {
	Driver(string name):name(name),points(0),places(vector<int>()) {}
	string name;
	int points;
	vector<int> places;
	void add(int x) { if(x<10) points+=get[x]; while(x>=SZ(places)) places.PB(0); places[x]++; }
} Driver;

bool origrule;
bool operator<(const Driver &a,const Driver &b) {
	if(!origrule&&a.places[0]!=b.places[0]) return a.places[0]>b.places[0];
	if(a.points!=b.points) return a.points>b.points;
	return a.places>b.places;
}

void run() {
	int nraces; scanf("%d",&nraces);
	map<string,int> name2id;
	vector<Driver> drivers;
	REP(i,nraces) {
		int nfinish; scanf("%d",&nfinish);
		REP(j,nfinish) {
			scanf("%s",buff); string s=buff;
			int id;
			if(!name2id.count(s)) { id=name2id[s]=SZ(drivers); drivers.PB(Driver(s)); } else id=name2id[s];
			drivers[id].add(j);
		}
	}
	origrule=true; sort(drivers.begin(),drivers.end()); printf("%s\n",drivers[0].name.c_str());
	origrule=false; sort(drivers.begin(),drivers.end()); printf("%s\n",drivers[0].name.c_str());
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
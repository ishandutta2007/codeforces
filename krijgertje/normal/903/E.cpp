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

const int MAXN=2500;
const int MAXLEN=5000;

int n,len;
string s[MAXN];
char buff[MAXLEN+1];

bool test(string res) {
	REP(i,n) {
		int c1=-1,c2=-1;
		REP(j,len) if(s[i][j]!=res[j]) { if(c1==-1) c1=j; else if(c2==-1) c2=j; else return false; }
		if(c1==-1&&c2==-1) {
			int mask=0; bool ok=false; REP(j,len) { int x=s[i][j]-'a'; if(mask&(1<<x)) ok=true; else mask|=1<<x; } if(!ok) return false;
		} else {
			assert(c1!=-1&&c2!=-1);
			if(s[i][c1]!=res[c2]||s[i][c2]!=res[c1]) return false;
		}
	}
	return true;
}

void run() {
	scanf("%d%d",&n,&len); REP(i,n) { scanf("%s",buff); s[i]=buff; }
	string sorted=s[0]; sort(sorted.begin(),sorted.end()); FOR(i,1,n) { string tmp=s[i]; sort(tmp.begin(),tmp.end()); if(tmp!=sorted) { printf("-1\n"); return; } }
	int diff=1; while(diff<n&&s[0]==s[diff]) ++diff; if(diff>=n) { string ret=s[0]; swap(ret[0],ret[1]); printf("%s\n",ret.c_str()); return; }
	vector<int> pos; REP(i,len) if(s[0][i]!=s[diff][i]) pos.PB(i);
	assert(SZ(pos)!=0&&SZ(pos)!=1);
	if(SZ(pos)==2) {
		assert(s[0][pos[0]]==s[diff][pos[1]]&&s[0][pos[1]]==s[diff][pos[0]]);
		if(test(s[0])) { printf("%s\n",s[0].c_str()); return; }
		string direct=s[0]; swap(direct[pos[0]],direct[pos[1]]); if(test(direct)) { printf("%s\n",direct.c_str()); return; }
		REP(i,2) REP(j,len) if(j!=pos[1-i]&&s[0][j]==s[0][pos[1-i]]) { string indirect=s[0]; swap(indirect[pos[i]],indirect[j]); if(test(indirect)) { printf("%s\n",indirect.c_str()); return; } }
	}
	if(SZ(pos)==3) {
		REP(i,3) FOR(j,i+1,3) { string direct=s[0]; swap(direct[pos[i]],direct[pos[j]]); if(test(direct)) { printf("%s\n",direct.c_str()); return; } }
	}
	if(SZ(pos)==4) {
		REP(i,4) FOR(j,i+1,4) { string direct=s[0]; swap(direct[pos[i]],direct[pos[j]]); if(test(direct)) { printf("%s\n",direct.c_str()); return; } }
	}
	printf("-1\n");
}

int main() {
	run();
	return 0;
}
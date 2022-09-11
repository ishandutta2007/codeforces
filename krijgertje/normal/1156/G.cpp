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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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

const int MAXLINE=1000;
const int MAXLINELEN=4+1+4+1+4+1;
struct Node { int a; char op; int b; Node() {} Node(int a,char op,int b):a(a),op(op),b(b) {} };
bool operator==(const Node &p,const Node &q) { return p.a==q.a&&p.op==q.op&&p.b==q.b; }

int nline;
char line[MAXLINE][MAXLINELEN+1];
int nans;
char ans[MAXLINE][MAXLINELEN+1];

vector<string> names;
map<string,int> mp;
int lhs[MAXLINE],lpar[MAXLINE]; char op[MAXLINE]; int rpar[MAXLINE];

vector<Node> vars;
vector<int> curvar;
vector<bool> valid;
vector<bool> used;
vector<string> newnames;

int lookup(string s) { auto it=mp.find(s); if(it!=mp.end()) return it->second; int ret=SZ(names); names.PB(s); mp[s]=ret; return ret; }

void printvar(int idx) {
	if(vars[idx].op=='=') printf("%s",names[vars[idx].a].c_str()); else { printf("("); printvar(vars[idx].a); printf("%c",vars[idx].op); printvar(vars[idx].b); printf(")"); }
}

void solve() {
	names.clear(); mp.clear();
	int resname=lookup("res");

	REP(i,nline) {
		int eqidx=-1,opidx=-1,linelen=strlen(line[i]);
		REP(j,linelen) if(line[i][j]=='=') { assert(eqidx==-1); eqidx=j; } else if(line[i][j]=='$'||line[i][j]=='^'||line[i][j]=='#'||line[i][j]=='&') { assert(opidx==-1); opidx=j; } assert(eqidx!=-1);
		if(opidx==-1) {
			string a=string(line[i]+0,line[i]+eqidx),b=string(line[i]+eqidx+1,line[i]+linelen);
			lhs[i]=lookup(a); lpar[i]=lookup(b); op[i]='=';
		} else {
			string a=string(line[i]+0,line[i]+eqidx),b=string(line[i]+eqidx+1,line[i]+opidx),c=string(line[i]+opidx+1,line[i]+linelen);
			lhs[i]=lookup(a); lpar[i]=lookup(b); op[i]=line[i][opidx]; rpar[i]=lookup(c);
		}
	}

	vars.clear();
	REPSZ(i,names) vars.PB(Node(i,'=',-1));
	curvar=vector<int>(SZ(names)); REPSZ(i,curvar) curvar[i]=i;
	REP(i,nline) {
		if(op[i]=='=') {
			curvar[lhs[i]]=curvar[lpar[i]];
		} else {
			int id=SZ(vars);
			vars.PB(Node(curvar[lpar[i]],op[i],curvar[rpar[i]]));
			curvar[lhs[i]]=id;
		}
	}

	int resvar=curvar[resname];
	//printvar(resvar); puts("");

	valid=vector<bool>(SZ(vars),true);
	REPSZ(i,vars) if(valid[i]) {
		FORSZ(j,i+1,vars) if(valid[j]&&vars[j]==vars[i]) {
			valid[j]=false;
			if(resvar==j) resvar=i;
			FORSZ(k,j+1,vars) {
				if(vars[k].a==j) vars[k].a=i;
				if(vars[k].b==j) vars[k].b=i;
			}
		}
	}
	used=vector<bool>(SZ(vars),false); queue<int> q;
	used[resvar]=true; q.push(resvar);
	while(!q.empty()) { int at=q.front(); q.pop(); if(vars[at].op=='=') continue; if(!used[vars[at].a]) used[vars[at].a]=true,q.push(vars[at].a); if(!used[vars[at].b]) used[vars[at].b]=true,q.push(vars[at].b); }

	//printf("valid: "); REPSZ(i,valid) printf("%c",valid[i]?'v':'.'); puts("");
	//printf("used: "); REPSZ(i,used) printf("%c",used[i]?'v':'.'); puts("");
	//REPSZ(i,vars) if(valid[i]&&used[i]) { printf("%d: %d %c %d\n",i,vars[i].a,vars[i].op,vars[i].b); }
	//printf("resvar: %d\n",resvar);

	newnames=vector<string>(SZ(vars)); int nxtnewname=0; 
	set<string> reservednames;
	reservednames.insert("res");
	if(vars[resvar].op!='=') newnames[resvar]="res";
	REPSZ(i,vars) if(valid[i]&&used[i]&&vars[i].op=='=') newnames[i]=names[vars[i].a],reservednames.insert(newnames[i]);
	REPSZ(i,vars) if(valid[i]&&used[i]&&i!=resvar&&vars[i].op!='=') while(true) { 
		int a=nxtnewname/26/27,b=nxtnewname/26%27,c=nxtnewname%26; ++nxtnewname; 
		string name; if(a!=0) name+=string(1,'a'+a-1); if(b!=0) name+=string(1,'a'+b-1); name+=string(1,'a'+c); 
		if(reservednames.count(name)) continue;
		newnames[i]=name; break;
	}
	nans=0;
	REPSZ(i,vars) if(valid[i]&&used[i]&&vars[i].op!='=') {
		string cur=newnames[i]+'='+newnames[vars[i].a]+vars[i].op+newnames[vars[i].b];
		sprintf(ans[nans++],"%s",cur.c_str());
	}
	if(vars[resvar].op=='='&&newnames[vars[resvar].a]!="res") {
		string cur="res="+newnames[vars[resvar].a];
		sprintf(ans[nans++],"%s",cur.c_str());
	}
}

void run() {
	scanf("%d",&nline);
	REP(i,nline) scanf("%s",line[i]);
	solve();
	printf("%d\n",nans);
	REP(i,nans) printf("%s\n",ans[i]);
}

int main() {
	run();
	return 0;
}
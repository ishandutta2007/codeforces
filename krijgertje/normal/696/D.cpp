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

const int MAXN=200;
const int MAXSUMLEN=200;
const int MAXSTATE=MAXSUMLEN+1;
typedef ll Mat[MAXSTATE][MAXSTATE];

int nid;
void mmult(Mat &A,Mat &B) {
	Mat C;
	REP(i,nid) REP(j,nid) { ll cur=-1; REP(k,nid) if(A[i][k]!=-1&&B[k][j]!=-1) { ll now=A[i][k]+B[k][j]; if(now>cur) cur=now; } C[i][j]=cur; }
	REP(i,nid) REP(j,nid) A[i][j]=C[i][j];
}
void mpow(Mat &A,ll k) {
	Mat B; REP(i,nid) REP(j,nid) B[i][j]=A[i][j],A[i][j]=i==j?0:-1;
	while(k>0) {
		if(k&1) mmult(A,B);
		if((k>>=1)==0) break;
		mmult(B,B);
	}
}

int n; ll steps;

Mat A,B;
int gain[MAXN];
char s[MAXN][MAXSUMLEN+1];
int slen[MAXN];

map<string,pair<int,int> > mp;

void run() {
	scanf("%d%lld",&n,&steps);
	REP(i,n) scanf("%d",&gain[i]);
	REP(i,n) scanf("%s",s[i]),slen[i]=strlen(s[i]);

	memset(A,-1,sizeof(A));
	mp.clear(); nid=0;
	REP(i,n) REPE(j,slen[i]) {
		string cur=string(s[i]).substr(0,j);
		if(!mp.count(cur)) mp[cur]=MP(nid++,0);
		if(j==slen[i]) mp[cur].second+=gain[i];
	}
	//for(map<string,pair<int,int> >::iterator it=mp.begin();it!=mp.end();++it) printf("%d='%s' (%d)\n",it->second.first,it->first.c_str(),it->second.second);
	vector<pair<int,string> > p; for(map<string,pair<int,int> >::iterator it=mp.begin();it!=mp.end();++it) p.PB(MP(SZ(it->first),it->first)); sort(p.begin(),p.end());
	REPSZ(i,p) if(p[i].first>0) { string cur=p[i].second.substr(1); while(!mp.count(cur)) cur=cur.substr(1); mp[p[i].second].second+=mp[cur].second; }
	for(map<string,pair<int,int> >::iterator it=mp.begin();it!=mp.end();++it) for(char c='a';c<='z';++c) {
		string cur=it->first+c;
		while(!mp.count(cur)) cur=cur.substr(1);
		A[it->second.first][mp[cur].first]=mp[cur].second;
	}
	//REP(i,nid) { REP(j,nid) printf("%3d ",A[i][j]); puts(""); } puts("");
	//REPE(x,steps) { REP(i,nid) REP(j,nid) B[i][j]=A[i][j]; mpow(B,x); printf("%d:",x); REP(j,nid) printf("%3d ",B[0][j]); puts(""); }
	mpow(A,steps);
	ll ret=0; REP(j,nid) if(A[0][j]>ret) ret=A[0][j]; printf("%lld\n",ret);
	//REP(i,nid) { REP(j,nid) printf("%3d ",A[i][j]); puts(""); } puts("");
}

int main() {
	run();
	return 0;
}
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

const int MAXN=100000;

int n;

vector<pair<int,int>> diff;
vector<pair<int,int>> same;
int single;
int match[MAXN];
vector<int> identical;

vector<vector<vector<int>>> res;
int col[MAXN];

string query(vector<pair<int,int>> pairs) {
	if(SZ(pairs)==0) return "";
	printf("Q %d",SZ(pairs)); REPSZ(i,pairs) printf(" %d %d",pairs[i].first+1,pairs[i].second+1); puts(""); fflush(stdout);
	string ret; cin>>ret; if(ret=="-1") exit(0); return ret;
}

void solve() {
	diff.clear(); same.clear(); single=-1; identical.clear(); REP(i,n) match[i]=col[i]=-1;
	vector<pair<int,int>> qfst; REP(i,n) if(i%2==0) if(i+1<n) qfst.PB(MP(i,i+1)); else { assert(single==-1); single=i; }
	string ansfst=query(qfst);
	REPSZ(i,qfst) if(ansfst[i]=='1') same.PB(qfst[i]); else diff.PB(qfst[i]);
	
	vector<pair<int,int>> qsnd; REPSZ(i,same) if(i+1<SZ(same)) qsnd.PB(MP(same[i].second,same[i+1].first)); else if(single!=-1) qsnd.PB(MP(same[i].second,single));
	string anssnd=query(qsnd);
	bool sndsame=true;
	REPSZ(i,anssnd) if(anssnd[i]=='0') {
		diff.PB(qsnd[i]);
		FORSZ(j,i+1,same) {
			if(j<SZ(anssnd)&&anssnd[j]=='0') break;
			match[same[j].second]=qsnd[i].second;
			if(j+1<SZ(same)) match[same[j+1].first]=qsnd[i].second; else if(single!=-1) match[single]=qsnd[i].second;
		}
		if(sndsame) {
			sndsame=false;
			match[same[i].first]=qsnd[i].first;
			for(int j=i-1;j>=0;--j) match[same[j].first]=match[same[j].second]=qsnd[i].first;
		}
	}
	if(sndsame) { REPSZ(i,same) identical.PB(same[i].first),identical.PB(same[i].second); if(single!=-1) identical.PB(single); }

	//printf("diff:"); REPSZ(i,diff) printf(" (%d,%d)",diff[i].first+1,diff[i].second+1); puts("");
	//printf("match:"); REP(i,n) printf(" %d",match[i]+1); puts("");
	//printf("identical:"); REPSZ(i,identical) printf(" %d",identical[i]+1); puts("");

	if(SZ(diff)==0) { REP(i,n) col[i]=0; return; }
	res=vector<vector<vector<int>>>(SZ(diff)-1,vector<vector<int>>(2,vector<int>(2,-1)));
	{ 
		vector<pair<int,int>> q; FORSZ(i,1,diff) if(i%2==1) q.PB(MP(diff[i-1].first,diff[i].first)); else q.PB(MP(diff[i-1].second,diff[i].second)); 
		string ans=query(q); FORSZ(i,1,diff) if(i%2==1) res[i-1][0][0]=ans[i-1]=='1'; else res[i-1][1][1]=ans[i-1]=='1';
	}
	{
		vector<pair<int,int>> q; FORSZ(i,1,diff) if(i%2==1) q.PB(MP(diff[i-1].second,diff[i].second)); else q.PB(MP(diff[i-1].first,diff[i].first));
		string ans=query(q); FORSZ(i,1,diff) if(i%2==1) res[i-1][1][1]=ans[i-1]=='1'; else res[i-1][0][0]=ans[i-1]=='1';
	}
	{
		vector<pair<int,int>> q; FORSZ(i,1,diff) q.PB(MP(diff[i-1].first,diff[i].second));
		string ans=query(q); FORSZ(i,1,diff) res[i-1][0][1]=ans[i-1]=='1';
	}
	{
		vector<pair<int,int>> q; FORSZ(i,1,diff) q.PB(MP(diff[i-1].second,diff[i].first));
		string ans=query(q); FORSZ(i,1,diff) res[i-1][1][0]=ans[i-1]=='1';
	}
	
	col[diff[0].first]=0,col[diff[0].second]=1;
	FORSZ(i,1,diff) {
		if(res[i-1][0][0]==1) col[diff[i].first]=col[diff[i-1].first]; else if(res[i-1][1][0]==1) col[diff[i].first]=col[diff[i-1].second]; else col[diff[i].first]=3-col[diff[i-1].first]-col[diff[i-1].second];
		if(res[i-1][0][1]==1) col[diff[i].second]=col[diff[i-1].first]; else if(res[i-1][1][1]==1) col[diff[i].second]=col[diff[i-1].second]; else col[diff[i].second]=3-col[diff[i-1].first]-col[diff[i-1].second];
	}
	REP(i,n) if(match[i]!=-1) { assert(col[i]==-1&&col[match[i]]!=-1); col[i]=col[match[i]]; }

	if(SZ(identical)==1) {
		vector<pair<int,int>> q1; q1.PB(MP(diff[0].first,identical[0])); string ans1=query(q1);
		vector<pair<int,int>> q2; q2.PB(MP(diff[0].second,identical[0])); string ans2=query(q2);
		if(ans1[0]=='1') col[identical[0]]=col[diff[0].first]; else if(ans2[0]=='1') col[identical[0]]=col[diff[0].second]; else col[identical[0]]=3-col[diff[0].first]-col[diff[0].second];
	}
	if(SZ(identical)>=2) {
		vector<pair<int,int>> q; q.PB(MP(diff[0].first,identical[0])); q.PB(MP(diff[0].second,identical[1])); string ans=query(q);
		int c=-1; if(ans[0]=='1') c=col[diff[0].first]; else if(ans[1]=='1') c=col[diff[0].second]; else c=3-col[diff[0].first]-col[diff[0].second];
		REPSZ(i,identical) col[identical[i]]=c;
	}

	//printf("res:"); REPSZ(i,res) { printf(" "); REP(j,2) REP(k,2) printf("%d",res[i][j][k]); } puts("");
	//printf("col:"); REP(i,n) printf(" %d",col[i]+1); puts("");
}

void run() {
	scanf("%d",&n); if(n==-1) exit(0);
	solve();
	REP(i,n) assert(col[i]!=-1);
	vector<int> cnt(3); REP(i,n) ++cnt[col[i]];
	printf("A"); REP(i,3) printf(" %d",cnt[i]); puts(""); REP(i,3) { bool fst=true; REP(j,n) if(col[j]==i) { if(fst) fst=false; else printf(" "); printf("%d",j+1); } puts(""); } fflush(stdout);
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}
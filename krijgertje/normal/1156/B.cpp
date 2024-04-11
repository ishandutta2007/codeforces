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

const int MAXLEN=100;

char s[MAXLEN+1]; int slen;
char ans[MAXLEN+1]; int anslen;

int cnt[26];

bool solve() {
	REP(i,26) cnt[i]=0; REP(i,slen) ++cnt[s[i]-'a'];
	vector<pair<vector<int>,vector<int>>> chains;
	for(int l=0,r=l;l<26;l=r) {
		while(r<26&&(cnt[r]>0)==(cnt[l]>0)) ++r;
		if(cnt[l]==0) continue;
		vector<int> evn,odd; REP(i,r-l) if(i%2==0) evn.PB(l+i); else odd.PB(l+i);
		reverse(evn.begin(),evn.end()); reverse(odd.begin(),odd.end());
		chains.PB(MP(evn,odd));
	}
	assert(SZ(chains)>0);
	REPSZ(i,chains) if(SZ(chains[0].second)==0&&SZ(chains[i].second)>0) swap(chains[0],chains[i]);
	vector<int> order;
	REPSZ(i,chains) REPSZ(j,chains[i].first) order.PB(chains[i].first[j]);
	REPSZ(i,chains) REPSZ(j,chains[i].second) order.PB(chains[i].second[j]);
	FORSZ(i,1,order) if(abs(order[i-1]-order[i])==1) return false;
	anslen=0; REPSZ(i,order) REP(j,cnt[order[i]]) ans[anslen++]='a'+order[i]; ans[anslen]='\0';
	return true;
}

void run() {
	scanf("%s",s); slen=strlen(s);
	if(!solve()) { printf("No answer\n"); return; }
	printf("%s\n",ans);
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}
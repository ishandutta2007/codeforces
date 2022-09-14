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

const int MOD=51123987;
char s[4000002];

int bf(vector<pair<int,int> > x) {
	vector<pair<int,int> > y;
	REPSZ(i,x) {
		for(int l=x[i].first,r=x[i].second;l<=r;++l,--r) y.PB(MP(l,r));
	}
	int ret=0;
	REPSZ(i,y) FORSZ(j,i+1,y) {
		if(y[i].second<y[j].first||y[j].second<y[i].first) continue;
		++ret;
	}
	return ret;
}

void run() {
	int n; scanf("%d",&n);
	int nchars=0;
	s[nchars++]='$'; REP(i,n) { if(i!=0) s[nchars++]='*'; scanf(" %c",&s[nchars++]); } s[nchars++]='#'; s[nchars]='\0';
//	printf("%s\n",s);	

	vector<int> size(nchars,0);
	pair<int,int> rightmostrange=MP(-1,-1);
	FOR(i,1,nchars-1) {
		size[i]=0;
		if(rightmostrange.second>=i) size[i]=min(rightmostrange.second-i+1,size[rightmostrange.first+(rightmostrange.second-i)]);
		while(s[i-size[i]]==s[i+size[i]]) ++size[i];
		if(i+size[i]>rightmostrange.second) rightmostrange=MP(i-(size[i]-1),i+(size[i]-1));
	}
//	FOR(i,1,nchars-1) printf("%d: %d\n",i,size[i]);

	vector<pair<int,int> > palins;
	FOR(i,1,nchars-1) {
		if(s[i-(size[i]-1)]=='*'||s[i+(size[i]-1)]=='*') --size[i];
		if(size[i]==0) continue;
		palins.PB(MP((i-(size[i]-1)-1)/2,(i+(size[i]-1)-1)/2));
	}
//	REPSZ(i,palins) printf("(%d,%d)\n",palins[i].first,palins[i].second);
	
	vector<int> deltastart(n+1,0),deltaend(n+1,0);
	REPSZ(i,palins) {
		int a=palins[i].first,b=palins[i].second,len=b-a+1;
		if(len%2==0) {
			deltastart[a]++; deltastart[a+len/2]--;
			deltaend[a+len/2]++; deltaend[b+1]--;
		} else {
			deltastart[a]++; deltastart[a+(len+1)/2]--;
			deltaend[a+(len-1)/2]++; deltaend[b+1]--;
		}
	}
//	REPE(i,n) printf("%2d ",deltastart[i]); puts("");
//	REPE(i,n) printf("%2d ",deltaend[i]); puts("");
	ll ret=0;
	ll cur=0,nstart=0,nend=0;
	REPE(i,n) {
		nstart+=deltastart[i];
		ll tmp=nstart%MOD;
		ret=(ret+tmp*(tmp-1)/2)%MOD;
		ret=(ret+cur%MOD*tmp)%MOD;
		cur+=nstart;
		nend+=deltaend[i];
		cur-=nend;
	}
	printf("%d\n",(int)ret);
//	fprintf(stderr,"%lld %lld %lld\n",cur,nstart,nend);
//	int check=bf(palins); printf("have %d, need %d\n",(int)ret,check);
}

int main() {
	run();
	return 0;
}
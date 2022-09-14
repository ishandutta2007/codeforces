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

int alen;
char a[1000];
int blen;
char b[1000];

int np;
int plen[1000];
char p[1000][1000];


void addp() {
	int c=0;
	int at=0;
	for(;c!=0||at<plen[np-1]||at-1<plen[np-1];++at) {
		if(0<=at-1&&at-1<plen[np-1]) c+=p[np-1][at-1]-'0';
		if(at<plen[np-1]) c+=2*(p[np-1][at]-'0');
		p[np][at]='0'+c%10; c/=10;
	}
	p[np][at]='\0'; plen[np]=at; ++np;
//	printf("added %d: %s\n",np-1,p[np-1]);
}

void add(int i,int j) {
	while(i>=np||j>=np) addp();
	int at=0,c=0;
	for(;c!=0||at<plen[i]||at<plen[j];++at) {
		if(at<plen[i]) c+=p[i][at]-'0';
		if(at<plen[j]) c+=p[j][at]-'0';
		b[at]='0'+c%10; c/=10;
	}
	b[at]='\0'; blen=at;
}

bool check(int i,int j) {
	add(i,j);
//	printf("%s vs %s\n",a,b);
	if(alen!=blen) return false;
	REP(i,alen) if(a[i]!=b[i]) return false;
	return true;
}

void output(int i,int j) {
	add(i,j);
	reverse(b,b+blen);
	printf("%s",b);
}

void run() {
	scanf("%s",a); alen=strlen(a); reverse(a,a+alen);
	p[0][0]='1'; p[0][1]='\0'; plen[0]=1; np=1;
	while(plen[np-1]<alen) addp();

	set<pair<int,int> > skip;
	vector<int> when;
	REP(i,np) FOR(j,i,np) if(check(i,j)) { when.PB(i+j); skip.insert(MP(i,j)); }
	sort(when.begin(),when.end()); when.erase(unique(when.begin(),when.end()),when.end());
	
	if(SZ(when)==0) { printf("NO\n"); return; }
	printf("%s\n","YES");
	printf("%d\n",min(1000,SZ(when)));	
	REPE(i,min(1000,SZ(when)-1)) {
		printf("%d\n",when[i]+1);
	}
	int cnt=0;
	for(int i=0;i<=when.back();++i) {
		int at=0;
		for(int j=0;j<=i;++j) {
			while(at<SZ(when)&&i+j>when[at]) ++at;
			if(at<SZ(when)&&i+j==when[at]&&!skip.count(MP(j,i))) {
				++cnt;
			}
		}
	}
	cnt=min(cnt,1000);
	printf("%d\n",cnt);
	for(int i=0;i<=when.back();++i) {
		int at=0;
		for(int j=0;j<=i;++j) {
			while(at<SZ(when)&&i+j>when[at]) ++at;
			if(at<SZ(when)&&i+j==when[at]&&cnt>0&&!skip.count(MP(j,i))) {
				--cnt;
				output(i,j); puts("");
			}
		}
	}
}


int main() {
//	freopen ("input.txt","r",stdin);
//	freopen ("output.txt","w",stdout);
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;  

#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  

const int MAXN=100;
const int MAXLEN=1000;

int n;
char s[MAXLEN+1]; int slen;

int cnt1[26];
int cnt2[26][26];


void run() {
	memset(cnt1,0,sizeof(cnt1));
	memset(cnt2,0,sizeof(cnt2));
	scanf("%d",&n);
	REP(i,n) {
		scanf("%s",s); slen=strlen(s); int oslen=slen;
		sort(s,s+slen); slen=unique(s,s+slen)-s;
		if(slen==1) cnt1[s[0]-'a']+=oslen;
		if(slen==2) cnt2[s[0]-'a'][s[1]-'a']+=oslen;
	}
	int ret=0;
	REP(i,26) FOR(j,i+1,26) { int cur=cnt1[i]+cnt1[j]+cnt2[i][j]; if(cur>ret) ret=cur; }
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
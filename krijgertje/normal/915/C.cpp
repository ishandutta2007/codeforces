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

const int MAXLEN=18;

char a[MAXLEN+1]; int alen;
char b[MAXLEN+1]; int blen;
char c[MAXLEN+1]; int clen;

int cnt[10];

void run() {
	scanf("%s%s",a,b); alen=strlen(a); blen=strlen(b);
	if(alen<blen) {
		REP(i,alen) c[i]=a[i]; clen=alen; c[clen]='\0'; sort(c,c+clen); reverse(c,c+clen);
	} else {
		assert(alen==blen);
		for(int neq=blen;neq>=0;--neq) {
			REP(i,10) cnt[i]=0; REP(i,alen) ++cnt[a[i]-'0'];
			clen=0; bool ok=true; REP(i,neq) { int x=b[i]-'0'; if(cnt[x]==0) { ok=false; break; } else --cnt[x],c[clen++]='0'+x; } if(!ok) continue;
			if(neq<blen) {
				int y=b[neq]-'0'-1;
				while(y>=0&&cnt[y]==0) --y; if(y<0) continue;
				--cnt[y],c[clen++]='0'+y;
			}
			for(int i=9;i>=0;--i) while(cnt[i]>0) { --cnt[i],c[clen++]='0'+i; }
			c[clen]='\0'; break;
		}
	}
	printf("%s\n",c);
}

int main() {
	run();
	return 0;
}
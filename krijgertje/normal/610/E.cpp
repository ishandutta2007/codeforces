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

const int MAXN=200000;
const int MAXQ=20000;
const int MAXALPH=10;


int n,nq,k;
char s[MAXN+1];
char p[MAXALPH+1];

map<int,char> x;
int cnt[MAXALPH][MAXALPH];

void run() {
	scanf("%d%d%d%s",&n,&nq,&k,s);
	
	x.clear(); memset(cnt,0,sizeof(cnt));
	x.insert(MP(0,'x')); REP(i,n) x.insert(MP(i+1,s[i])); x.insert(MP(n+1,'x'));
	FOR(i,1,n) ++cnt[s[i-1]-'a'][s[i]-'a'];

	//for(map<int,char>::iterator z=x.begin();z!=x.end();++z) printf("%d%c ",z->first,z->second); puts("");
	//REP(ii,k) REP(jj,k) if(cnt[ii][jj]!=0) printf("%c%c=%d ",'a'+ii,'a'+jj,cnt[ii][jj]); puts("");

	REP(qi,nq) {
		int type; scanf("%d",&type);
		if(type==1) {
			int l,r; char c; scanf("%d%d %c",&l,&r,&c);
			map<int,char>::iterator i=x.lower_bound(l); if(i->first>=l) --i;
			if(i->second!='x') ++cnt[i->second-'a'][c-'a'];
			cnt[c-'a'][c-'a']+=r-l;
			map<int,char>::iterator j=i; ++j;
			while(true) {
				//printf("\t%d%c %d%c\n",i->first,i->second,j->first,j->second);
				if(j->first==r+1) {
					cnt[i->second-'a'][i->second-'a']-=r-max(l-1,i->first);
					if(j->second!='x') --cnt[i->second-'a'][j->second-'a'],++cnt[c-'a'][j->second-'a'];
					if(i->first>=l) x.erase(i);
					break;
				} else if(j->first>r+1) {
					cnt[i->second-'a'][i->second-'a']-=r-max(l-1,i->first);
					--cnt[i->second-'a'][i->second-'a'],++cnt[c-'a'][i->second-'a'];
					char cc=i->second; if(i->first>=l) x.erase(i); x.insert(MP(r+1,cc));
					break;
				} else {
					if(i->second!='x') cnt[i->second-'a'][i->second-'a']-=j->first-1-max(l-1,i->first);
					if(i->second!='x') --cnt[i->second-'a'][j->second-'a'];
					if(i->first>=l) x.erase(i);
				}
				i=j++;
			}
			x.insert(MP(l,c));
			//for(map<int,char>::iterator z=x.begin();z!=x.end();++z) printf("%d%c ",z->first,z->second); puts("");
			//REP(ii,k) REP(jj,k) if(cnt[ii][jj]>0) printf("%c%c=%d ",'a'+ii,'a'+jj,cnt[ii][jj]); puts("");
		}
		if(type==2) {
			scanf("%s",p);
			int ret=1; REP(i,k) REPE(j,i) ret+=cnt[p[i]-'a'][p[j]-'a'];
			printf("%d\n",ret);
		}
	}


}

int main() {
	run();
	return 0;
}
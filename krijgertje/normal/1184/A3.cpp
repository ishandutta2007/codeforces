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
const int MAXP=2000000;

int pw(int x,int n,int mod) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%mod; if((n>>=1)==0) return ret; x=(ll)x*x%mod; } }

int n,modlim;
char sa[MAXN+1];
char sb[MAXN+1];


bool isp[MAXP+1];

vector<int> getpol(int d) { vector<int> pol(d,0); REP(i,n) pol[i%d]+=((int)sa[i])-((int)sb[i]); return pol; }
int eval(const vector<int> &pol,int r,int mod) { int ret=0,x=1; REPSZ(i,pol) { ret=(ret+(ll)pol[i]*x)%mod; x=(ll)x*r%mod; } if(ret<0) ret+=mod; return ret; }

pair<int,int> solve() {
	REPE(i,MAXP) isp[i]=true; isp[0]=isp[1]=false; FORE(i,2,MAXP) if(isp[i]) for(int j=i+i;j<=MAXP;j+=i) isp[j]=false;

	int cnt=0;
	REPE(d,MAXP) if(d%2==1&&isp[d]) {
		//printf("d=%d\n",d);
		vector<int> pol=getpol(d);
		//printf("pol:"); REP(i,d) printf(" %d",pol[i]); puts("");

		for(int p=1;p<=MAXP;p+=d) if(isp[p]&&p>=modlim) {
			int r=-1;
			FORE(i,2,p-2) { int cur=pw(i,(p-1)/d,p); if(cur!=1) { r=cur; break; } }
			assert(r!=-1);
			REP(i,d) {
				int x=pw(r,i,p); if(x<2||x>p-2) continue;
				assert(pw(x,d,p)==1);
				++cnt;
				if(eval(pol,x,p)==0) {
					//printf("cnt=%d\n",cnt);
					return MP(x,p);
				}
			}
		}
	}
	assert(false); return MP(-1,-1);
}

void run() {
	scanf("%d%d",&n,&modlim);
	scanf("%s",&sa); assert(strlen(sa)==n);
	scanf("%s",&sb); assert(strlen(sb)==n);
	//printf("%d\n",eval(getpol(n),2,5));
	//printf("%d\n",eval(getpol(n),2,3));
	//printf("%d\n",eval(getpol(n),79724,118219));
	pair<int,int> ans=solve();
	printf("%d %d\n",ans.second,ans.first);
}

int main() {
	run();
	return 0;
}
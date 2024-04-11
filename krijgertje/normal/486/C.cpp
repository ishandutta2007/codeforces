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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int n,start;
char s[100001];
bool isud[100000];

bool contains(int a,int b,int c) { if(a<=b) return a<=c&&c<=b; else return c<=b||a<=c; }
int count(int a,int b) { if(a<=b) return b-a; else return b+n-a; }

void run() {
	scanf("%d%d",&n,&start); --start;
	scanf("%s",s);
	memset(isud,false,sizeof(isud));
	int cntud=0,sumud=0; REP(i,n/2) { int a=s[i]-'a',b=s[n-1-i]-'a'; if(a==b) continue; if(a>b) swap(a,b); int cur=min(b-a,a+26-b); ++cntud,sumud+=cur; isud[i]=isud[n-1-i]=true; }
	int ret=INT_MAX;
	// go left, then right
	{
		int l=start,r=start,haveud=isud[start]?1:0;
		while(haveud<cntud) {
			int nr=r+1; if(nr>=n) nr=0;
			if(isud[nr]&&!contains(start,r,n-1-nr)) ++haveud;
			r=nr;
		}
		while(true) {
			int cur=count(l,start)+(r!=start?count(l,r):0)+sumud; if(cur<ret) ret=cur;
//			printf("LR %d %d: %d\n",l,r,cur);
			if(--l<0) l=n-1; if(l==start) break;
			while(r!=start) {
				int nr=r-1; if(nr<0) nr=n-1;
				if(isud[r]&&!contains(l,start,r)&&!contains(l,start,n-1-r)&&!contains(start,nr,r)&&!contains(start,nr,n-1-r)) break;
				r=nr;
			}
		}
	}
	// go right, then left
	{
		int l=start,r=start,haveud=isud[start]?1:0;
		while(haveud<cntud) {
			int nl=l-1; if(nl<0) nl=n-1;
			if(isud[nl]&&!contains(l,start,n-1-nl)) ++haveud;
			l=nl;
		}
		while(true) {
			int cur=count(start,r)+(l!=start?count(l,r):0)+sumud; if(cur<ret) ret=cur;
//			printf("RL %d %d: %d\n",r,l,cur);
			if(++r>=n) r=0; if(r==start) break;
			while(l!=start) {
				int nl=l+1; if(nl>=n) nl=0;
				if(isud[l]&&!contains(start,r,l)&&!contains(start,r,n-1-l)&&!contains(nl,start,l)&&!contains(nl,start,n-1-l)) break;
				l=nl;
			}
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
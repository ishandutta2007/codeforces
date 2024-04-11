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

const int MAXN=1000000;

int n,nq;
int a[2*MAXN];

int fst[MAXN],cnt[MAXN],cur; ll sz[MAXN];

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) a[n+i]=a[i];
	REP(qi,nq) {
		ll cap; cin>>cap;
		int l=-1,r=-1;
		{
			int start=0,end=1; ll sum=a[start];
			while(true) {
				while(end<n&&sum+a[end]<=cap) sum+=a[end++];
				if(end>=n) break;
				if(l==-1||r==-1||end-start<=r-l) l=start,r=end;
				start=end,end=start+1,sum=a[start];
			}
		}
		if(l==-1||r==-1) { printf("%d\n",1); continue; }
		{
			cur=0; int at=l;
			while(at<n+l) {
				if(cur>0&&sz[cur-1]+a[at]<=cap) ++cnt[cur-1],sz[cur-1]+=a[at]; else fst[cur]=at,cnt[cur]=1,sz[cur]=a[at],++cur;
				++at;
			}
		}
		int ret=cur;
		while(fst[0]<r) {
			int at=n+fst[0];
			sz[0]-=a[fst[0]]; fst[0]++; cnt[0]--;
			REP(i,cur-1) while(cnt[i+1]>0&&sz[i]+a[fst[i+1]]<=cap) sz[i]+=a[fst[i+1]],sz[i+1]-=a[fst[i+1]],++cnt[i],--cnt[i+1],++fst[i+1];
			while(cur>0&&cnt[cur-1]==0) --cur;
			if(cur>0&&sz[cur-1]+a[at]<=cap) ++cnt[cur-1],sz[cur-1]+=a[at]; else fst[cur]=at,cnt[cur]=1,sz[cur]=a[at],++cur;
			if(cur<ret) ret=cur;
		}
		printf("%d\n",ret);
	}

}

int main() {
	run();
	return 0;
}
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

const int MAXN=500000;
typedef struct QueueMin {
	set<pair<int,int> > x;
	void init() {
		x.clear();
	}
	void push(int idx,int val) {
		x.insert(MP(val,idx));
	}
	void pop(int idx,int val) {
		x.erase(MP(val,idx));
	}
	int count() {
		return SZ(x);
	}
	int val() {
		if(SZ(x)==0) return INT_MAX; return x.begin()->first;
	}
	int idx() {
		assert(SZ(x)!=0); return x.begin()->second;
	}
	int val2() {
		if(SZ(x)<=1) return INT_MAX; auto it=x.begin(); ++it; return it->first;
	}
} QueueMin;

int n,len;
int val[MAXN];
int lim[MAXN];
vector<pair<int,int> > opt;

QueueMin qm;

bool solve() {
	int l=0,r=0,a=-1; qm.init();
	REP(i,n) {
		while(r<n&&r<=i+len) qm.push(r,val[r]),++r;
		while(l<=i) qm.pop(l,val[l]),++l;
		if(qm.count()==len&&qm.val()>=val[i]) { a=i; break; }
	}
	if(a==-1) return true;
	//printf("a=%d\n",a);
	FOR(i,a+len+1,n) lim[i]=INT_MAX;
	FOR(i,a+len+1,n) {
		while(r<n&&r<=i+len) qm.push(r,val[r]),++r;
		while(l<=i) qm.pop(l,val[l]),++l;
		if(qm.count()==len) {
			if(qm.val()>=val[i]) return false;
			if(qm.val2()>=val[i]) {
				int idx=qm.idx();
				lim[idx]=min(lim[idx],val[i]-1);
			}
		}
	}
	opt.clear();
	FOR(i,a+len+1,n) if(val[i]<val[a]&&lim[i]>=val[a]) opt.PB(MP(val[i],lim[i]));
	sort(opt.begin(),opt.end());
	{ int nsz=0; REPSZ(i,opt) { while(nsz!=0&&opt[i].second>=opt[nsz-1].second) --nsz; opt[nsz++]=opt[i]; } while(SZ(opt)>nsz) opt.pop_back(); }
	int mn=INT_MAX,at=SZ(opt);
	FORE(i,a+1,a+len) {
		int cur=i+len<n?val[i+len]:0; mn=min(mn,cur);
		while(at-1>=0&&opt[at-1].first>mn) --at;
		if(at<SZ(opt)&&val[i]<=opt[at].second) return true;
	}
	return false;
}

void run() {
	scanf("%d%d",&n,&len);
	REP(i,n) scanf("%d",&val[i]);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}
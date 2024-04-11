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

const int MAXN=200000;

int n;
int a[MAXN];

int cur[MAXN],endd[MAXN]; // startidx
int start[MAXN]; // endidx
bool isstart[MAXN];

priority_queue<pair<int,int>> pq; // (-cur,-startidx)

bool solve() {
	REP(i,n) cur[i]=a[i],endd[i]=i,start[i]=i,isstart[i]=true;
	pq=priority_queue<pair<int,int>>();
	REP(i,n) if(isstart[i]) pq.push(MP(-cur[i],-i));
	while(!pq.empty()) {
		int idx=-pq.top().second,expect=-pq.top().first; pq.pop();
		if(!isstart[idx]||cur[idx]!=expect) continue;
		if(idx==0&&endd[idx]==n-1) continue;
		if(idx!=0&&(endd[idx]==n-1||cur[start[idx-1]]<=cur[endd[idx]+1])) {
			int nidx=start[idx-1];
			if(cur[nidx]!=cur[idx]) {
				int len=endd[idx]-idx+1; if(len%2!=0) return false;
			}
			isstart[idx]=false; start[endd[idx]]=nidx; endd[nidx]=endd[idx];
		} else {
			int nidx=endd[idx]+1;
			if(cur[nidx]!=cur[idx]) {
				int len=endd[idx]-idx+1; if(len%2!=0) return false;
			}
			isstart[nidx]=false; start[endd[nidx]]=idx; endd[idx]=endd[nidx]; cur[idx]=cur[nidx];
			pq.push(MP(-cur[idx],-idx));
		}
	}
	return true;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}
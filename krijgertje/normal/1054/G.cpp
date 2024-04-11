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

const int MAXN=2000;
const int MAXGROUP=2000;

int n,ngroup;
char group[MAXGROUP][MAXN+1];
vector<pair<int,int>> ans;

int groupremcnt[MAXGROUP]; // groupremcnt[i] = the number of remaining people that are in group i
int extra[MAXN][MAXN]; // extra[i][j] = the number of alive groups that i is in, but j isn't

bitset<MAXGROUP> bs[MAXN];
int cnt[MAXN]; // cnt[i] = the number of groups the i the person is in

queue<pair<int,int>> q;
bool done[MAXN];
int ufpar[MAXN],ufsz[MAXN];

int uffind(int a) { if(ufpar[a]==a) return a; return ufpar[a]=uffind(ufpar[a]); }
void ufunite(int a,int b) { a=uffind(a),b=uffind(b); if(a==b) return; if(ufsz[a]<ufsz[b]) swap(a,b); ufpar[b]=a,ufsz[a]+=ufsz[b]; }

bool solve() {
	REP(i,ngroup) { groupremcnt[i]=0; REP(j,n) if(group[i][j]=='1') ++groupremcnt[i]; }
	REP(i,ngroup) if(groupremcnt[i]>=2) REP(j,n) if(group[i][j]=='1') bs[j][i]=1;
	REP(i,n) cnt[i]=bs[i].count();
	REP(i,n) FOR(j,i+1,n) { int common=(bs[i]&bs[j]).count(); extra[i][j]=cnt[i]-common; extra[j][i]=cnt[j]-common; }

	ans.clear();
	q=queue<pair<int,int>>();
	REP(i,n) done[i]=false,ufpar[i]=i,ufsz[i]=1;
	REP(i,n) REP(j,n) if(i!=j&&extra[i][j]==0) q.push(MP(i,j));
	while(!q.empty()) {
		int leaf=q.front().first,parent=q.front().second; q.pop();
		if(done[leaf]||done[parent]||uffind(leaf)==uffind(parent)) continue;
		done[leaf]=true;
		ans.PB(MP(leaf,parent));
		ufunite(leaf,parent);
		REP(i,ngroup) if(groupremcnt[i]>=2&&group[i][leaf]=='1') {
			--groupremcnt[i];
			if(groupremcnt[i]==1) {
				REP(to,n) if(!done[to]) {
					--extra[parent][to];
					if(extra[parent][to]==0) q.push(MP(parent,to));
				}
			}
		}
	}
	REP(i,ngroup) REP(j,n) bs[j][i]=0;
	return SZ(ans)==n-1;
}

void run() {
	scanf("%d%d",&n,&ngroup);
	REP(i,ngroup) scanf("%s",group[i]);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REPSZ(i,ans) printf("%d %d\n",ans[i].first+1,ans[i].second+1);
}

int main() {
	REP(i,MAXN) bs[i]=0;
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}
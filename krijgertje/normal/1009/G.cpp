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

const int MAXLEN=100000;
const int ALPH=6;

struct G {
	int n,m,s,t,totalflow;
	vector<int> ghead,gnxt,gto,gcap;
	void init(int _n,int _s,int _t) { n=_n,m=0,s=_s,t=_t,totalflow=0; ghead=vector<int>(n,-1),gnxt.clear(),gto.clear(),gcap.clear(); }
	int addedge(int a,int b,int c) {
		int ret=m; gnxt.PB(ghead[a]),ghead[a]=m,gto.PB(b),gcap.PB(c),++m; gnxt.PB(ghead[b]),ghead[b]=m,gto.PB(a),gcap.PB(0),++m; return ret;
	}
	int maxflow(int lim) {
		//if(lim-totalflow>1) printf("%d vs %d\n",totalflow,lim);
		while(totalflow<lim) {
			queue<int> q; vector<int> back(n,-1); vector<int> flow(n,0);
			q.push(s),back[s]=-2,flow[s]=INT_MAX;
			while(!q.empty()&&flow[t]==0) {
				int at=q.front(); q.pop();
				for(int x=ghead[at];x!=-1;x=gnxt[x]) {
					int to=gto[x];
					if(gcap[x]==0||flow[to]!=0) continue;
					q.push(to),back[to]=x^1,flow[to]=min(gcap[x],flow[at]);
				}
			}
			if(flow[t]==0) break;
			totalflow+=flow[t];
			for(int at=t;at!=s;at=gto[back[at]]) {
				gcap[back[at]]+=flow[t];
				gcap[back[at]^1]-=flow[t];
			}
		}
		//printf("totalflow=%d\n",totalflow);
		return totalflow;
	}

	vector<int> rback; vector<bool> rbeen;
	void precalcreroute(int reid) {
		int a=gto[reid^1];
		queue<int> q; rback=vector<int>(n,-1); rbeen=vector<bool>(n,false);
		q.push(a),rback[a]=-2,rbeen[a]=true;
		while(!q.empty()) {
			int at=q.front(); q.pop();
			for(int x=ghead[at];x!=-1;x=gnxt[x]) {
				int to=gto[x];
				if(gcap[x]==0||rbeen[to]) continue;
				q.push(to),rback[to]=x^1,rbeen[to]=true;
			}
		}
	}
	bool reroute(int leid,int reid) {
		int a=gto[reid^1],b=gto[leid];
		if(!rbeen[b]) return false;
		--gcap[leid^1],--gcap[reid^1];
		for(int at=b;at!=a;at=gto[rback[at]]) {
			++gcap[rback[at]];
			--gcap[rback[at]^1];
		}
		return true;
	}

};

char s[MAXLEN+1]; int slen;
int cond[MAXLEN];
char ret[MAXLEN+1];

int sid,tid,lid[ALPH],rid[1<<ALPH],nid;
int leid[ALPH],reid[1<<ALPH];
int have[ALPH],need[1<<ALPH];

G g;

bool solve() {
	REP(i,ALPH) have[i]=0; REP(i,slen) ++have[s[i]-'a'];
	REP(j,1<<ALPH) need[j]=0; REP(i,slen) ++need[cond[i]];

	nid=0; sid=nid++; tid=nid++; REP(i,ALPH) lid[i]=nid++; REP(j,1<<ALPH) rid[j]=nid++;
	g.init(nid,sid,tid);
	REP(i,ALPH) leid[i]=g.addedge(sid,lid[i],have[i]);
	REP(i,ALPH) REP(j,1<<ALPH) if(j&(1<<i)) g.addedge(lid[i],rid[j],min(have[i],need[j]));
	REP(j,1<<ALPH) reid[j]=g.addedge(rid[j],tid,need[j]);

	if(g.maxflow(slen)!=slen) return false;
	REP(i,slen) {
		bool found=false;
		g.precalcreroute(reid[cond[i]]);
		REP(c,ALPH) if(have[c]>0&&(cond[i]&(1<<c))!=0&&g.reroute(leid[c],reid[cond[i]])) {
			--have[c],--need[cond[i]],found=true,ret[i]='a'+c; break;
		}
		assert(found);
	}
	ret[slen]='\0';
	return true;
}

void run() {
	scanf("%s",s); slen=strlen(s);
	REP(i,slen) cond[i]=(1<<ALPH)-1; int nq; scanf("%d",&nq); REP(i,nq) { int idx; char buff[ALPH+1]; scanf("%d%s",&idx,buff); --idx,cond[idx]=0; for(int j=0;buff[j]!='\0';++j) cond[idx]|=1<<(buff[j]-'a'); }
	//printf("cond:"); REP(i,slen) printf(" %x",cond[i]); puts("");

	if(!solve()) { printf("Impossible"); return; }
	printf("%s\n",ret);
}

void stress() {
	REP(rep,1) {
		slen=MAXLEN; REP(i,slen) s[i]=i<ALPH?'a'+i:'f'; s[slen]='\0';
		REP(i,slen) cond[i]=(1<<ALPH)-1;
		REP(i,ALPH) cond[slen-i-1]=1<<i;
		//printf("%s\n",s); printf("cond:"); REP(i,slen) printf(" %x",cond[i]); puts("");
		bool res=solve();
		printf("%c",res?'V':'x');
	}
}

int main() {
	run();
	//stress();
	return 0;
}
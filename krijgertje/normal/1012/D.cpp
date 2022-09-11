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

vector<pair<int,int>> solvesame(vector<int> x,vector<int> y);
vector<pair<int,int>> solvediff(vector<int> x,vector<int> y) {
	//printf("solvediff(%d,%d)\n",SZ(x),SZ(y));
	vector<pair<int,int>> ret;
	if(SZ(x)<=1&&SZ(y)<=1) return ret;
	if(SZ(x)<SZ(y)) { ret=solvediff(y,x); REPSZ(i,ret) swap(ret[i].first,ret[i].second); return ret; }
	if(SZ(y)<=1) {
		int nxmove=SZ(x)/2; bool ymove=SZ(y)==1&&nxmove%2==1; int xsum=0; REP(i,nxmove) xsum+=x[i]; ret.PB(MP(xsum,ymove?y[0]:0));
		vector<int> nx,ny; REPSZ(i,x) if(i<nxmove) ny.PB(x[i]); else nx.PB(x[i]); if(SZ(y)==1) if(ymove) nx[0]+=y[0]; else ny.back()+=y[0];
		auto sub=nxmove%2==0?solvesame(nx,ny):solvediff(nx,ny);
		REPSZ(i,sub) ret.PB(sub[i]);
		return ret;
	} else if(SZ(y)==2) {
		if(SZ(x)==2) {
			ret.PB(MP(x[0],y[0])); return ret;
		} else if(SZ(x)==3) {
			ret.PB(MP(x[0],y[0])); ret.PB(MP(y[0]+x[1],x[0]+y[1])); return ret;
		} else if(SZ(x)==4) {
			ret.PB(MP(x[0],y[0])); ret.PB(MP(y[0]+x[1],x[0]+y[1])); ret.PB(MP(x[0]+y[1]+x[2],y[0]+x[1])); return ret;
		} else if(SZ(x)==5) {
			ret.PB(MP(x[0]+x[1]+x[2],y[0])); ret.PB(MP(y[0]+x[3],x[0])); ret.PB(MP(x[0]+x[4],y[0]+x[3]+x[1])); return ret;
		} else {
			int xfst=x[0],yfst=y[0],ylst=y[1],reps=(SZ(x)-2)/4;
			REP(i,reps) {
				ret.PB(MP(xfst+x[4*i+1]+x[4*i+2],yfst)); ret.PB(MP(yfst+x[4*i+3],xfst));
				xfst+=x[4*i+4],yfst+=x[4*i+1]+x[4*i+3],ylst+=x[4*i+2];
			}
			vector<int> nx,ny; nx.PB(xfst); FORSZ(i,4*reps+1,x) nx.PB(x[i]); ny.PB(yfst); ny.PB(ylst);
			auto sub=solvediff(nx,ny);
			REPSZ(i,sub) ret.PB(sub[i]);
			return ret;
		}
	} else {
		int xfst=x[0],yfst=y[0],reps=SZ(y)-2;
		REP(i,reps) { 
			ret.PB(MP(xfst,yfst));
			swap(xfst,yfst); xfst+=x[i+1]; yfst+=y[i+1];
		}
		vector<int> nx,ny; nx.PB(xfst); FORSZ(i,reps+1,x) nx.PB(x[i]); ny.PB(yfst); FORSZ(i,reps+1,y) ny.PB(y[i]);
		auto sub=solvediff(nx,ny);
		REPSZ(i,sub) ret.PB(sub[i]);
		return ret;
	}
}
vector<pair<int,int>> solvesame(vector<int> x,vector<int> y) {
	//printf("solvesame(%d,%d)\n",SZ(x),SZ(y));
	vector<pair<int,int>> ret;
	if(SZ(x)+SZ(y)<=1) return ret;
	if(SZ(x)<SZ(y)) { ret=solvesame(y,x); REPSZ(i,ret) swap(ret[i].first,ret[i].second); return ret; }
	if(SZ(y)<=1) {
		int nxmove=SZ(x)/2; bool ymove=SZ(y)==1&&nxmove%2==0; int xsum=0; REP(i,nxmove) xsum+=x[i]; ret.PB(MP(xsum,ymove?y[0]:0)); 
		vector<int> nx,ny; REPSZ(i,x) if(i<nxmove) ny.PB(x[i]); else nx.PB(x[i]); if(SZ(y)==1) if(ymove) nx[0]+=y[0]; else ny.back()+=y[0];
		auto sub=nxmove%2==0?solvesame(nx,ny):solvediff(nx,ny);
		REPSZ(i,sub) ret.PB(sub[i]);
		return ret;
	} else if(SZ(x)==2) {
		ret.PB(MP(x[0],0)); ret.PB(MP(x[1],x[0]+y[0])); return ret;
	} else if(SZ(x)==3) {
		if(SZ(y)==2) {
			ret.PB(MP(x[0],0)); ret.PB(MP(x[1],x[0]+y[0])); return ret;
		} else {
			ret.PB(MP(x[0],0)); ret.PB(MP(x[1],x[0]+y[0])); ret.PB(MP(x[0]+y[0]+x[2],x[1]+y[1])); return ret;
		}
	} else {
		int xfst=x[0],yfst=y[0],ysnd=y[1],reps=(SZ(x)-2)/2;
		REP(i,reps) {
			ret.PB(MP(xfst+x[2*i+1],yfst));
			swap(xfst,yfst); xfst+=x[2*i+2]; ysnd+=x[2*i+1];
		}
		vector<int> nx,ny; nx.PB(xfst); FORSZ(i,2*reps+1,x) nx.PB(x[i]); ny.PB(yfst); ny.PB(ysnd); FORSZ(i,2,y) ny.PB(y[i]);
		auto sub=solvesame(nx,ny);
		REPSZ(i,sub) ret.PB(sub[i]);
		return ret;
	}
}

vector<pair<int,int>> solve(string sx,string sy) {
	vector<int> x; for(int l=0,r=l;l<SZ(sx);l=r) { while(r<SZ(sx)&&sx[l]==sx[r]) ++r; x.PB(r-l); }
	vector<int> y; for(int l=0,r=l;l<SZ(sy);l=r) { while(r<SZ(sy)&&sy[l]==sy[r]) ++r; y.PB(r-l); }
	return sx[0]!=sy[0]?solvediff(x,y):solvesame(x,y);
}

void run() {
	string sx,sy; cin>>sx>>sy;
	auto ans=solve(sx,sy);
	printf("%d\n",SZ(ans)); REPSZ(i,ans) printf("%d %d\n",ans[i].first,ans[i].second);
}

bool verify(string x,string y,vector<pair<int,int>> ops) {
	REPSZ(i,ops) {
		int xi=ops[i].first,yi=ops[i].second;
		if(xi<0||xi>SZ(x)||yi<0||yi>SZ(y)) return false;
		string nx=y.substr(0,yi)+x.substr(xi);
		string ny=x.substr(0,xi)+y.substr(yi);
		x=nx,y=ny;
	}
	FORSZ(i,1,x) if(x[i]!=x[i-1]) return false;
	FORSZ(i,1,y) if(y[i]!=y[i-1]) return false;
	return true;
}

void stress() {
	FORE(len,1,14) {
		// id=mask+(1<<len)*alen
		int nid=(1<<len)*(len+1);
		vector<vector<int>> adj(nid);
		vector<int> s;
		REP(at,nid) {
			int alen=at>>len,blen=len-alen,mask=at-(alen<<len),bmask=mask>>alen,amask=mask-(bmask<<alen);
			if(amask==0&&bmask==(1<<blen)-1||bmask==0&&amask==(1<<alen)-1) s.PB(at);
			REPE(i,alen) REPE(j,blen) {
				int nalen=alen-i+j,nblen=blen-j+i,nmask=(bmask&((1<<j)-1))|((amask>>i)<<j)|((amask&((1<<i)-1))<<nalen)|((bmask>>j)<<(nalen+i)),to=nmask|(nalen<<len);
				//REP(k,len) { printf("%c",(mask&(1<<k))==0?'a':'b'); if(k+1==alen) printf("|"); } printf(" -> "); REP(k,len) { printf("%c",(nmask&(1<<k))==0?'a':'b'); if(k+1==nalen) printf("|"); } puts("");
				adj[at].PB(to);
			}
		}
		vector<int> d(nid,INT_MAX); queue<int> q; REPSZ(i,s) { int at=s[i]; d[at]=0; q.push(at); }
		while(!q.empty()) { int at=q.front(); q.pop(); REPSZ(i,adj[at]) { int to=adj[at][i]; if(d[to]==INT_MAX) d[to]=d[at]+1,q.push(to); } }
		REP(at,nid) {
			int alen=at>>len,blen=len-alen,mask=at-(alen<<len),bmask=mask>>alen,amask=mask-(bmask<<alen);
			if(alen==0||blen==0) continue;
			string sa(alen,'?'),sb(blen,'?'); REP(i,alen) sa[i]=(amask&(1<<i))==0?'a':'b'; REP(i,blen) sb[i]=(bmask&(1<<i))==0?'a':'b';
			vector<pair<int,int>> have=solve(sa,sb); int want=d[at];
			
			if(want!=SZ(have)) {
				printf("%s %s: want=%d have=%d\n",sa.c_str(),sb.c_str(),want,SZ(have));
			}
			if(!verify(sa,sb,have)) {
				printf("%s %s: want=%d have=%d\n",sa.c_str(),sb.c_str(),want,SZ(have));
				REPSZ(i,have) printf("%d %d\n",have[i].first,have[i].second);
			}
		}
	}
}

int main() {
	run();
	//stress();
	return 0;
}
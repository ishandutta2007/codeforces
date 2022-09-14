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

const int MAXH=600;
const int MAXW=600;
const int MAXK=16;

int h,w,k;
int orig[MAXH][MAXW];
int g[MAXH][MAXW];
int res[MAXH][MAXW];

ll val[MAXK][MAXK];

ll dp[MAXK+1][MAXK][1<<MAXK];
int act[MAXK+1][MAXK][1<<MAXK];

int ret[MAXK];

char fname[100];
int casenr;
FILE *file;
int fsz;
void writechar(int x) { ++fsz; fputc(x&255,file); }
void writeshort(int x) { fsz+=2; fputc(x&255,file); fputc((x>>8)&255,file); }
void writeint(int x) { fsz+=4; fputc(x&255,file); fputc((x>>8)&255,file); fputc((x>>16)&255,file); fputc((x>>24)&255,file); }
void writebmp() {
	int hsz=40; // +68
	sprintf(fname,"e2/out%d.bmp",casenr);
	file=fopen(fname,"wb"); fsz=0;
	writeshort(19778);
	writeint(14+hsz+4*256+h*4*((w+3)/4));
	writeshort(0);
	writeshort(0);
	writeint(14+hsz+4*256-1024);
	writeint(hsz);
	writeint(w);
	writeint(h);
	writeshort(1);
	writeshort(8);
	REP(i,6) writeint(0);
	REP(i,256) { REP(j,3) writechar(i); writechar(i); }
	//REP(i,4) writeint(0); writeint(1); REP(i,9) writeint(0); REP(i,3) writeint(100);
	//REP(i,w-4) writechar(0);
	REP(x,h) {
		int n4=(w+3)/4;
		REP(i,n4-1) REP(j,4) writechar(i*4+j<w?res[h-x-1][i*4+j]:255);
		REP(j,4) writechar((n4-1)*4+j<w?res[h-x-1][(n4-1)*4+j]:255);
	}
	REP(i,1000) writechar(0);
	fclose(file);
}

void run() {
	scanf("%d%d%d",&h,&w,&k);
	REP(x,h) REP(y,w) scanf("%d",&g[x][y]);
	//if(casenr!=8) return;

	const int DAVG=1;
	const int DCMP=0;

	REP(x,h) REP(y,w) orig[x][y]=g[x][y];
	REP(x,h) REP(y,w) {
		int sum=0,cnt=0;
		FORE(dx,-DAVG,+DAVG) FORE(dy,-DAVG,+DAVG) {
			int nx=x+dx,ny=y+dy; if(nx<0||nx>=h||ny<0||ny>=w||x/(h/k)!=nx/(h/k)) continue;
			sum+=orig[nx][ny],++cnt;
		}
		g[x][y]=sum/cnt;
	}

	REP(i,k) REP(j,k) {
		if(i==j) { val[i][j]=LLONG_MAX; continue; }
		ll cur=0;
		int x1=(i+1)*(h/k)-1,x2=j*(h/k);
		REP(y,w) FORE(dx,0,+DCMP) FORE(dy,-DCMP,+DCMP) {
			int nx1=x1-dx,nx2=x2+dx,ny=y+dy; if(ny<0||ny>=w) continue;
			int diff=abs(g[nx1][y]-g[nx2][ny]);
			//if(i==0&&j==1) printf("%d: %d (%d,%d)\n",y,diff,nx1,nx2);
			//if(i==1&&j==2) printf("%d: %d\n",y,diff);
			//if(abs(diff)>50) ++cur;
			cur+=(ll)diff;
		}
		val[i][j]=cur;
	}
	//REP(i,k) { REP(j,k) if(val[i][j]==INT_MAX) printf("XXXXX "); else printf("%5d ",val[i][j]); puts(""); } puts("");

	REPE(i,k) REP(j,k) REP(mask,1<<k) dp[i][j][mask]=LLONG_MAX;
	REP(j,k) { int cmask=(1<<k)-(1<<j)-1; dp[1][j][cmask]=0; }
	REP(i,k) REP(j,k) REP(mask,1<<k) if(dp[i][j][mask]!=LLONG_MAX) {
		REP(nj,k) if(mask&(1<<nj)) {
			ll nval=dp[i][j][mask]+val[j][nj]; int nmask=mask-(1<<nj);
			//printf("%d %d %d -> %d %d %d\n",i,j,mask,i+1,nj,mask);
			if(nval<dp[i+1][nj][nmask]) dp[i+1][nj][nmask]=nval,act[i+1][nj][nmask]=j;
		}
	}
	//REPE(i,k) REP(j,k) REP(mask,1<<k) if(dp[i][j][mask]!=INT_MAX) printf("%d %d %x = %d (%d)\n",i,j,mask,dp[i][j][mask],act[i][j][mask]);

	int bj=0,bmask=0; FOR(j,1,k) if(dp[k][j][bmask]<dp[k][bj][bmask]) bj=j;
	//printf("best=%lld\n",dp[k][bj][bmask]);
	for(int i=k;i>=1;--i) {
		ret[bj]=i-1; int nj=act[i][bj][bmask]; bmask+=(1<<bj); bj=nj;
	}
	assert(bmask==(1<<k)-1);

	/*if(casenr==8) {
		//1 6 11 3 10 9 15 12 7 13 2 5 4 14 8
		REP(i,k-1) REP(a,k) REP(b,k) if(ret[a]==i&&ret[b]==i+1) printf("%d->%d ",a,b); puts("");
		{ int sum=0; REP(i,k-1) REP(a,k) REP(b,k) if(ret[a]==i&&ret[b]==i+1) { int cur=val[a][b]; sum+=cur; printf("%4d ",cur); } printf("= %d\n",sum); }
		//ret[0]=0; ret[1]=5; ret[2]=10; ret[3]=2; ret[4]=9; ret[5]=8; ret[6]=14; ret[7]=11; ret[8]=6; ret[9]=12; ret[10]=1; ret[11]=4; ret[12]=3; ret[13]=13; ret[14]=7;
		//ret[0]=1; ret[1]=2; ret[2]=0;
		ret[0]=1; ret[1]=0; ret[2]=3; ret[3]=2;
		REP(i,k-1) REP(a,k) REP(b,k) if(ret[a]==i&&ret[b]==i+1) printf("%d->%d ",a,b); puts("");
		{ int sum=0; REP(i,k-1) REP(a,k) REP(b,k) if(ret[a]==i&&ret[b]==i+1) { int cur=val[a][b]; sum+=cur; printf("%4d ",cur); } printf("= %d\n",sum); }
	} */



	REP(i,k) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
	int dh=h/k;
	REP(i,k) REP(x,dh) REP(y,w) res[ret[i]*dh+x][y]=orig[i*dh+x][y];

	//h=240,w=360; REP(x,h) REP(y,w) res[x][y]=(x+y)&255;
	//h=128,w=128; REP(x,h) REP(y,w) res[x][y]=(2*y)&255;
	//h=128,w=128; REP(x,h) REP(y,w) res[x][y]=(y)&255;
	//writebmp();

	//exit(0);
}

int main() {
	int n; scanf("%d",&n); for(casenr=1;casenr<=n;++casenr) run();
	return 0;
}
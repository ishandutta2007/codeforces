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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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

void run(int casenr) {
	int h,w,x,y,dx,dy; char sdir[10]; scanf("%d%d%d%d%s",&h,&w,&x,&y,sdir); --x,--y;
	if(strcmp(sdir,"UL")==0) { dx=-1; dy=-1; } else if(strcmp(sdir,"UR")==0) { dx=-1; dy=+1; } else if(strcmp(sdir,"DL")==0) { dx=+1; dy=-1; } else if(strcmp(sdir,"DR")==0) { dx=+1; dy=+1; } else assert(false);

	vector<int> cnt1(h+w-1,0),cnt2(h+w-1,0);
	int d1,d1l,d1r,d1cnt=0,d1need,d2,d2l,d2r,d2cnt=0,d2need;	//da=i -> y-x+h-1=i, dab=i -> x+y=i
	if((h-1)%2==(x+y)%2) {
		d1=0; d1l=d1r=h-1; d1need=1;
	} else {
		d1=1; d1l=h-2; d1r=h; d1need=2;
	}
	if((w-1)%2==(x+y)%2) {
		d2=w-1+h-1; d2l=d2r=w-1; d2need=1;
	} else {
		d2=w-2+h-1; d2l=w-2; d2r=w; d2need=2;
	}

	ll ret=1;
	while(d1<=h-1||d2>=h-1) {
		int nx=x+dx,ny=y+dy;
		if(nx<0||nx>=h) dx=-dx;
		if(ny<0||ny>=w) dy=-dy;
		int xcnt=dx<0?x:h-1-x,ycnt=dy<0?y:w-1-y,cnt=min(xcnt,ycnt); assert(cnt>=1);
		nx=x+cnt*dx,ny=y+cnt*dy; ret+=cnt;
//		printf("(%d,%d)[%c,%c](%d,%d)",x,y,dx<0?'-':'+',dy<0?'-':'+',nx,ny); if(d1<=h-1) printf(" +[%d:%d/%d,%d..%d]",d1,d1cnt,d1need,d1l,d1r); if(d2>=h-1) printf(" -[%d:%d/%d,%d..%d]",d2,d2cnt,d2need,d2l,d2r); puts(""); 
		if((x+y)==(nx+ny)) {
			++cnt2[x+y]; if(cnt2[x+y]>=3) { printf("-1\n"); return; }
			if(cnt2[x+y]==1) {
				if(d1l<=x+y&&x+y<=d1r) ++d1cnt;
				if(d2l<=x+y&&x+y<=d2r) ++d2cnt;
			}
		} else {
			++cnt1[y-x+h-1]; if(cnt1[y-x+h-1]>=3) { printf("-1\n"); return; }
		}
//		{ int cmin=INT_MAX,ccnt=0; for(int cx=h-1-35939,cy=0;cx<h&&cy<w;++cx,++cy) { int now=cnt1[cy-cx+h-1]+cnt2[cx+cy]; if(now<cmin) cmin=now; if(now==0) ++ccnt; } printf("\t%d %d\n",cmin,ccnt); }
		while(d1<=h-1&&(cnt1[d1]>0||d1cnt>=d1need)) {
//			if(d1==35939) printf(" +[%d:%d/%d,%d..%d]\n",d1,d1cnt,d1need,d1l,d1r);
			d1+=2; d1need+=2; d1l-=2; int od1r=d1r; d1r+=2; if(d1need>w) { d1need=w; d1r=h-1+w-1-d1+w-1; }
			if(d1l>=0&&cnt2[d1l]>0) ++d1cnt; if(d1r>od1r&&d1r<h+w-1&&cnt2[d1r]>0) ++d1cnt; if(d1r<od1r&&od1r<h+w-1&&cnt2[od1r]>0) --d1cnt;
		}
		while(d2>=h-1&&(cnt1[d2]>0||d2cnt>=d2need)) {
			d2-=2; d2need+=2; d2l-=2; int od2r=d2r; d2r+=2; if(d2need>h) { d2need=h; d2r=h-1+d2; }
			if(d2l>=0&&cnt2[d2l]>0) ++d2cnt; if(d2r>od2r&&d2r<h+w-1&&cnt2[d2r]>0) ++d2cnt; if(d2r<od2r&&od2r<h+w-1&&cnt2[od2r]>0) --d2cnt;
		}
		x=nx; y=ny;
	}
//	printf("%d %d\n",x,y);
	while(cnt1[y-x+h-1]+cnt2[x+y]>1) { --ret; x-=dx; y-=dy; }
//	printf("%d %d\n",x,y);
	cout<<ret<<endl;
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
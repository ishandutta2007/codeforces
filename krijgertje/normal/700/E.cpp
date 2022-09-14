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

const int MAXN=200000;
const int MAXLGN=17;

typedef struct SA {
	int cnt[MAXN+1];
	int arr[8*MAXN+10000];
	int amax;

	bool leq(int a,int b,int A,int B) { return a<A||a==A&&b<=B; }
	bool leq(int a,int b,int c,int A,int B,int C) { return a<A||a==A&&b<B||a==A&&b==B&&c<=C; }
	void countsort(int *a,int n,int K,int *key,int *b) {
		REPE(i,K) cnt[i]=0;
		REP(i,n) ++cnt[key[a[i]]+1];
		REP(i,K) cnt[i+1]+=cnt[i];
		for(int i=n-1;i>=0;--i) b[--cnt[key[a[i]]+1]]=a[i];
	}

	// calculate suffix array of s[0..n-1] which has elements in [0..K-1] (requires s[n]=s[n+1]=s[n+2]==-1)
	void calc(int *s,int n,int K,int *t) {
		//printf("calc("); REP(i,n+3) { if(i!=0) printf(","); printf("%d",s[i]); } printf(")\n");
		int n0=(n+2)/3,n1=(n+2)/3,n2=n/3; // n1 might be one bigger than expected so that triplets at positions starting at i%3==1 include at least one -1
		int *s12=t+n+3,*t12=s12+n1+n2+3; int n12=0;
		REP(i,n0+n1+n2) if(i%3!=0) s12[n12++]=i; s12[n12]=s12[n12+1]=s12[n12+2]=t12[n12]=t12[n12+1]=t12[n12+2]=-1;
		countsort(s12,n12,K,s+2,t12);
		countsort(t12,n12,K,s+1,s12);
		countsort(s12,n12,K,s+0,t12);
		int nK=0; REP(i,n12) s12[(t12[i]%3==1?0:n1)+t12[i]/3]=(i==0||s[t12[i]]!=s[t12[i-1]]||s[t12[i]+1]!=s[t12[i-1]+1]||s[t12[i]+2]!=s[t12[i-1]+2])?nK++:nK-1;
		//printf("\ts12:"); REP(i,n12) printf(" %d",s12[i]); puts("");
		//printf("\tt12:"); REP(i,n12) printf(" %d",t12[i]); puts("");
		if(nK<n12) {
			calc(s12,n12,nK,t12);
			REP(i,n12) s12[t12[i]]=i;
		} else {
			REP(i,n12) t12[s12[i]]=i;
		}
		//printf("\tt12:"); REP(i,n12) printf(" %d",t12[i]); puts("");
		int *s0=t12+n1+n2+3,*t0=s0+n0; n0=0; REP(i,n12) if(t12[i]<n1) s0[n0++]=3*t12[i];
		countsort(s0,n0,K,s,t0);
		//printf("\ts0:"); REP(i,n0) printf(" %d",s0[i]); puts("");
		//printf("\tt0:"); REP(i,n0) printf(" %d",t0[i]); puts("");
		int a=0,b=n%3==1?1:0; n=0;
		while(a<n0||b<n12) {
			int i=t0[a],j=t12[b]<n1?3*t12[b]+1:3*(t12[b]-n1)+2;
			if(b>=n12||a<n0&&(t12[b]<n1?leq(s[i],s12[i/3],s[j],s12[n1+j/3]):leq(s[i],s[i+1],s12[n1+i/3],s[j],s[j+1],s12[j/3+1]))) t[n++]=i,++a; else t[n++]=j,++b;
		}
		//printf("\tt:"); REP(i,n) printf(" %d",t[i]); puts("");
		amax=max(amax,t0+n0-arr);
	}

	void calc(char *in,int *sa) {
		int n=strlen(in);
		int *s=arr,*t=s+n+3;
		REP(i,n) s[i]=(int)in[i]; s[n]=s[n+1]=s[n+2]=-1;
		calc(s,n,256,t);
		//fprintf(stderr,"amax=%d (%.9lf)\n",amax,1.0*amax/n);
		REP(i,n) sa[i]=t[i];
	}
} SA;
SA sacalc;

int n;
char s[MAXN+1];

int sa[MAXN]; // sa[i] = ith suffix (lexographically ordered)
int rnk[MAXN]; // rnk[i] = position of s[i..) in ordered suffixes
bool on[MAXN];

int lg[MAXN+1]; // lg[i] is maximum k such that (1<<k)<=i
int lcp[MAXN-1]; // lcp[i] = longest common prefix of s+sa[i] and s+sa[i+1]
int rmq[MAXN][MAXLGN+1]; // rmq[i][j] = minimum lcp[i]..lcp[i+(1<<j)-1]

int sval[2*MAXN];

void sset(int idx,int val) { idx+=n; sval[idx]=val; for(idx>>=1;idx>=1;idx>>=1) sval[idx]=min(sval[idx<<1],sval[idx<<1|1]); }
void disable(int i) { on[i]=false; sset(rnk[i],INT_MAX); }
int sfind(int lidx,int ridx) { lidx+=n,ridx+=n; int ret=INT_MAX; for(;lidx<ridx;lidx>>=1,ridx>>=1) { if(lidx&1) ret=min(ret,sval[lidx++]); if(ridx&1) ret=min(ret,sval[--ridx]); } return ret==INT_MAX?-1:ret; }
int bffindlowest(int a,int b) { int ret=-1; FORE(c,a,b) { int i=sa[c]; if(on[i]&&(ret==-1||i<ret)) ret=i; } return ret; }
int findlowest(int a,int b) {
	int ret=sfind(a,b+1);
	//printf("bffindlowest(%d,%d): ret=%d bf=%d\n",a,b,ret,bffindlowest(a,b));
	//REP(c,n) printf("%3d ",on[sa[c]]?sa[c]:-1); puts("");
	//assert(ret==bffindlowest(a,b));
	return ret;
}
int bflcp[MAXN-1]; int bfcalclcp(int i,int j) { int ret=0; while(i<n&&j<n&&s[i]==s[j]) ++ret,++i,++j; return ret; }
int bflcp2(int i,int j) { int a=rnk[i],b=rnk[j]; if(a>b) swap(a,b); int ret=INT_MAX; FOR(c,a,b) if(lcp[c]<ret) ret=lcp[c]; return ret; }
int getlcp(int i,int j) {
	int a=rnk[i],b=rnk[j]; if(a>b) swap(a,b);
	assert(a!=b); int k=lg[b-a]; int ret=min(rmq[a][k],rmq[b-(1<<k)][k]);
	//assert(ret==bflcp(i,j)&&ret==bflcp2(i,j));
	return ret;
}
int bfsa[MAXN]; bool bfcmp(int i,int j) { return strcmp(s+i,s+j)<0; }
void init() {
	REP(i,n) on[i]=true;
	//printf("presort\n");
	sacalc.calc(s,sa);
	//REP(i,n) bfsa[i]=i; sort(bfsa,bfsa+n,bfcmp); REP(i,n) assert(sa[i]==bfsa[i]);
	//printf("sorted\n");
	REP(i,n) rnk[sa[i]]=i;
	//printf("prelcp\n");
	int k=0; REP(i,n) {
		if(rnk[i]==n-1) { k=0; continue; }
		int j=sa[rnk[i]+1];
		while(i+k<n&&j+k<n&&s[i+k]==s[j+k]) ++k;
		lcp[rnk[i]]=k;
		if(k>0) --k;
	}
	//REP(i,n-1) bflcp[i]=bfcalclcp(sa[i],sa[i+1]); REP(i,n-1) assert(lcp[i]==bflcp[i]);
	//printf("lcp\n");
	lg[1]=0; FORE(i,1,n) { lg[i]=lg[i-1]; while((1<<(lg[i]+1))<=i) ++lg[i]; }
	REP(i,n-1) rmq[i][0]=lcp[i];
	REP(k,MAXLGN) REP(i,n-1) { rmq[i][k+1]=rmq[i][k]; if(i+(1<<k)<n-1&&rmq[i+(1<<k)][k]<rmq[i][k+1]) rmq[i][k+1]=rmq[i+(1<<k)][k]; }
	REP(i,n) sset(rnk[i],i);
}
pair<int,int> bffindrange(int i,int len) { int a=rnk[i],b=rnk[i]; while(a>0&&getlcp(sa[a-1],i)>=len) --a; while(b+1<n&&getlcp(sa[b+1],i)>=len) ++b; return MP(a,b); }
pair<int,int> findrange(int i,int len) {
	int a=rnk[i],b=rnk[i];
	for(int k=MAXLGN;k>=0;--k) if(a-(1<<k)>=0&&getlcp(sa[a-(1<<k)],i)>=len) a-=(1<<k);
	for(int k=MAXLGN;k>=0;--k) if(b+(1<<k)<n&&getlcp(sa[b+(1<<k)],i)>=len) b+=(1<<k);
	//pair<int,int> bf=bffindrange(i,len); assert(bf.first==a&&bf.second==b);
	return MP(a,b);
}


void run() {
	scanf("%d%s",&n,s); n=strlen(s);
	//srand(time(NULL)); n=MAXN; REP(i,n) s[i]=(rand()%1000==0?1:0)+'a';
	init();
	//REP(i,n) printf("%2d: %2d %s\n",i,sa[i],s+sa[i]);
	int ret=0;
	REP(i,n) {
		// disable suffix starting at i
		disable(i);
		int cur=1,len=1;
		while(true) {
			// find interval of suffixes matching s[i..i+len) = [A,B]
			pair<int,int> range=findrange(i,len);
			// find lowest enabled suffix in [A,B] = j (none -> break)
			int j=findlowest(range.first,range.second);
			if(j==-1) break;
			if(j>=i+len) { ++cur; len=j+len-i; continue; }
			int common=getlcp(i,j),period=j-i;
			// nlen=nx*period+len%period, nlen<=common+period, (nx-1)*period+len%period<=common, nx<=1+(common-len%period)/period
			int x=len/period,nx=1+(common-len%period)/period;
			//if(i==0) printf("\tlen=%d, period=%d, rem=%d, x=%d nx=%d nlen=%d (common=%d)\n",len,period,len%period,x,nx,nx*period+len%period,common);
			cur+=nx-x; len=nx*period+len%period;
		}
		if(cur>ret) ret=cur;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
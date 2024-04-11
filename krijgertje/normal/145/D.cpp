#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<iostream>
using namespace std;

#define PB push_back
#define SZ(v) ((int)(v).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n) FORE(i,0,n)
#define REPSZ(i,v) REP(i,SZ(v))

typedef long long ll;

typedef struct X { int requiredluckyinseg2,maxlastluckyinseg1,maxlastluckyinseg2; } X;

bool islucky(int x) {
	if(x==0) return false;
	while(x>0) { if(x%10!=4&&x%10!=7) return false; x/=10; }
	return true;
}

int n,nlucky;
vector<int> luckypos;

ll __gcd(ll a,ll b) { if(b==0) return a; return __gcd(b,a%b); }

ll choose(int n,int cnt) {
	if(cnt==1) return n;
	if(cnt==2) return (ll)n*(n+1)/2;
	if(cnt==3) return (ll)n*(n+1)*(n+2)/6;
//	if(cnt==4) return (ll)n*(n+1)*(n+2)*(n+3)/24;
	if(cnt==4) { ll a=n,b=n+1,c=n+2,d=n+3; ll rem=24; ll g=__gcd(a,rem); a/=g,rem/=g; g=__gcd(b,rem); b/=g,rem/=g; g=__gcd(c,rem); c/=g,rem/=g; g=__gcd(d,rem); d/=g,rem/=g; return a*b*c*d; }
	throw 1;
}

ll calc(int la,int ha,int lb,int hb,int lc,int hc,int ld,int hd) {
	if(lb<la) lb=la; if(lc<lb+1) lc=lb+1; if(ld<lc) ld=lc;
	if(hc>hd) hc=hd; if(hb>hc-1) hb=hc-1; if(ha>hb) ha=hb;
	if(la>ha||lb>hb||lc>hc||ld>hd) return 0;
//	printf("[[%d..%d]..[%d..%d]] [[%d..%d]..[%d..%d]]\n",la,ha,lb,hb,lc,hc,ld,hd);
//	ll check=0; FORE(a,la,ha) FORE(b,max(a,lb),hb) FORE(c,max(b+1,lc),hc) FORE(d,max(c,ld),hd) ++check;
	int lcc=lc-1,hcc=hc-1,ldd=ld-1,hdd=hd-1;
	vector<int> l(4); l[0]=la; l[1]=lb; l[2]=lcc; l[3]=ldd;
	vector<int> h(4); h[0]=ha; h[1]=hb; h[2]=hcc; h[3]=hdd;
	vector<int> events; events.PB(la); events.PB(ha+1); events.PB(lb); events.PB(hb+1); events.PB(lcc); events.PB(hcc+1); events.PB(ldd); events.PB(hdd+1); sort(events.begin(),events.end()); events.erase(unique(events.begin(),events.end()),events.end());
	int nintervals=SZ(events)-1;
	vector<ll> ways(5,0); ways[0]=1;
	REP(i,nintervals) {
		int from=events[i],to=events[i+1]-1;
		for(int done=4;done>=0;--done) if(ways[done]>0) {
			int ndone=done;
			for(int ndone=done+1;ndone<=4;++ndone) {
				if(to<l[ndone-1]||from>h[ndone-1]) break;
//				printf("\t\t[%d..%d] %d->%d += %lld * %lld\n",from,to,done,ndone,ways[done],choose(to-from+1,ndone-done));
				ways[ndone]+=ways[done]*choose(to-from+1,ndone-done);
			}
		}
	}
	ll ret=ways[4];
//	printf("\t%lld vs %lld\n",ret,check);
	return ret;
}

ll calclucky(int firstluckyinseg1,int maxlastluckyinseg1,int minfirstluckyinseg2,int maxfirstluckyinseg2,int minlastluckyinseg2,int maxlastluckyinseg2,bool popping) {
	if(maxlastluckyinseg1<firstluckyinseg1) return 0;
//	printf("\t[%d..[?..%d]] [[%d..%d]..[%d..%d]] %c\n",firstluckyinseg1,maxlastluckyinseg1,minfirstluckyinseg2,maxfirstluckyinseg2,minlastluckyinseg2,maxlastluckyinseg2,popping?'X':' ');
	int minfirstseg1=firstluckyinseg1==0?0:luckypos[firstluckyinseg1-1]+1;
	int maxfirstseg1=luckypos[firstluckyinseg1];
	int minlastseg1=luckypos[firstluckyinseg1];
	int maxlastseg1=maxlastluckyinseg1+1==nlucky?n-1:luckypos[maxlastluckyinseg1+1]-1;
	int minfirstseg2=minfirstluckyinseg2==0?0:luckypos[minfirstluckyinseg2-1]+1;
	int maxfirstseg2=luckypos[maxfirstluckyinseg2];
	int minlastseg2=luckypos[minlastluckyinseg2];
	int maxlastseg2=maxlastluckyinseg2+1==nlucky?n-1:luckypos[maxlastluckyinseg2+1]-1;
	return calc(minfirstseg1,maxfirstseg1,minlastseg1,maxlastseg1,minfirstseg2,maxfirstseg2,minlastseg2,maxlastseg2);
}

void run() {
	scanf("%d",&n);
	vector<int> luckyval;
	luckypos.clear();
	REP(i,n) {
		int x; scanf("%d",&x);
		if(islucky(x)) { luckyval.PB(x); luckypos.PB(i); }
	}
	nlucky=SZ(luckyval);
//	printf("%d %d\n",n,nlucky);
	vector<int> allluckyval(0); REP(i,nlucky) allluckyval.PB(luckyval[i]); sort(allluckyval.begin(),allluckyval.end()); allluckyval.erase(unique(allluckyval.begin(),allluckyval.end()),allluckyval.end());
	map<int,int> luckyval2id; REPSZ(i,allluckyval) luckyval2id[allluckyval[i]]=i;
	vector<int> luckyid(nlucky); REP(i,nlucky) luckyid[i]=luckyval2id[luckyval[i]];

	ll ret=0;
	REP(firstluckyinseg1,nlucky) {
		vector<int> firstidpos(SZ(allluckyval),-1); FOR(i,firstluckyinseg1,nlucky) if(firstidpos[luckyid[i]]==-1) firstidpos[luckyid[i]]=i;
		vector<X> stck;
		for(int nfirstluckyinseg2=nlucky-1;nfirstluckyinseg2>firstluckyinseg1;--nfirstluckyinseg2) {
			int nmaxlastluckyinseg1=firstidpos[luckyid[nfirstluckyinseg2]]-1;
			int nmaxlastluckyinseg2=nfirstluckyinseg2;
			while(SZ(stck)>0&&stck[SZ(stck)-1].maxlastluckyinseg1>nmaxlastluckyinseg1) {
				int maxlastluckyinseg1=stck[SZ(stck)-1].maxlastluckyinseg1;
				int minfirstluckyinseg2=nfirstluckyinseg2+1;
				int maxfirstluckyinseg2=stck[SZ(stck)-1].requiredluckyinseg2;
				int minlastluckyinseg2=stck[SZ(stck)-1].requiredluckyinseg2;
				int maxlastluckyinseg2=stck[SZ(stck)-1].maxlastluckyinseg2;
				ret+=calclucky(firstluckyinseg1,maxlastluckyinseg1,minfirstluckyinseg2,maxfirstluckyinseg2,minlastluckyinseg2,maxlastluckyinseg2,false);
				nmaxlastluckyinseg2=stck[SZ(stck)-1].maxlastluckyinseg2;
				stck.pop_back();
			}
			X x; x.requiredluckyinseg2=nfirstluckyinseg2; x.maxlastluckyinseg1=nmaxlastluckyinseg1; x.maxlastluckyinseg2=nmaxlastluckyinseg2; stck.PB(x);
		}
		while(SZ(stck)>0) {
			int maxlastluckyinseg1=stck[SZ(stck)-1].maxlastluckyinseg1;
			int minfirstluckyinseg2=firstluckyinseg1;
			int maxfirstluckyinseg2=stck[SZ(stck)-1].requiredluckyinseg2;
			int minlastluckyinseg2=stck[SZ(stck)-1].requiredluckyinseg2;
			int maxlastluckyinseg2=stck[SZ(stck)-1].maxlastluckyinseg2;
			ret+=calclucky(firstluckyinseg1,maxlastluckyinseg1,minfirstluckyinseg2,maxfirstluckyinseg2,minlastluckyinseg2,maxlastluckyinseg2,true);
			stck.pop_back();
		}
	}
	REPE(noluckyseg,nlucky) {
		int a=noluckyseg==0?0:luckypos[noluckyseg-1]+1;
		int b=noluckyseg==nlucky?n-1:luckypos[noluckyseg]-1;
		ret+=calc(a,b,a,b,0,n-1,0,n-1);
		ret+=calc(0,n-1,0,n-1,a,b,a,b);
		FORE(noluckyseg2,noluckyseg,nlucky) {
			int c=noluckyseg2==0?0:luckypos[noluckyseg2-1]+1;
			int d=noluckyseg2==nlucky?n-1:luckypos[noluckyseg2]-1;
			ret-=calc(a,b,a,b,c,d,c,d);
		}
	}
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}
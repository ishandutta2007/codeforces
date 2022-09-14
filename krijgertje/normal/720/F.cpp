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

const int MAXN=100000;
const int MINVAL=-50000;
const int MAXVAL=+50000;

int n; ll want;
int x[MAXN];
ll sumx[MAXN+1];
ll allsums[MAXN+1]; int nsums;
int sumidx[MAXN+1];

int b1[MAXN+2];
void b1mod(int idx,int by) { ++idx; while(idx<=nsums) { b1[idx]+=by; idx+=idx&-idx; } } 
int b1get(int idx) { if(idx==-1) return 0; ++idx; int ret=0; while(idx>0) { ret+=b1[idx]; idx-=idx&-idx; } return ret; }

ll b2[MAXN+2];
void b2mod(int idx,ll by) { ++idx; while(idx<=nsums) { b2[idx]+=by; idx+=idx&-idx; } } 
ll b2get(int idx) { if(idx==-1) return 0; ++idx; ll ret=0; while(idx>0) { ret+=b2[idx]; idx-=idx&-idx; } return ret; }

int b3[MAXN+2];
void b3mod(int idx,int val) { ++idx; while(idx<=nsums) { b3[idx]=min(b3[idx],val); idx+=idx&-idx; } } 
int b3get(int idx) { if(idx==-1) return n; ++idx; int ret=n; while(idx>0) { ret=min(ret,b3[idx]); idx-=idx&-idx; } return ret; }

ll cntatleast(ll val) {
	ll ret=0;
	FORE(i,1,nsums) b1[i]=0;
	REPE(i,n) {
		ll cur=sumx[i]-val; int key=lower_bound(allsums,allsums+nsums,cur)-allsums; if(key>=nsums||allsums[key]>cur) --key;
		int cnt=b1get(key); // #seen <=sumx[i]-val
		//printf("%d: %lld %d -> %lld %d -> %d\n",i,sumx[i],sumidx[i],cur,curidx,cnt);
		ret+=cnt;
		b1mod(sumidx[i],+1);
	}
	//printf("at least %lld = %lld\n",val,ret);
	return ret;
}

ll calc_nth(ll nfixed) {
	ll l=(ll)MAXN*MINVAL-1,h=(ll)MAXN*MAXVAL+1; // [l,h)
	while(l+1<h) {
		ll m=l+(h-l)/2;
		if(cntatleast(m)>nfixed) l=m; else h=m;
	}
	return l;
}

int e1[MAXN+1],e3[MAXN+1];
void init() {
	FORE(i,1,nsums) b1[i]=0,b2[i]=0,b3[i]=n;
	REPE(i,nsums) e1[i]=0,e3[i]=n;
}
void calcbelow(ll val,int &cnt,ll &sum,int &idx) {
	int key=lower_bound(allsums,allsums+nsums,val)-allsums-1;
	cnt=b1get(key);
	if(cnt!=0) sum=b2get(key);
	if(cnt!=0) idx=b3get(key);
}
void calceq(ll val,int &cnt, int &idx) {
	int key=lower_bound(allsums,allsums+nsums,val)-allsums;
	if(key>=nsums||allsums[key]!=val) { cnt=0; return; }
	cnt=e1[key];
	idx=e3[key];
}
void add(int key,int cnt,ll val,int idx) {
	b1mod(key,cnt);
	b2mod(key,val);
	b3mod(key,idx);
	++e1[key]; if(idx<e3[key]) e3[key]=idx;
}
int isfixed[MAXN+1];
typedef struct Dyn { int a,b; ll val; } Dyn;
bool operator <(const Dyn &p,const Dyn &q) { if(p.val!=q.val) return p.val>q.val; if(p.b!=q.b) return p.b<q.b; return p.a<q.a; }
Dyn dyn[MAXN]; int ndyn;
ll process(ll mn,ll mx,ll nmndyn,ll nmxfix) {
	ll ret=0; init();
	set<pair<ll,int> > seen;
	ndyn=0; REPE(i,n) isfixed[i]=0;
	REPE(i,n) {
		int cntfix1; ll sumfix1; int minfix1; calcbelow(sumx[i]-mx,cntfix1,sumfix1,minfix1);
		if(cntfix1>0) {
			ret+=cntfix1*sumx[i]-sumfix1;
			++isfixed[minfix1]; --isfixed[i]; //printf("fixed covers > [%d..%d]\n",minfix1,i-1);
		}
		int cmx; int minmx; calceq(sumx[i]-mx,cmx,minmx);
		ll cntfix2=min(nmxfix,(ll)cmx); cmx-=cntfix2; nmxfix-=cntfix2;
		if(cntfix2>0) {
			ret+=cntfix2*mx;
			++isfixed[minmx]; --isfixed[i]; //printf("fixed covers = [%d..%d]\n",minmx,i-1);
		}
		ll cntdyn1=mn!=mx?cmx:min((ll)cmx,nmndyn); if(mn==mx) nmndyn-=cntdyn1;
		if(cntdyn1>0) {
			REP(z,cntdyn1) dyn[ndyn].a=minmx,dyn[ndyn].b=i-1,dyn[ndyn].val=mx,++ndyn;
			//printf("%lld ranges [%d..%d] with value %lld\n",cntdyn1,minmx,i-1,mx);
		}
		if(mn!=mx) {
			//printf("enumerating dynamic ranges in range (%lld,%lld)\n",sumx[i]-mx,sumx[i]-mn);
			for(set<pair<ll,int> >::iterator at=seen.lower_bound(MP(sumx[i]-mx+1,INT_MIN));at!=seen.end()&&at->first<sumx[i]-mn;++at) {
				dyn[ndyn].a=at->second,dyn[ndyn].b=i-1,dyn[ndyn].val=sumx[i]-at->first,++ndyn;
				//printf("dynamic range [%d..%d] with value %lld\n",at->second,i-1,sumx[i]-at->first);
			}
			int cmn; int minmn; calceq(sumx[i]-mn,cmn,minmn);
			ll cntdyn3=min(nmndyn,(ll)cmn); nmndyn-=cntdyn3;
			if(cntdyn3>0) {
				REP(z,cntdyn3) dyn[ndyn].a=minmn,dyn[ndyn].b=i-1,dyn[ndyn].val=mn,++ndyn;
				//printf("%lld ranges [%d..%d] with value %lld\n",cntdyn3,minmn,i-1,mn);
			}
		}
		add(sumidx[i],1,sumx[i],i);
		seen.insert(MP(sumx[i],i));
	}
	REP(i,n) isfixed[i+1]+=isfixed[i];
	sort(dyn,dyn+ndyn);
	return ret;
}

void rem1(multiset<ll> &use,multiset<ll> &avail,ll &sumuse,ll val) {
	//printf("removing %lld\n",val);
	multiset<ll>::iterator at=use.lower_bound(val);
	if(at!=use.end()&&*at==val) { sumuse-=val; use.erase(at); return; }
	at=avail.lower_bound(val);
	if(at!=avail.end()&&*at==val) { avail.erase(at); return; }
	assert(false);
}
void add1(multiset<ll> &use,multiset<ll> &avail,ll &sumuse,ll val) {
	if(SZ(use)>0) {
		multiset<ll>::iterator at=use.end(); --at; if(val<*at) { use.insert(val); sumuse+=val; return; }
	}
	avail.insert(val);
}
ll smn[2*(MAXN+1)],smx[2*(MAXN+1)];
void suminit() {
	REPE(i,n) smn[n+1+i]=smx[n+1+i]=sumx[i];
	for(int i=n;i>=1;--i) smn[i]=min(smn[i<<1],smn[i<<1|1]),smx[i]=max(smx[i<<1],smx[i<<1|1]);
}
ll calcmnsum(int l,int r) {
	ll ret=LLONG_MAX;
	for(l+=n+1,r+=n+2;l<r;l>>=1,r>>=1) {
		if(l&1) ret=min(ret,smn[l++]);
		if(r&1) ret=min(ret,smn[--r]);
	}
	return ret;
}
ll calcmxsum(int l,int r) {
	ll ret=LLONG_MIN;
	for(l+=n+1,r+=n+2;l<r;l>>=1,r>>=1) {
		if(l&1) ret=max(ret,smx[l++]);
		if(r&1) ret=max(ret,smx[--r]);
	}
	return ret;
}
ll calcmnseg(int l,int r) {
	return sumx[r+1]-sumx[l]-(calcmxsum(l,r+1)-sumx[l])-(sumx[r+1]-calcmnsum(l,r+1));
}


ll seg[MAXN];
void run() {
	scanf("%d%lld",&n,&want); if(want>(ll)n*(n+1)/2) want=(ll)n*(n+1)/2;
	REP(i,n) scanf("%d",&x[i]);

	//n=100000; want=(ll)n*(n+1)/2; REP(i,n) x[i]=-50000;


	//vector<ll> zz; REP(i,n) FORE(j,i+1,n) { ll sum=0; FOR(k,i,j) sum+=x[k]; zz.PB(sum); } sort(zz.rbegin(),zz.rend()); REPSZ(i,zz) printf("%lld\n",zz[i]);
	sumx[0]=0; REP(i,n) sumx[i+1]=sumx[i]+x[i];
	nsums=0; REPE(i,n) allsums[nsums++]=sumx[i]; sort(allsums,allsums+nsums); nsums=unique(allsums,allsums+nsums)-allsums;
	REPE(i,n) sumidx[i]=lower_bound(allsums,allsums+nsums,sumx[i])-allsums;

	//REPE(i,n) printf("%lld %d\n",sumx[i],sumidx[i]);

	ll nfixed=max(0LL,want-n);
	ll mn=calc_nth(want-1),mx=calc_nth(nfixed);
	ll nmxfix=nfixed-cntatleast(mx+1);
	ll nmndyn=want-cntatleast(mn+1)-(mn==mx?nmxfix:0);
	//printf("%lld fixed, dyn: %lld..%lld (%lld of mn, %lld not of max)\n",nfixed,mn,mx,nmndyn,nmxfix);

	ll sumfix=process(mn,mx,nmndyn,nmxfix);
	//printf("sumfixed=%lld ndyn=%d\n",sumfix,ndyn);
	//REP(i,n) printf("%c",isfixed[i]?'*':'.'); puts("");
	//REP(i,ndyn) printf("%lld: %d..%d\n",dyn[i].val,dyn[i].a,dyn[i].b);

	set<int> uncovered; REP(i,n) if(!isfixed[i]) uncovered.insert(i);
	multiset<ll> use,avail; ll sumuse=0,mnpref=0,mnsuff=0;
	REP(i,n) seg[i]=-1;
	suminit();
	for(set<int>::iterator at=uncovered.begin();at!=uncovered.end();++at) {
		set<int>::iterator to=at; ++to;
		if(at==uncovered.begin()) mnpref=calcmnsum(0,*at);
		if(to==uncovered.end()) { mnsuff=sumx[n]-calcmxsum(*at+1,n); continue; }
		ll mnseg=calcmnseg(*at+1,*to-1);
		seg[*at]=mnseg; add1(use,avail,sumuse,mnseg);
		//printf("%d..%d = %lld\n",*at+1,*to,mnseg);
	}

	ll ret=LLONG_MIN,sumdyn=0;
	REPE(i,ndyn) {
		if(SZ(uncovered)==0&&i==ndyn) {
			ll cur=sumfix+sumdyn;
			//printf("cur=%lld\n",cur);
			if(cur>ret) ret=cur;
		}
		if(i<ndyn&&ndyn-i<=SZ(uncovered)) {
			int nuse=ndyn-i-1;
			while(SZ(use)>nuse) { multiset<ll>::iterator at=use.end(); --at; avail.insert(*at); sumuse-=*at; use.erase(at); }
			while(SZ(use)<nuse&&SZ(avail)>0) { multiset<ll>::iterator at=avail.begin(); use.insert(*at); sumuse+=*at; avail.erase(at); }
			assert(SZ(use)==nuse);
			ll cur=sumfix+sumdyn+(sumx[n]-mnpref-mnsuff-sumuse);
			//printf("cur=%lld\n",cur);
			if(cur>ret) ret=cur;
		}
		//printf("%d: rem=%d, uncovered=%d, mnpref=%lld, mnsuff=%lld, cntuse=%d, sumuse=%lld, cntav=%d\n",i,ndyn-i,SZ(uncovered),mnpref,mnsuff,SZ(use),sumuse,SZ(avail));
		if(i<ndyn) {
			sumdyn+=dyn[i].val;
			for(set<int>::iterator at=uncovered.lower_bound(dyn[i].a),tmp;at!=uncovered.end()&&*at<=dyn[i].b;tmp=at++,uncovered.erase(tmp)) {
				//printf("cover %d\n",*at);
				set<int>::iterator nxt=at; ++nxt;
				if(at==uncovered.begin()) {
					if(nxt!=uncovered.end()) {
						rem1(use,avail,sumuse,seg[*at]);
						seg[*at]=-1;
						mnpref=calcmnsum(0,*nxt);
					}
				} else if(nxt==uncovered.end()) {
					set<int>::iterator prv=at; --prv;
					rem1(use,avail,sumuse,seg[*prv]); 
					seg[*prv]=-1;
					mnsuff=sumx[n]-calcmxsum(*prv+1,n);
				} else {
					set<int>::iterator prv=at; --prv;
					rem1(use,avail,sumuse,seg[*prv]); 
					rem1(use,avail,sumuse,seg[*at]);
					ll mnseg=calcmnseg(*prv+1,*nxt-1);
					seg[*at]=-1; seg[*prv]=mnseg; add1(use,avail,sumuse,mnseg); //printf("->%lld\n",mnseg);
				}
			}
		}
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}
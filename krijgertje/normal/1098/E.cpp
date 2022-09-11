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

const int MAXN=50000;
const int MAXVAL=100000;

int n;
int a[MAXN];


int pmn[MAXVAL+1];
vector<int> who[MAXVAL+1]; // for powers of primes, all indexes that have that prime power as a divisor

vector<pair<int,int>> b;


vector<pair<int,int>> factorize(int x) {
	vector<pair<int,int>> ret; while(x>1) { int p=pmn[x],cnt=0; while(x%p==0) x/=p,++cnt; ret.PB(MP(p,cnt)); } return ret;
}
vector<int> getprimepowers(int x) {
	vector<pair<int,int>> factors=factorize(x); vector<int> ret; REPSZ(i,factors) { int cur=1; REP(j,factors[i].second) cur*=factors[i].first; ret.PB(cur); } return ret;
}

int findfirstmissing(const vector<int> &lst,int x) {
	int idx=lower_bound(lst.begin(),lst.end(),x)-lst.begin(); assert(idx<SZ(lst)&&lst[idx]==x);
	int l=0,r=SZ(lst)-idx; // max delta such that lst[idx+delta]==lst[idx]+delta 
	while(l+1<r) { int m=l+(r-l)/2; if(lst[idx+m]==lst[idx]+m) l=m; else r=m; }
	return lst[idx]+l+1;
}

ll bfcalc(ll lim) {
	int l=0,loff=0,r=0,roff=0; int cnt=0; ll sum=0,ret=0;
	while(l<SZ(b)) {
		while(r<SZ(b)) {
			if(roff>=b[r].second) { ++r,roff=0; continue; }
			if(sum+b[r].first>lim) break;
			++cnt; sum+=b[r].first; ++roff;
		}
		ret+=cnt;
		--cnt; sum-=b[l].first; ++loff; if(loff>=b[l].second) { ++l,loff=0; }
	}
	printf("bfcalc(%lld)=%lld\n",lim,ret);
	return ret;
}

ll calc1(int cnt,ll x) {
	return cnt*x;
}
ll calc2(int cnt,ll x) {
	return (ll)cnt*(x+x-cnt+1)/2;
}
ll calc3(int cnt,ll x,int a,int b) {
	//printf("calc3(%d,%lld,%d,%d)\n",cnt,x,a,b);
	assert(b!=0);
	ll ret=0;
	int adiv=a/b; a%=b; ret+=(ll)adiv*cnt*(cnt-1)/2;
	int xdiv=x/b; x%=b; ret+=(ll)xdiv*cnt;
	if(a==0) return ret;
	int zlim=(x+(cnt-1)*a+1)/b;
	ret+=(ll)zlim*(cnt-1)-calc3(zlim,b-x-1,b,a);
	return ret;
}

ll calc(ll lim) {
	int l=0,loff=0,r=0; int cnt=0; ll sum=0,ret=0;
	while(l<SZ(b)) {
		while(r<SZ(b)) {
			int rem=b[r].second-(l==r?loff:0);
			if(sum+(ll)rem*b[r].first>lim) break;
			cnt+=rem; sum+=(ll)rem*b[r].first; ++r;
		}
		int nloff=b[l].second;
		if(r<SZ(b)) {
			int rem=b[r].second-(l==r?loff:0);
			nloff=min((ll)nloff,loff+(sum+(ll)rem*b[r].first-lim+b[l].first-1)/b[l].first);
		}
		//printf("\tprocessing from %d, occ [%d..%d]",b[l].first,loff,nloff-1); if(r<SZ(b)) printf(", ending with possibly some %d (rem=%lld)",b[r].first,lim-sum); puts("");
		if(l==r) {
			assert(cnt==0&&sum==0);
			//REP(i,nloff-loff) ret+=lim/b[r].first;
			ret+=calc1(nloff-loff,lim/b[r].first);
			loff=nloff; if(nloff>=b[l].second) ++l,loff=0,++r;
		} else {
			if(r==SZ(b)) {
				//REP(i,nloff-loff) ret+=cnt-i;
				ret+=calc2(nloff-loff,cnt);
			} else {
				//REP(i,nloff-loff) ret+=cnt-i+(lim-sum+i*b[l].first)/b[r].first;
				ret+=calc2(nloff-loff,cnt)+calc3(nloff-loff,lim-sum,b[l].first,b[r].first);
			}
			cnt-=nloff-loff; sum-=(ll)(nloff-loff)*b[l].first;
			loff=nloff; if(nloff>=b[l].second) ++l,loff=0;
		}
		//printf("\t\t%lld\n",ret);
	}

	//ll chk=bfcalc(lim); printf("ret=%lld chk=%lld\n",ret,chk); assert(chk==ret);
	return ret;
}

ll solve() {
	memset(pmn,-1,sizeof(pmn)); FORE(i,2,MAXVAL) if(pmn[i]==-1) { for(int j=i;j<=MAXVAL;j+=i) if(pmn[j]==-1) pmn[j]=i; }
	FORE(i,2,MAXVAL) who[i].clear(); REP(i,n) { vector<pair<int,int>> cur=factorize(a[i]); REPSZ(j,cur) { int val=1; FORE(k,1,cur[j].second) { val*=cur[j].first; who[val].PB(i); } } }
	//FORE(i,2,MAXVAL) if(SZ(who[i])!=0) { printf("who%d:",i); REPSZ(j,who[i]) printf(" %d",who[i][j]); puts(""); }

	b.clear();
	REP(i,n) {
		int g=0,at=i;
		while(at<n) {
			g=gcd(g,a[at]);
			vector<int> cur=getprimepowers(g);
			int to=n; REPSZ(j,cur) { int pp=cur[j]; to=min(to,findfirstmissing(who[pp],at)); }
			//printf("[%d..%d) gcd=%d\n",at,to,g);
			b.PB(MP(g,to-at));
			at=to;
		}
	}
	{ sort(b.begin(),b.end()); int nb=0; REPSZ(i,b) if(i!=0&&b[i].first==b[nb-1].first) b[nb-1].second+=b[i].second; else b[nb++]=b[i]; b.resize(nb); reverse(b.begin(),b.end()); }
	//printf("b:"); REPSZ(i,b) printf(" %d*%d",b[i].second,b[i].first); puts("");

	int bcnt=0; ll bsum=0; REPSZ(i,b) bcnt+=b[i].second,bsum+=(ll)b[i].second*b[i].first;
	ll ccnt=(ll)bcnt*(bcnt+1)/2;
	ll need=(ccnt+1)/2;
	ll lo=0,hi=bsum;
	while(lo+1<hi) {
		ll mi=lo+(hi-lo)/2;
		ll have=calc(mi);
		if(have>=need) hi=mi; else lo=mi;
	}
	return hi;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	printf("%lld\n",solve());
}

void stress() {
	FOR(cnt,1,50) FORE(b,1,50) FORE(a,1,50) REPE(x,2*b) {
		//if(cnt!=2||a!=1||b!=3||x!=2) continue;
		ll want=0; REP(i,cnt) want+=(x+i*a)/b;
		ll have=calc3(cnt,x,a,b);
		if(have==want) { if(x==2*b-1) printf("."); continue; }
		printf("have=%lld want=%lld\n",have,want);
		printf("cnt=%d a=%d b=%d x=%d\n",cnt,a,b,x); exit(0);
	}


	/*REPE(z,10) FORE(a,1,50) FORE(b,1,50) if(gcd(a,b)==1) REPE(x,2*b) {
		//sum(k=z*b..z*b+b-1,floor((x+k*a)/b))=sum(k=z*b..z*b+b-1,(x+k*a))/b-(b-1)/2=((x+z*b*a)+(x+(z*b+b-1)*a))/2-(b-1)/2=x+a*z*b
		ll want=0; FORE(k,z*b,z*b+b-1) want+=(x+k*a)/b;
		//ll have=0; FORE(k,z*b,z*b+b-1) have+=x+k*a; have-=b*(b-1)/2; assert(have%b==0); have/=b;
		//ll have=0; have+=b*((x+z*b*a)+(x+(z*b+b-1)*a))/2; have-=b*(b-1)/2; assert(have%b==0); have/=b;
		ll have=x+z*b*a+(a-1)*(b-1)/2;

		//sum(k=z*b..z*b+b-1,(x+k*a)/b-floor((x+k*a)/b))=sum(k=0..b-1,k)/b=b*(0+b-1)/2/b=(b-1)/2
		//ll want=0; FORE(k,z*b,z*b+b-1) want+=(x+k*a)%b;
		//ll have=b*(b-1)/2;


		if(have==want) { if(x==2*b-1) printf("."); continue; }
		printf("have=%lld want=%lld\n",have,want);
		printf("z=%d a=%d b=%d x=%d\n",z,a,b,x); exit(0);
	}*/
}

int main() {
	run();
	//stress();
	return 0;
}
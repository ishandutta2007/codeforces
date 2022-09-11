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

ll n,l,r,k;

ll solve() {
	if(l==r&&k<=2) return n;
	ll ret=-1;
	ll last=l<=r?r-l:n+r-l;
	FORE(bfin,1,2) if(bfin<=k) REP(nb,2) {
		if(bfin==2&&nb==0) continue;
		// max na+nb+nc s.t. nfull*(n+na+nb+nc)+(last+na)=k-bfin, nfull>=0, 0<=na<=last, 0<=nc<=n-last-1
		if(k/n<n) {
			// suppose we know nfull, then (na+nc)*nfull+na=k-bfin-nfull*n-nfull*nb-last, (na+nc)<=na+n-last-1
			for(ll nfull=0;;++nfull) {
				ll rhs=k-bfin-nfull*(n+nb)-last; if(rhs<0) break;
				if(nfull==0) {
					if(rhs<=last) { ll na=rhs,nc=n-last-1; ret=max(ret,na+nb+nc); }
				} else {
					ll nac=min(n-1,rhs/nfull),na=rhs-nac*nfull; if(nac<na||na>last) continue;
					// 0<=(nac-x)-(na+x*nfull)<=n-last-1, na+x*nfull<=last
					// x<=(nac-na)/(nfull+1), x<=(last-na)/nfull, x>=(nac-na-(n-last-1))/(nfull+1)
					ll xmn=nac-na-(n-last-1)<0?0:(nac-na-(n-last-1)+nfull)/(nfull+1),xmx=min((nac-na)/(nfull+1),(last-na)/nfull);
					if(xmn<=xmx) ret=max(ret,nac-xmn+nb);
				}
			}
		} else {
			// suppose we know nac=na+nc, then nfull=floor((k-bfin-last)/(n+na+nb+nc)), na=k-bfin-nfull*(n+na+nb+nc)-last
			for(ll nac=0;nac<=n-1;++nac) {
				ll nfull=(k-bfin-last)/(n+nac+nb);
				ll na=k-bfin-nfull*(n+nac+nb)-last,nc=nac-na;
				if(0<=na&&na<=last&&0<=nc&&nc<=n-last-1) ret=max(ret,nac+nb);
			}
		}
	}
	return ret;
}

void run() {
	scanf("%lld%lld%lld%lld",&n,&l,&r,&k);
	printf("%lld\n",solve());
}

void stress() {
	for(n=1;n<=16;++n) {
		for(k=1;k<=1000;++k) {
			vector<ll> ans(n,-1);
			REP(mask,1<<n) {
				ll each=n; REP(i,n) if(mask&(1<<i)) ++each;
				ll rem=k%each; if(rem==0) rem=each;
				REP(i,n) { ll cur=min(rem,mask&(1<<i)?2LL:1LL); rem-=cur; if(rem==0) { ans[i]=max(ans[i],each-n); break; } } assert(rem==0);
			}
			for(l=1,r=1;r<=n;++r) {
				ll have=solve(),want=ans[r-1];
				if(have==want) { printf("."); continue; }
				printf("err\n"); 
				printf("n=%lld k=%lld l=%lld r=%lld have=%lld want=%lld\n",n,k,l,r,have,want);
				exit(0);
			}
		}
	}
}

int main() {
	run();
	//stress();
	return 0;
}
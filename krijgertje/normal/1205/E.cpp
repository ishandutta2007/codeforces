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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
const int MOD=1000000007;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void dec(int &a,int b) { inc(a,MOD-b); }
int twice(int a) { if((a*=2)>=MOD) a-=MOD; return a; }
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
int inv(int x) { assert(x!=0); return pw(x,MOD-2); }

int n,alph;

int invalphpw[MAXN+1];

int par[MAXN],sz[MAXN];
int find(int a) { if(par[a]==a) return a; return par[a]=find(par[a]); }
void unite(int a,int b) { a=find(a),b=find(b); if(a==b) return; if(sz[a]<sz[b]) swap(a,b); par[b]=a,sz[a]+=sz[b]; }


int calc(int len) {
	//REP(i,n) par[i]=i,sz[i]=1;
	//REP(i,len) unite(i,n-len+i);
	//int cnt=0; REP(i,n) if(par[i]==i) ++cnt;
	int cnt=n-len;
	return invalphpw[n-cnt];
}
int calc(int len1,int len2) {
	//REP(i,n) par[i]=i,sz[i]=1;
	//REP(i,len1) unite(i,n-len1+i);
	//REP(i,len2) unite(i,n-len2+i);
	//int cnt=0; REP(i,n) if(par[i]==i) ++cnt;
	int per1=n-len1,per2=n-len2,g=gcd(per1,per2);
	int cnt=max(g,per1+per2-n);
	return invalphpw[n-cnt];
}

int pmn[MAXN+1];
int mu[MAXN+1];


int solve() {
	invalphpw[0]=1; invalphpw[1]=inv(alph); FORE(i,2,n) invalphpw[i]=(ll)invalphpw[i-1]*invalphpw[1]%MOD;
	int ret=0;

	//int chk=0;
	//FORE(len1,1,n-1) FORE(len2,1,len1-1) inc(chk,twice(calc(len1,len2)));

	REPE(i,n) pmn[i]=-1;
	FORE(i,2,n) if(pmn[i]==-1) for(int j=i;j<=n;j+=i) if(pmn[j]==-1) pmn[j]=i;
	mu[1]=1; FORE(i,2,n) { int j=i/pmn[i]; mu[i]=pmn[j]==pmn[i]?0:-mu[j]; }

	FORE(d,1,n) if(mu[d]!=0) FORE(g,1,n/d) FORE(w,1,2*(n/(g*d))) {
		int prob=invalphpw[n-max(g,w*d*g-n)];
		//int chk=0; FOR(u,1,(n+g*d-1)/(g*d)) FOR(v,u+1,(n+g*d-1)/(g*d)) if(u+v==w) ++chk;
		int l=1,h=(n-1)/(g*d),cnt=0,ol=l,oh=h;
		if(l==h||l+l+1>w||h+h-1<w) continue;
		if(l+h<w) { int diff=w-(l+h); l+=diff; }
		if(l+h>w) { int diff=l+h-w; h-=diff; }
		{ assert(l+h==w); assert(l<=h); int diff=h-l; cnt+=(diff+1)/2; }
		//if(cnt!=chk) printf("l=%d h=%d w=%d -> cnt=%d chk=%d\n",ol,oh,w,cnt,chk);

		int cur=(ll)2*prob*cnt%MOD;
		//printf("d=%d mu=%d g=%d w=%d cnt=%d z=%d\n",d,mu[d],g,w,cnt,max(g,w*d*g-n));
		if(mu[d]==+1) inc(ret,cur); else if(mu[d]==-1) dec(ret,cur); else assert(false);

	}

	//printf("%d vs %d\n",ret,chk);


	FORE(len,1,n-1) inc(ret,calc(len));


	return ret;
}

void run() {
	scanf("%d%d",&n,&alph);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
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

const int MAXN=1000000;
const int MAXBIT=17;
const int MOD=1000000007;

int n;
int arr[MAXN];

int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
int inv(int x) { return pw(x,MOD-2); }
void fwht(ll *a,bool iv) {
	REP(i,1<<MAXBIT) { a[i]%=MOD; if(a[i]<0) a[i]+=MOD; }
	for(int len=1;len<(1<<MAXBIT);len*=2) {
		for(int i=0;i<(1<<MAXBIT);i+=2*len) {
			REP(j,len) {
				ll u=a[i+j],v=a[i+len+j];
				ll x=u+v; if(x>=MOD) x-=MOD; ll y=u-v; if(y<0) y+=MOD;
				a[i+j]=x; a[i+len+j]=y;
			}
		}
	}
	if(iv) { int mlt=inv(1<<MAXBIT); REP(i,1<<MAXBIT) a[i]=a[i]*mlt%MOD; }
}

int f[1<<MAXBIT];
void calcsum(ll *a,int *b) {
	REP(i,1<<MAXBIT) { a[i]%=MOD; if(a[i]<0) a[i]+=MOD; }
	REP(i,1<<MAXBIT) b[i]=a[i]*f[i]%MOD;
	REP(i,MAXBIT) REP(j,1<<MAXBIT) if((j&(1<<i))==0) b[j]=(b[j]+b[j^(1<<i)])%MOD;
}

void calcinvsum(int *a) {
	REP(i,MAXBIT) REP(j,1<<MAXBIT) if((j&(1<<i))==0) a[j]=(a[j]+MOD-a[j^(1<<i)])%MOD;
}


int cnt[1<<MAXBIT];
ll a[1<<MAXBIT];

ll cnt1[1<<MAXBIT];
ll cnt2[1<<MAXBIT];
ll cnt3[1<<MAXBIT];

int sum1[1<<MAXBIT];
int sum2[1<<MAXBIT];
int sum3[1<<MAXBIT];
int prod[1<<MAXBIT];



void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&arr[i]);
	memset(cnt,0,sizeof(cnt)); REP(i,n) ++cnt[arr[i]];

	REP(i,1<<MAXBIT) for(int j=0;j<(1<<MAXBIT);j=(j+i+1)&~i) cnt1[i|j]+=(ll)cnt[i]*cnt[j];
	REP(i,1<<MAXBIT) cnt2[i]=cnt[i];
	REP(i,1<<MAXBIT) a[i]=cnt[i];
	fwht(a,false);
	REP(i,1<<MAXBIT) a[i]=a[i]*a[i]%MOD;
	fwht(a,true);
	REP(i,1<<MAXBIT) cnt3[i]=a[i];
	//REP(i,1<<MAXBIT) if(cnt3[i]>0) printf("%x: %lld\n",i,cnt3[i]);

	f[0]=0,f[1]=1; FOR(i,2,1<<MAXBIT) f[i]=(f[i-2]+f[i-1])%MOD;
	calcsum(cnt1,sum1);
	calcsum(cnt2,sum2);
	calcsum(cnt3,sum3);
	//REP(i,1<<MAXBIT) if(cnt1[i]>0||cnt2[i]>0||cnt3[i]>0) printf("cnt %x: %lld %lld %lld\n",i,cnt1[i],cnt2[i],cnt3[i]);
	//REP(i,1<<MAXBIT) if(sum1[i]>0||sum2[i]>0||sum3[i]>0) printf("sum %x: %d %d %d\n",i,sum1[i],sum2[i],sum3[i]);
	REP(i,1<<MAXBIT) prod[i]=(ll)sum1[i]*sum2[i]%MOD*sum3[i]%MOD;
	calcinvsum(prod);
	//REP(i,1<<MAXBIT) if(sum3[i]>0) printf("%x: %d\n",i,prod[i]);
	int ret=0; REP(i,MAXBIT) ret=(ret+prod[1<<i])%MOD;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
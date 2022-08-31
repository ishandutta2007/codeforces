#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A)
#ifdef LOCAL
#define makel(A) scanf("%lld",&A)
#define pll(A) printf("%lld ",A)
#else
#define makel(A) scanf("%I64d",&A)
#define pll(A) printf("%I64d ",A)
#endif
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
#define MAX 100010
#define MAXX (1<<17)
int n,q,t[MAX],po[MAX],ko[MAX];
int pz[MAX],kz[MAX],sz[MAX];
PI d[MAX];
vector<int> zap[MAX];
struct node{
	int suf,cal,pref;
	bool czc;
	void scal(node a,node &b){
		czc = a.czc && b.czc;
		suf = b.czc?a.suf+b.cal:b.suf;
		pref = a.czc?a.cal+b.pref:a.pref;
		cal = max(max(a.suf+b.pref,a.cal),b.cal);
	}
	void zer(){
		suf = cal = pref = 0;
		czc = 0;
	};
	void jed(){
		suf = cal = pref = 1;
		czc = 1;
	};
}dp[MAXX*2],gl;
int nn,pk,kk;
void licz(int nr = 1,int pp = 0, int kp = nn-1){
	if(pk > kp || kk < pp) return;
	if(pk <= pp && kp <= kk){
		gl.scal(gl,dp[nr]);
		return;
	}
	licz(nr*2,pp,(pp+kp)/2);
	licz(nr*2+1,(pp+kp)/2+1,kp);
}
main(){
	make(n);
	nn=1;while(nn <= n)nn*=2;
	R(i,n){
		int pom;
		make(pom);
		d[i] = MP(pom,i);
	}
	sort(d,d+n,greater<PI>());
	//R(i,n)printf("%d ",d[i].SE);puts("");
	make(q);
	R(i,q){
		scanf("%d%d%d",&pz[i],&kz[i],&sz[i]);
		pz[i]--;
		kz[i]--;
		po[i] = -1;
		ko[i] = n-1;
	}
	while(1){
		bool x = 0;
		R(i,q){
			if(po[i] +1 != ko[i]){
				zap[po[i]+ko[i]>>1].PB(i);
				x = 1;
			}
		}
		if(x==0)break;
		R(i,nn*2)dp[i].zer();
		R(i,n){
			int ak = d[i].SE+nn;
			dp[ak].jed();
			while(ak>1){
				ak/=2;
				dp[ak].scal(dp[ak*2],dp[ak*2+1]);
			}
			R(j,zap[i].size()){
				int kt = zap[i][j];
				pk = pz[kt];
				kk = kz[kt];
				gl.zer();
				licz();
				if(gl.cal < sz[kt])
					po[kt] = i;
				else
					ko[kt] = i;
			}
			zap[i].clear();
		}
	}
	//R(i,q)printf("%d\n",ko[i]);puts("");
	R(i,q)printf("%d\n",d[ko[i]].FI);
}
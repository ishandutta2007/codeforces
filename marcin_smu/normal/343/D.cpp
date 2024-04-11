#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
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
#define makel(A) scanf("%I64d",&A)
#define pll(A) printf("%I64d ",A)
//#define makel(A) scanf("%lld",&A)
//#define pll(A) printf("%lld ",A)
#define MAX 500001
int n,p[MAX],k[MAX],ip;
vector<int> d[MAX];
void dfs(int nr,int o){
	p[nr] = ip;
	ip++;
	R(i,d[nr].size()){
		int ak=d[nr][i];
		if(ak!=o)dfs(ak,nr);
	}
	k[nr] = ip-1;
}
#define MAX2 (1<<19)
int dp[MAX2*2],dp2[MAX2*2];
int pk,kk,nn,gl;
void add(int nr=1,int pp=0,int kp=nn-1){
	if(pp > kk || kp < pk)return;
	if(pk <= pp && kp <= kk){
		dp[nr]=gl;
		return;
	}
	add(nr*2,pp,(pp+kp)/2);
	add(nr*2+1,(pp+kp)/2+1,kp);
}
int ma(int nr=1,int pp=0,int kp=nn-1){
	if(pp > kk || kp < pk)return 0;
	if(pk <= pp && kp <= kk)
		return dp2[nr];
	return max(
		ma(nr*2,pp,(pp+kp)/2),
		ma(nr*2+1,(pp+kp)/2+1,kp)
	);
}
main(){
	make(n);
	nn=1;while(nn<=n)nn*=2;
	R(i,n-1){
		int a,b;
		make(a);make(b);a--;b--;
		d[a].PB(b);
		d[b].PB(a);
	}
	dfs(0,-1);
	int q;
	make(q);
	F(i,1,q+1){
		int c,kt;
		make(c);make(kt);kt--;
		if(c==1){
			pk = p[kt];
			kk = k[kt];
			gl = i;
			add();
		}
		if(c==2){
			int ak = p[kt]+nn;
			while(ak){
				dp2[ak] = i;
				ak/=2;
			}
		}
		if(c==3){
			int war = 0;
			int ak = p[kt]+nn;
			while(ak){
				if(war < dp[ak])war =dp[ak];
				ak/=2;
			}
			pk = p[kt];
			kk = k[kt];
			int war2 = ma();
			printf("%d\n",int (war > war2));
		}
	}
}
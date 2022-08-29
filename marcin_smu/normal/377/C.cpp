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
#define MAX 101
const int INF = 1000 * 1001 * 1001;
int n,t[MAX];
int q(int a,int b){
	return a>b;
}
int wyn[(1<<20)+1];
vector<PI> ban;
vector<int> zb;
main(){
	make(n);
	R(i,n)make(t[i]);
	sort(t,t+n,q);
	//R(i,n)printf("%d ",t[i]);puts("");
	make(n);
	R(i,n){
		char z;int kt;
		scanf(" %c%d",&z,&kt);
		if(z=='b')
			ban.PB(MP(int(zb.size()),kt));
		else
			zb.PB(kt);
	}
	R(kt,(1<<n)){
	//	printf("%d\n",kt);
		int il = __builtin_popcount(kt);
		if(il < zb.size())continue;
		if(il == zb.size()){
			int pom = kt;
			int i=0;
			wyn[kt] = 0;
			while(pom){
				int ak = __builtin_ctz(pom);
	//			printf("%d %d %d\n",ak,zb[i],t[ak]);
				wyn[kt] += t[ak]*(zb[i]==1?1:-1);
				i++;
				pom-=(1<<ak);
			}
		}else{
			int ktban = n-il;
			int mn = (ban[ktban].SE==1?1:-1);
			int pom = kt;
			int i=0;
			wyn[kt] = INF * -mn;
			//printf("ktban %d\n",ktban);
			int odj = ban[ktban].FI;
			while(pom){
				int ak = __builtin_ctz(pom);
				if(odj){
					odj--;
				}else{
					if(ban[ktban].SE == 1)
						wyn[kt] = max(wyn[kt], wyn[kt - (1<<ak)]);
					else
						wyn[kt] = min(wyn[kt], wyn[kt - (1<<ak)]);
				}
				pom-=(1<<ak);
			}
		}
		//printf("      wyn %d = %d\n",kt,wyn[kt]);
	}
	printf("%d\n",wyn[(1<<n)-1]);
}
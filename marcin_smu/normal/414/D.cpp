#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
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
#define MAX 100001
int m,k,p,gl[MAX];
vector<int> d[MAX];
void dfs(int nr,int o,int g){
	gl[g]++;
	R(i,d[nr].size()){
		int ak = d[nr][i];
		if(ak!=o)dfs(ak,nr,g+1);
	}
}
main(){
	make(m);make(k);make(p);
	R(i,m-1){
		int a,b;
		make(a);make(b);
		a--;b--;
		d[a].PB(b);
		d[b].PB(a);
	}
	dfs(0,-1,0);
	int mam=0,wyn = 0,j=m-1;
	gl[0] = 0;
	for(int i=m-1;i>0;i--){
		while(j>0 && gl[j] * LL(i-j) <= p){
			p-=gl[j] * LL(i-j);
			mam += gl[j];
			j--;
		}
		int pom = mam;
		if(j!=0) pom += p/(i-j);
		if(pom > wyn)wyn = pom;
		mam -= gl[i];
		p += mam;
	}
	printf("%d\n",min(k,wyn));
}
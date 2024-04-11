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
#define MAX 100001
vector<int> d[MAX];
int n,m;
int wyn[MAX];
bool cz2[MAX];
bool cz(int a,int b){
	if(a==b)return 0;
	R(i,d[a].size()){
		if(d[a][i] == b)return 0;
	}
	return 1;
}
void wys(){
	wyn[n]=wyn[0];
	R(i,m){
		printf("%d %d\n",wyn[i]+1,wyn[i+1]+1);
	}
	exit(0);
}
void licz(int kt,int pier){
	if(kt==n && n == m){
		if(cz(wyn[0],wyn[n-1]))
			wys();
		return;
	}
	if(kt==m+1){
		wys();
	}
	for(int i=pier;i<n;i++){
		if(cz(wyn[kt-1],i)&& cz2[i] == 0){
			cz2[i]=1;
			wyn[kt]=i;
			int pom=pier;
			while(cz2[pom])pom++;
			licz(kt+1,pom);
			cz2[i]=0;
		}
	}
}
main(){
	make(n);
	make(m);
	for(int i=0;i<m;i++){
		int a,b;
		make(a);make(b);
		a--;b--;
		d[a].PB(b);
		d[b].PB(a);
	}
	for(int i=0;i<n;i++){
		wyn[0]=i;
		cz2[i]=1;
		licz(1,0);
		cz2[i]=0;
	}
	printf("-1\n");
}
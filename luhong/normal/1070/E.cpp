#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
typedef long long LL;

int N,M,LgN,Ans1; LL T,Ans2;
LL A[200005]; int P[200005];
inline bool cmp(int i,int j){return A[i]<A[j];}

LL b1[200005],b2[200005];
inline void Add(LL*b,int i,LL x){for(;i<=N;i+=i&-i)b[i]+=x;}
inline LL Qur(LL*b,int i){LL A=0;for(;i;i-=i&-i)A+=b[i];return A;}
inline void Add(int id){Add(b1,id,A[id]);Add(b2,id,1LL);}
inline int LB(LL*b,LL x){
	int pos=0;
	for(int j=LgN;j;j>>=1) if(pos+j<=N&&b[pos+j]<=x) pos+=j, x-=b[pos];
	return pos;
}

int main(){
	int Te; scanf("%d",&Te);
	while(Te--){
		// Read
		scanf("%d%d%lld",&N,&M,&T); LgN=1<<(31-__builtin_clz(N));
		F(i,1,N) scanf("%lld",A+i), P[i]=i;
		// Memset
		F(i,1,N) b1[i]=b2[i]=0;
		Ans1=0, Ans2=1LL;
		// Sort
		sort(P+1,P+N+1,cmp);
		// Solve
		F(i,1,N){
			if(A[P[i]]>T) break;
//			puts("==========");
			Add(P[i]);
			while(i<N&&A[P[i+1]]==A[P[i]]) Add(P[++i]);
			int Pos=LB(b1,T/2);
			int Pir=Qur(b2,Pos)/M*M;
			int NPos=LB(b2,Pir);
			LL Used=Qur(b1,NPos);
			int TotPos=LB(b1,T-Used);
			int TotNum=min((LL)Pir+M,Qur(b2,TotPos));
			if(TotNum>=Ans1) Ans1=TotNum, Ans2=A[P[i]];
//			printf(" Pos = %d , T = %lld\n",Pos,T);
//			printf(" Pir = %d\n",Pir);
//			printf(" NPos = %d\n",NPos);
//			printf(" Used = %lld\n",Used);
//			printf(" TotPos = %d\n",TotPos);
//			printf(" TotNum = %d\n",TotNum);
//			puts("==========");
		}
		printf("%d %lld\n",Ans1,Ans2);
	}
	return 0;
}
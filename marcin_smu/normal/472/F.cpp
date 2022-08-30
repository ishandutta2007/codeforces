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
#define MAX 10001
int n,x[MAX],y[MAX],z[31];
vector<PI> wyn,wyn2;
bool faza = 0;
void add(int a,int b){
	//printf("add %d: %d %d\n",faza,a,b);
	if(faza == 0)
		wyn.PB(MP(a,b));
	else
		wyn2.PB(MP(a,b));
}
void swa(int a,int b){
	if(a==b)return;
	add(a,b);add(b,a);add(a,b);
}
int gauss(int *x,int n){
	int pom = (1<<30),il = 0;
	while(pom){
		int ost = -1;
		F(i,il,n)if(x[i] >= pom){
			ost = i;
			break;
		}
		if(ost!=-1){
			swa(il,ost);
			swap(x[il],x[ost]);
			R(i,n){
				if(i!=il && (x[i] & pom)){
					add(i,il);
					x[i]^=x[il];
				}
			}
			il++;
		}
		pom/=2;
	}
	return il;
}
void nie(){
	puts("-1");
	exit(0);
}
main(){
	make(n);
	R(i,n)make(x[i]);
	int il = gauss(x,n);
	R(i,n)make(y[i]);
	F(i,il,n){
		R(j,il){
			if((x[j]^y[i]) < y[i]){
				y[i]^=x[j];
				add(i,j);
			}
		}
		if(y[i]!=0)nie();
	}
	R(i,il){
		R(j,il){
			if((x[j]^y[i]) < y[i]){
				y[i]^=x[j];
				z[i]^=(1<<(il-j-1));
			}
		}
		if(y[i]!=0)nie();
	}
	faza = 1;
	gauss(z,il);
	faza = 0;
	
	R(i,il){
		R(j,i+1){
			if(((z[j]&(1<<(il-i-1)))!=0)  ^ (i==j)){
				//printf("%d %d %d %d\n",z[j],1<<(il-i-1),i,j);
				add(j,i);
			}
		}
	}
	printf("%d\n",wyn.size()+wyn2.size());
	R(i,wyn.size())printf("%d %d\n",wyn[i].FI+1,wyn[i].SE+1);
	//puts("");
	FD(i,(int)wyn2.size())printf("%d %d\n",wyn2[i].FI+1,wyn2[i].SE+1);
}
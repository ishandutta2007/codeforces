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
#define MAX 100100
int n,q,po,ko,dp[MAX],war[MAX];
bool odw;
void add(int nr,int il){
	for(;nr<=n;nr+=(nr&-nr))
		dp[nr] += il;
}
int sum(int nr){
	int wyn = 0;
	for(;nr;nr -= (nr&-nr))
		wyn += dp[nr];
	return wyn;
}
main(){
	make(n);make(q);
	po = 1;
	ko = n+1;
	F(i,1,n+1){
		war[i] = 1;
		add(i,1);
	}
	while(q--){
	//	printf("  %d %d %d\n",po,ko,int(odw));
	//	F(i,po,ko)printf("%d ",war[i]);
	//	puts("");
		int z;make(z);
		if(z==1){
			int poz;make(poz);
			if(odw)poz = ko - po - poz;
			if(poz*2 <= ko - po){
				R(i,poz){
					int a = po + poz*2 - i -1;
					int b = po + i;
					war[a] += war[b];
					add(a,war[b]);
				}
				po += poz;
				if(odw)odw = 0;
			}else{
				poz = ko - po - poz;
				R(i,poz){
					int a = ko - poz*2 + i;
					int b = ko - i - 1;
					war[a] += war[b];
					add(a,war[b]);
				}
				ko -= poz;
				if(!odw)odw = 1;
			}
		}else{
			int l,p;
			make(l);make(p);
			if(odw){
				l = ko - po - l;
				p = ko - po - p;
				swap(l,p);
			}
		//	printf("%d %d\nwyn : ",l,p);
			printf("%d\n",sum(p+po-1) - sum(l+po-1));
		}
	}
}
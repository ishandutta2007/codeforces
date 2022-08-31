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
#define pll(A) printf("%lld\n",A)
#else
#define makel(A) scanf("%I64d",&A)
#define pll(A) printf("%I64d\n",A)
#endif
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
int n;
LL l,r;
main(){
	make(n);
	while(n--){
		makel(l);makel(r);
		int wyn = -1;
		LL k = -1;
		while(l <= r){
			int pom = __builtin_popcountll(l);
			if(wyn <= pom){
				wyn = pom;
				k = l;
			}
			l = l | (l+1);
		}
		pll(k);
	}
}
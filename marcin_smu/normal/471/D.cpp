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
#define MAX 201001
int n,k,tn[MAX],tk[MAX],t[MAX*2],knp[MAX*2];
main(){
	make(n);make(k);
	R(i,n)make(tn[i]);
	R(i,k)make(tk[i]);
	R(i,k)t[i] = tk[i+1] - tk[i];
	t[k-1] = 2e9;
	R(i,n)t[k+i] = tn[i+1] - tn[i];
	int w = 0;
	int wyn = 0;
	for(int i=1;i<k+n;i++){
		while(w!=0 && t[w] != t[i]) w = knp[w-1];
		if(t[w] == t[i])w++;
		knp[i] = w;
		if(w == k-1)wyn ++;
	}
	printf("%d\n",wyn);
}
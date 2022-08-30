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
#define MAX 101
char z[] = "qwertyuiopasdfghjkl;zxcvbnm,./";
char a;
char p[MAX];
main(){
	scanf(" %c%s",&a,p);
	
	for(int i=0;p[i];i++){
		int j=0;
		while(1){
			if(z[j] == p[i]){
				p[i] = z[j + (a == 'R'?-1:1)];
				break;
			}
			j++;
		}
	}
	printf("%s\n",p);
}
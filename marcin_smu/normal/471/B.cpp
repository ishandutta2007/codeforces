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
#define MAX 2001
int n,t[MAX],p[MAX];
bool q(int a,int b){
	return t[a] < t[b];
}
void pr(){
	R(i,n)printf("%d ",p[i]+1);
	puts("");
}
main(){
	int il = 0;
	make(n);
	R(i,n){
		make(t[i]);
		p[i]=i;
	}
	sort(p,p+n,q);
	R(i,n-1)
		if(t[p[i]] == t[p[i+1]]){
			il++;
	}
	if(il<2){
		puts("NO");
	}else{
		puts("YES");
		pr();
		il = 0;
		R(i,n-1){
			if(t[p[i]] == t[p[i+1]]){
				il++;
				swap(p[i],p[i+1]);
				pr();
				if(il == 2)return 0;
			}
		}
	}
}
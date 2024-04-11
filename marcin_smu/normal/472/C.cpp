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
#define MAX 100001
int n,p[MAX];
bool cmp(char *a,char *b){
	int i=0;
	while(1){
		if(a[i] != b[i])return a[i] < b[i];
		i++;
	}
}
struct osoba{
	char a[51],b[51];
	bool cza,czb;
	bool czm(osoba& pom){
		cza = 1;
		czb = 1;
		if(!pom.cza){
			if(cmp(pom.a,a))cza = 0;
			if(cmp(pom.a,b))czb = 0;
		}
		if(!pom.czb){
			if(cmp(pom.b,a))cza = 0;
			if(cmp(pom.b,b))czb = 0;
		}
		return cza & czb;
	}
}t[MAX];
main(){
	make(n);
	R(i,n)scanf("%s%s",t[i].a,t[i].b);
	R(i,n)make(p[i]);
	R(i,n-1){
		if(t[p[i+1]-1].czm(t[p[i]-1])){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}
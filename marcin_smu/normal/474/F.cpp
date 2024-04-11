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
int n,kmr[21][MAX];
vector<int> gd[MAX];
map<int,int> mapa;
int szu(vector<int> &a,int b){
	int p = -1,k = a.size();
	while(p+1!=k){
		int m = p+k >>1;
		if(a[m] < b)
			p = m;
		else
			k = m;
	}
	return k;
}
main(){
	make(n);
	int il = 0;
	R(i,n){
		int pom;
		make(pom);
		kmr[0][i] = pom;
		if(mapa[pom] == 0){
			il++;
			mapa[pom] = il;
		}
		gd[mapa[pom]].PB(i);
	}
	int sze = 1, j = 1;
	while(sze*2 <= n){
		R(i,n-sze)kmr[j][i] = __gcd(kmr[j-1][i],kmr[j-1][i+sze]);
		sze*=2;
		j++;
	}
	int t;make(t);while(t--){
		int r,l;
		make(l);make(r);
		int wyn = r-l+1;
		int j = 0;while((1<<j) <= wyn)j++;j--;
		int a = __gcd(kmr[j][l-1],kmr[j][r-(1<<j)]);
		int pom = mapa[a];
		if(pom)wyn -= szu(gd[pom],r) - szu(gd[pom],l-1);
		printf("%d\n",wyn);
	}
}
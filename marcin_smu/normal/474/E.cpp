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
#define MAX 101000
int n,d,p[MAX],r[MAX];
LL h[MAX],h2[MAX],h3[MAX];
bool q(int a,int b){
	return h[a] < h[b];
}
struct{
	int dp[MAX];
	void add(int a,int il){
		a++;
		for(;a<=n;a+=a&-a)
			ma(dp[a],il);
	}
	int mxx(int a){
		a++;
		int res = 0;
		for(;a;a-=a&-a)
			ma(res,dp[a]);
		return res;
	}
}ft[2];
int szu(LL *a,LL b){
	int p = -1,k = n;
	while(p+1!=k){
		int m = p+k >>1;
		if(a[m] <= b)
			p = m;
		else
			k = m;
	}
	return k;
}
int w[MAX];
main(){
	make(n);make(d);
	R(i,n){
		makel(h[i]);
		h2[i] = h[i];
		h3[i] = -h[i];
		p[i] = i;
	}
	sort(p,p+n,q);
	sort(h2,h2+n);
	sort(h3,h3+n);
	R(i,n)r[p[i]] = i;
	int wyn = 0,os = 0;
	R(i,n){
		int pom = max(
			ft[0].mxx(szu(h2,h[i]-d)-1),
			ft[1].mxx(szu(h3,-h[i]-d)-1)
		)+1;
		ma(wyn,pom);
		w[i] = pom;
		//printf("%d\n",pom);
		if(wyn == pom)os = i;
		ft[0].add(r[i],pom);
		ft[1].add(n-r[i]-1,pom);
	}
	printf("%d\n",wyn);
	vector<int> wyny;
	while(wyn --){
		wyny.PB(os+1);
		LL pom = h[os];
		if(wyn)while(wyn != w[os] || abs(h[os]-pom) < d)os--;
	}
	FD(i,wyny.size()){
		printf("%d ",wyny[i]);
	}
	puts("");
}
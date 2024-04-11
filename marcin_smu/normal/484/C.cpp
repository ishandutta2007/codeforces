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
#define MAX 1000001
char *z,*z2;
char z_[MAX],z2_[MAX];
int n,k,d;
struct per{
	vector<int> p;
	per(int dl,int k){
		p.resize(dl);
		int il = 0;
		R(i,k)
			for(int j=0; j*k+i<dl;j++)
				p[j*k+i] = il++;
	}
	void add(per& b){
		int prze = p.size()-k+1;
		vector<int> &q = b.p;
		int dl = q.size() + prze;
		vector<int> wyn(dl);
		R(i,dl){
			int ak;
			if(i < p.size())
				ak = p[i];
			else
				ak = i;
			if(ak >= prze){
				ak = prze + q[ak-prze];
			}
			wyn[i] = ak;
		}
		swap(wyn,p);
	}
};
main(){
	z = z_;
	z2 = z2_;
	scanf("%s",z);
	while(z[n])n++;
	z2[n] = 0;
	int m;make(m);
	while(m--){
		make(k);make(d);
		per a(k,d),w(k,d);
		int wyk = n-k;
		while(wyk){
			if(wyk&1)w.add(a);
			wyk/=2;
			a.add(a);
		}
		R(i,n)z2[w.p[i]] = z[i];
		swap(z,z2);
		printf("%s\n",z);
	}
}
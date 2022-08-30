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
#define MAX2 401001
char s[MAX2],w[MAX2];
const int bl = (1<<14);
int q;
int wyn[MAX2];
vector<pair<int,PI> > zap[MAX2];
#define MAX (1<<18)
LL t[MAX*2],t2[MAX*2],t3[MAX*2],t4[MAX*2];
const unsigned P = 2013265921; //15*2^27+1
const unsigned gen = 440564289;//jakis generator w Zp
LL power(LL a,int w){
	LL ret=1;
	while(w){
		if(w&1){
			ret*=a;
			ret%=P;
		}
		w/=2;
		a*=a;
		a%=P;
	}
	return ret;
}
void FFT(LL *a,LL *b,LL x,int n){ // x ma rzad n
	if(n == 1){
		b[0] = a[0];
		return;
	}
	n>>=1;
	LL *ar = new LL[n];
	LL *b1 = new LL[n];
	LL *b2 = new LL[n];
	R(i,n)ar[i] = a[i*2]; 
	FFT(ar,b1,x*x%P,n);
	R(i,n)ar[i] = a[i*2+1]; 
	FFT(ar,b2,x*x%P,n);
	delete[] ar;
	LL xi = 1;
	R(i,n){
		b[i] = (b1[i] + b2[i] * xi) % P;
		xi = xi*x%P;
	}
	R(i,n){
		b[i+n] = (b1[i] + b2[i] * xi) % P;
		xi = xi*x%P;
	}
	delete[] b1;
	delete[] b2;
	if(xi != 1)exit(1);
}
int m,nn;
unsigned ss[32][MAX2/32],ww[32][MAX2/32];
void prebrut(){
	int i=0;while(s[i]){
		if(s[i] == '1'){
			R(j,32){
				if(i-j >= 0)
					ss[j][(i-j)>>5] ^= 1<<((i-j)&31);
			}
		}
		i++;
	}
	i=0;
	while(w[i]){
		if(w[i] == '1'){
			R(j,32){
				if(i-j >= 0)
					ww[j][(i-j)>>5] ^= 1<<((i-j)&31);
			}
		}
		i++;
	}
}

int brut2(unsigned *s,unsigned *w,int il,int os){
	int wyn = 0;
	R(i,il)wyn += __builtin_popcount(s[i]^w[i]);
	wyn += __builtin_popcount((s[il]^w[il])&((1<<os)-1));
	return wyn;
}

inline int brut(int a,int b,int il){
	int wyn = 0;
	wyn += brut2(ss[a&31]+(a>>5),ww[b&31]+(b>>5),il>>5,il&31);
	return wyn;
}


main(){
	scanf("%s%s",s,w);
	prebrut();
	make(q);
	R(i,q){
		int a,b,dl;
		make(a);make(b);make(dl);
		int dl2 = min((a+bl-1)/bl*bl-a,dl);
		wyn[i] += 2*brut(a,b,dl2);
		a+=dl2;
		b+=dl2;
		dl-=dl2;
		/*while(dl && a%bl!=0){
			wyn[i] += (s[a] ^ w[b]);
			a++;
			b++;
			dl--;
		}*/
		dl2 = dl%bl;
		wyn[i] += 2*brut(a+dl-dl2,b+dl-dl2,dl2);
		dl-=dl2;
		/*while(dl%bl!=0){
			wyn[i] += (s[a+dl-1] ^ w[b+dl-1]);
			dl--;
		}*/
		if(dl)zap[a/bl].PB(MP(i,MP(b,dl)));
		/*while(dl){
			zap[a/bl].PB(MP(i,b));
			dl-=bl;
			a+=bl;
			b+=bl;
		}*/
	}
//	R(i,q)printf("%d\n",wyn[i]);
	m = 0;while(w[m])m++;
	//if(m > 30)exit(0);
	nn = 1;while(nn <= m+bl)nn*=2;
	R(i,m)t[i] = (w[m-1-i] == '1' ? 1 : P-1);
	//R(i,m)printf("%lld ",t[i]);puts("");
	LL pom = power(gen, (1<<27)/ nn);
	FFT(t, t2, pom, nn);
	int n = 0;while(s[n])n++;
	unsigned p1 = power(nn,P-2), p2 =power(pom, nn-1) ;
	R(i,n/bl){
		R(j,nn)t3[j] = 0;
		R(j,bl)t3[j] = (s[i*bl + j] == '1' ? P-1 : 1);
		//R(j,bl)printf("%lld ",t3[j]);puts("");
		FFT(t3, t4, pom, nn);
		R(j,nn)t4[j]=t2[j]*t4[j]%P * p1%P;
		FFT(t4, t3, p2, nn);
		R(j,nn){
			t3[j]+=bl;
			if(t3[j] >= P)t3[j] -= P;
		}
		R(j,zap[i].size()){
			int gd = m-zap[i][j].SE.FI-1;
		//	printf("%d %d\n",zap[i][j].FI,gd);
			wyn[zap[i][j].FI] += t3[gd];
			zap[i][j].SE.SE -= bl;
			zap[i][j].SE.FI += bl;
			if(zap[i][j].SE.SE)
				zap[i+1].PB(zap[i][j]);
		}
		zap[i].clear();
		//R(j,m+bl)printf("%lld ",t3[j]);
		//puts("");
	}
	R(i,q)printf("%d\n",wyn[i]/2);
}
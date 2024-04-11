#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(b))
#define MOD 1000000007
using namespace std;
typedef long long ll;

int x[85][85],k;ll nn;int n;
int c[85][85];
int d[85];

void mmul(int r[85][85], int a[85][85], int b[85][85]){
	int t[85][85];
	mset(t,0);
	fore(i,0,n)fore(j,0,n)fore(k,0,n)t[i][j]+=1LL*a[i][k]*b[k][j]%MOD,t[i][j]%=MOD;
	mcopy(r,t);
}

void mexp(int r[85][85], int x[85][85], ll e){
	int a[85][85],t[85][85];
	memcpy(a,x,sizeof(a));
	mset(t,0);
	fore(i,0,n)t[i][i]=1;
	while(e){
		if(e&1)mmul(t,t,a);
		e>>=1;
		mmul(a,a,a);
	}
	mcopy(r,t);
}

int main(){
	fore(i,0,85){
		c[i][0]=c[i][i]=1;
		fore(j,1,i)c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
	}
	scanf("%lld%d",&nn,&k);n=2*k+3;
	x[2*k+2][2*k+2]=x[2*k+2][k]=1;
	fore(i,0,k+1){
		x[i+k+1][i]=1;
		mset(d,0);d[i]=1;
		for(int j=i;j>=0;--j){
			x[i][j]=d[j];int p=1;
			for(int l=j-1;l>=0;--l){
				p=(1LL*p*(MOD-1))%MOD;
				d[l]+=MOD-(1LL*p*c[j][l])%MOD*d[j]%MOD;d[l]%=MOD;
			}
		}
		mset(d,0);d[i]=1;
		for(int j=i;j>=0;--j){
			x[i][j+k+1]=d[j];int p=1;
			for(int l=j-1;l>=0;--l){
				p=(1LL*p*(MOD-2))%MOD;
				d[l]+=MOD-(1LL*p*c[j][l])%MOD*d[j]%MOD;d[l]%=MOD;
			}
		}
	}
	mexp(x,x,nn);
	int r=0;
	fore(i,0,k+2)r+=x[2*k+2][i],r%=MOD;
	printf("%d\n",r);
	return 0;
}
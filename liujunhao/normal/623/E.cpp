#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAXN 30000
#define MOD 1000000007
#define G 3
int mod[]={1004535809,998244353,104857601};
template<class T>
void Read(T &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
long long n;
int k,fac[MAXN+10],inv[MAXN+10],ta[MAXN+10],tb[MAXN+10],ret[MAXN+10],a[MAXN+10],ans,A[3][MAXN*3+10],B[3][MAXN*3+10];
int quick_pow(int a,int b){
	int ret(1);
	while(b){
		if(b&1)
			ret=1ll*ret*a%MOD;
		a=1ll*a*a%MOD;
		b>>=1;
	}
	return ret;
}
int quick_pow(int a,int b,int p){
    int ret(1);
    while(b){
        if(b&1)
            ret=1ll*ret*a%p;
        a=1ll*a*a%p;
        b>>=1;
    }
    return ret;
}
void ntt(int *a,int N,int f,int p){
    int i,j,k,t;
    for(i=1,j=0;i<N-1;i++){
        for(t=N;j^=t>>=1,~j&t;);
        if(i<j)
            swap(a[i],a[j]);
    }
    for(i=1;i<N;i<<=1){
        t=i<<1;
        int wn=quick_pow(G,(p-1)/t,p);
        for(j=0;j<N;j+=t){
            int w=1;
            for(k=0;k<i;k++,w=1ll*w*wn%p){
                int x=a[j+k],y=1ll*w*a[j+k+i]%p;
                a[j+k]=(x+y)%p,a[j+i+k]=(x-y+p)%p;
            }
        }
    }
    if(f==-1){
        reverse(a+1,a+N);
        int inv=quick_pow(N,p-2,p);
        for(i=0;i<N;i++)
            a[i]=1ll*a[i]*inv%p;
    }
}
long long quick_mul(long long a,long long b,long long p){
    long long ret(0);
    while(b){
        if(b&1)
            ret=(ret+a)%p;
        a=(a<<1)%p;
        b>>=1;
    }
    return ret;
}
void merge(int a[][MAXN*3+10],int *b,int N){
    int i;
    long long t=1ll*mod[0]*mod[1],r0=quick_pow(mod[0],mod[1]-2,mod[1]),r1=quick_pow(mod[1],mod[0]-2,mod[0]),t1,t2;
    for(i=0;i<N;i++){
        t1=(quick_mul(a[0][i]*r1%t,mod[1],t)+quick_mul(a[1][i]*r0%t,mod[0],t))%t;
        t2=quick_pow(t%mod[2],mod[2]-2,mod[2])*(((a[2][i]-t1)%mod[2]+mod[2])%mod[2])%mod[2];
        b[i]=(t2*(t%MOD)%MOD+t1)%MOD*fac[i]%MOD;
    }
}
void mul(int *a,int *b,int *c,int n){
	int i,N,j;
	for(i=0;i<n;i++)
		for(j=0;j<3;j++)
			A[j][i]=a[i]%mod[j],B[j][i]=b[i]%mod[j];
	for(N=1;N<n+n-1;N<<=1);
	for(i=n;i<N;i++)
		A[0][i]=A[1][i]=A[2][i]=B[0][i]=B[1][i]=B[2][i]=0;
	for(i=0;i<3;i++){
		ntt(A[i],N,1,mod[i]);
		ntt(B[i],N,1,mod[i]);
		for(j=0;j<N;j++)
			A[i][j]=1ll*A[i][j]*B[i][j]%mod[i];
		ntt(A[i],N,-1,mod[i]);
	}
	merge(A,c,n);
}
void calc(int *a,int *b,int left,int right){
	int i;
	for(i=0;i<=k;i++){
		ta[i]=1ll*a[i]*inv[i]%MOD*quick_pow(2,right*i)%MOD;
		tb[i]=1ll*b[i]*inv[i]%MOD;
	}
	mul(ta,tb,a,k+1);
}
void solve(int n){
	int left=0,right=1,i;
	for(i=1;i<=k;i++)
		a[i]=1;
	*ret=1;
	while(n){
		if(n&1){
			calc(ret,a,left,right);
			left+=right;
		}
		calc(a,a,right,right);
		right<<=1;
		n>>=1;
	}
	for(i=1;i<=k;i++)
		ans=(ans+1ll*ret[i]*fac[k]%MOD*inv[i]%MOD*inv[k-i])%MOD;
}
void prepare(){
	fac[0]=inv[0]=1;
	for(int i=1;i<=k;i++){
		fac[i]=1ll*fac[i-1]*i%MOD;
		inv[i]=quick_pow(fac[i],MOD-2);
	}
}
int main()
{
	Read(n),Read(k);
	prepare();
	if(n>k){
		puts("0");
		return 0;
	}
	solve(n);
	printf("%d\n",ans);
}
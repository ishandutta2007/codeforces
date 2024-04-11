#include<cstdio>
#include<algorithm>
#include<cmath>
#define MAXK 1000
#define G 3
#define MOD 7340033
using namespace std;
int f[40][MAXK+10],n,k,q,cnt,A[MAXK*6+10];
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF){
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
	}
}
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
void ntt(int *a,int N,int f){
	int i,j,t,k;
	for(i=1,j=0;i<N-1;i++){
		for(t=N;j^=t>>=1,~j&t;);
		if(i<j)
			swap(a[i],a[j]);
	}
	for(i=1;i<N;i<<=1){
		t=i<<1;
		int wn(quick_pow(G,(MOD-1)/t));
		for(j=0;j<N;j+=t){
			int w(1);
			for(k=0;k<i;k++,w=1ll*w*wn%MOD){
				int x(a[j+k]),y(1ll*w*a[j+k+i]%MOD);
				a[j+k]=(x+y)%MOD,a[j+k+i]=(x-y+MOD)%MOD;
			}
		}
	}
	if(f==-1){
		reverse(a+1,a+N);
		int inv=quick_pow(N,MOD-2);
		for(i=0;i<N;i++)
			a[i]=1ll*a[i]*inv%MOD;
	}
}
void prepare(){
	int i,N,j;
	for(N=1;N<4001;N<<=1);
	f[0][0]=1;
	for(i=0;i<30;i++){
		for(j=0;j<=MAXK;j++)
			A[j]=f[i][j];
		for(j=MAXK+1;j<N;j++)
			A[j]=0;
		ntt(A,N,1);
		for(j=0;j<N;j++)
			A[j]=1ll*A[j]*A[j]%MOD,A[j]=1ll*A[j]*A[j]%MOD;
		ntt(A,N,-1);
		for(j=1;j<=MAXK;j++)
			f[i+1][j]=A[j-1];
		f[i+1][0]=1;
	}
}
int main()
{
	prepare();
	Read(q);
	while(q--){
		Read(n),Read(k);
		int cnt=0;
		while((n&1)&&n>1)
			cnt++,n>>=1;
		printf("%d\n",f[cnt][k]);
	}
}
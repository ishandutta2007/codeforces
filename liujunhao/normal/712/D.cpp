#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXT 100
#define MAXK 1000
#define MOD 1000000007
using namespace std;
int a,b,k,t,jz,fac[MAXT*MAXK*4+1000],inv[MAXT*MAXK*4+1000],ans;
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
void prepare(){
	fac[0]=inv[0]=1;
	int i;
	for(i=1;i<=k*t*4+2*t;i++){
		fac[i]=1ll*fac[i-1]*i%MOD;
		inv[i]=quick_pow(fac[i],MOD-2);
	}
}
inline int C(int n,int m){
	return 1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int fz[MAXT*2+10],fm[MAXT*MAXK*4+10];
int main()
{
	Read(a),Read(b),Read(k),Read(t);
	jz=k*t;
	prepare();
	int l=2*k*t+b-a+1,r=4*k*t,i;
	if(l>r){
		puts("0");
		return 0;
	}
	for(i=0;i<=2*t;i++)
		fz[i]=(((i&1)?-1:1)*C(2*t,i)+MOD)%MOD;
	for(i=0;i<=4*k*t;i++)
		fm[i]=C(2*t-1+i+1,2*t);                          //
	for(i=0;i<=2*t;i++){
		int nl=l-(2*k+1)*i,nr=r-(2*k+1)*i;
		if(nr<0)
			break;
		if(nl<0)
			ans=(ans+1ll*fz[i]*fm[nr])%MOD;
		else
			ans=(ans+1ll*fz[i]*(fm[nr]-fm[nl-1]+MOD))%MOD;
	}
	printf("%d\n",ans);
}
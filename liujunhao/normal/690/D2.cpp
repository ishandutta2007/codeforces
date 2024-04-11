#include<cstdio>
#include<algorithm>
#define MOD 1000003
#define MAXN 500000
int n,c,fac[MAXN*2+10],ifac[MAXN*2+10],ans;
void Read(int &x){
	static char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
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
	int i;
	fac[0]=ifac[0]=1;
	for(i=1;i<=n+c;i++){
		fac[i]=1ll*fac[i-1]*i%MOD;
		ifac[i]=quick_pow(fac[i],MOD-2);
	}
}
int C(int n,int m){
	if(n<m)
		return 0;
	return 1ll*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
int main()
{
	Read(n),Read(c);
	prepare();
	int i;
	for(i=1;i<=n;i++)
		ans=(ans+C(i+c-1,c-1))%MOD;
	printf("%d\n",ans);
}
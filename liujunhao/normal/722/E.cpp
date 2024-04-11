#include<cstdio>
#include<algorithm>
#define MAXN 100000
#define MAXM 100000
#define MAXK 2000
#define MOD 1000000007
using namespace std;
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
typedef pair<int,int>pii;
int n,m,k,s,f[MAXK+10][21],fac[MAXN*2+10],inv[MAXN*2+10],ans;
pii a[MAXK+10];
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
void read(){
	Read(n),Read(m),Read(k),Read(s);
	int i;
	for(i=1;i<=k;i++)
		Read(a[i].first),Read(a[i].second);
	sort(a+1,a+k+1);
	fac[0]=inv[0]=1;
	for(i=1;i<=n+m;i++){
		fac[i]=1ll*fac[i-1]*i%MOD;
		inv[i]=quick_pow(fac[i],MOD-2);
	}
}
int C(int n,int m){
	return 1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
void solve(){
	int i,j,l,now;
	a[0]=pii(1,1);
	for(i=k;i>=0;i--){
		now=0;
		for(j=0;j<=20;j++){
			f[i][j]=C(n-a[i].first+m-a[i].second,n-a[i].first);
			for(l=i+1;l<=k;l++)
				if(a[l].first-a[i].first>=0&&a[l].second-a[i].second>=0)
					f[i][j]=(f[i][j]-1ll*C(a[l].first-a[i].first+a[l].second-a[i].second,a[l].first-a[i].first)*f[l][j])%MOD;
			f[i][j]=((f[i][j]-now)%MOD+MOD)%MOD;
			now=(now+f[i][j])%MOD;
		}
	}
}
void print(){
	int i,now=s,tot=0;
	for(i=0;i<=20;i++){
		ans=(ans+1ll*now*f[0][i])%MOD;
		tot=(tot+f[0][i])%MOD;
		(++now)>>=1;
	}
	ans=(1ll*(ans+(C(n-1+m-1,n-1)-tot))*quick_pow(C(n-1+m-1,n-1),MOD-2)%MOD+MOD)%MOD;
	printf("%d\n",ans);
}
int main()

{
	read();
	solve();
	print();
}
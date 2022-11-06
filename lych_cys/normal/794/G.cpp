#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define N 600009
#define M 6000009
#define cbn(x,y) ((ll)fac[x]*inv[y]%mod*inv[(x)-(y)]%mod)
using namespace std;

ll n; int la,lb,cnt,prm[N],phi[M],f[N],fac[N],inv[N];
char a[N],b[N];
int ksm(int x,ll y){
	int z=1; for (; y; y>>=1,x=(ll)x*x%mod) if (y&1) z=(ll)z*x%mod;
	return z;
}
int gcd(int x,int y){ return y?gcd(y,x%y):x; }
void pwk(){
	int i,j,k;
	fac[0]=inv[0]=inv[1]=1;
	for (i=1; i<N; i++) fac[i]=(ll)fac[i-1]*i%mod;
	for (i=2; i<N; i++) inv[i]=mod-(ll)inv[mod%i]*(mod/i)%mod;
	for (i=2; i<N; i++) inv[i]=(ll)inv[i]*inv[i-1]%mod;
	for (i=2; i<M; i++){
		if (!phi[i]){
			phi[i]=i-1; prm[++cnt]=i;
		}
		for (j=1; j<=cnt && (k=i*prm[j])<M; j++)
			if (i%prm[j])
				phi[k]=phi[i]*(prm[j]-1);
			else{
				phi[k]=phi[i]*prm[j]; break;
			}
	}
	phi[1]=1;
	for (i=2; i<N; i++) phi[i]=(phi[i]+phi[i-1])%mod;
}
int work(ll m){
	if (m<M) return phi[m];
	ll i,j; int &ans=f[n/m]; if (ans!=-1) return ans;
	ans=m%mod*((m-1)%mod)*(mod+1>>1)%mod;
	for (i=2; i<=m; i=j+1){
		j=m/(m/i);
		ans=(ans-(j-i+1)%mod*work(m/i)%mod+mod)%mod;
	}
	return ans;
}
int solve(ll m){
	ll i,j; int last=2,now,ans=0;
	for (i=1; i<=m; last=now,i=j+1){
		j=m/(m/i); now=ksm(2,j+1);
		ans=(ans+(ll)(now-last+mod)*(work(m/i)*2-1))%mod;
	}
	return ans;
}
int main(){
	scanf("%s%s%lld",a+1,b+1,&n);
	la=strlen(a+1); lb=strlen(b+1);
	pwk(); 
	int i,x,y,z,da=0,db=0,s1=0,s2=0,ans=0;
	for (i=1; i<=la; i++)
		if (a[i]=='A') da++; else if (a[i]=='B') db++;
		else s1++;
	for (i=1; i<=lb; i++)
		if (b[i]=='A') da--; else if (b[i]=='B') db--;
		else s2++;
	for (i=0; i<=s1+s2; i++){
		x=da+i-s2; y=db+s1-i;
		if (!x || !y) continue;
		if ((x>0)^(y>0)){
			x=abs(x); y=abs(y); z=gcd(x,y);
			ans=(ans+cbn(s1+s2,i)*(ksm(2,n/max(x/z,y/z)+1)-2+mod))%mod;
		}
	}
	if (la==lb){
		for (i=y=1,x=0; i<=la; i++){
			if (a[i]=='?' && b[i]=='?') x++;
			if (a[i]-'A'+b[i]-'A'==1) y=0;
		}
		z=(s2>=da?cbn(s1+s2,s2-da):0);
		if (y){
			ans=(ans+(ll)ksm(2,x)*(ksm(2,n+1)-2+mod)%mod*(ksm(2,n+1)-2+mod))%mod;
			z=(z-ksm(2,x)+mod)%mod;
		}
		ans=(ans+(ll)z*solve(n))%mod;
	}
	printf("%d\n",ans);
	return 0;
}
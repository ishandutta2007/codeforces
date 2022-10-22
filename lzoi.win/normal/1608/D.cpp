#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5,mod=998244353;
int n;
string a[MAXN];
ll fac[MAXN],inv[MAXN];
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
int s0,s1,ans;
ll C(int n,int m){
	if(n<m) return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int Check(){
	int res=1;
	for(int i=1; i<=n; i++){
		if(a[i]=="WW"||a[i]=="BB") return 0;
		if(a[i]=="??") res=res*2%mod;
	}
	return res;
}
int CheckBW(){
	for(int i=1; i<=n; i++)
		if(a[i][0]=='W'||a[i][1]=='B') return 0;
	return 1;
}
int CheckWB(){
	for(int i=1; i<=n; i++)
		if(a[i][0]=='B'||a[i][1]=='W') return 0;
	return 1;
}
int s2,s3;
int main(){
	//freopen("in2.txt","r",stdin);
	n=1e5;
	fac[0]=1;
	for(int i=1; i<=n; i++)
		fac[i]=fac[i-1]*i%mod;
	inv[n]=Fstpw(fac[n],mod-2);
	for(int i=n; i; i--)
		inv[i-1]=inv[i]*i%mod;
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i][0]=='W') s0++;
		if(a[i][0]=='B') s2++;
		if(a[i][1]=='B') s1++;
		if(a[i][1]=='W') s3++;
	}
	for(int i=max(s0,s1); i<=n; i++)
		ans=(ans+C(n-s0-s2,i-s0)*C(n-s1-s3,i-s1))%mod;
	//printf("%d\n",ans);
	ans=(ans-Check()+CheckBW()+CheckWB()+mod)%mod;
	printf("%d\n",ans);
	return 0;
}
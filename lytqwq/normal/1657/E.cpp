#include<bits/stdc++.h>
#include<cstdio>
#include<cctype>
#define ll long long
#define PI pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ui unsigned int
#define pb push_back
#define llu long long unsigned
using namespace std;
const int MB=1<<20;
struct FastIO{
	char ib[MB+100],*p,*q;
	char ob[MB+100],*r,stk[128];
	int tp;
	FastIO(){p=q=ib,r=ob,tp=0;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);}
	char read_char(){if(p==q){p=ib,q=ib+fread(ib,1,MB,stdin);if(p==q)return 0;}return *p++;}
	template<typename T>
	void read_int(T& x){char c=read_char(),l=0;for(x=0;!isdigit(c);c=read_char())l=c;for(;isdigit(c);c=read_char())x=x*10-'0'+c;if(l=='-')x=-x;}
	void write_char(char c){if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);*r++=c;}
	template<typename T>
	void write_int(T x){if(x<0)write_char('-'),x=-x;do stk[++tp]=x%10+'0';while(x/=10);while(tp)write_char(stk[tp--]);}
}IO;
//IO.read_int(a);c=IO.read_char();IO.write_int(a);//IO.write_char(c);
const int N=260,mod=998244353;
int T,n,k;
int f[N][N];//i, val=j
int pw[N][N*N];
int fac[N],invfac[N],inv[N];
int C(int x,int y){
	return fac[x]*1ll*invfac[y]%mod*invfac[x-y]%mod;
}
int main(){
//	scanf("%d",&T);
	fac[0]=fac[1]=inv[0]=inv[1]=invfac[0]=invfac[1]=1;
	for(int i=2;i<N;i++){
		fac[i]=fac[i-1]*1ll*i%mod;
		inv[i]=inv[mod%i]*1ll*(mod-mod/i)%mod;
		invfac[i]=invfac[i-1]*1ll*inv[i]%mod;
	}
	T=1;
	while(T--){
		scanf("%d%d",&n,&k);
		n--;
		for(int i=1;i<=k;i++){
			pw[i][0]=1;
			for(int v=1;v<=n*n;v++){
				pw[i][v]=pw[i][v-1]*1ll*i%mod;
			}
		}
		f[k+1][n]=1;
		for(int i=k;i>=1;i--){
			for(int p=n;p>=1;p--){
				for(int c=0;c<=p;c++){
					f[i][p-c]=(f[i][p-c]+f[i+1][p]*1ll*C(p,c)%mod*1ll*pw[k-i+1][((p-1)+(p-c))*c/2])%mod;
				}
			}
		}
//		printf("%d\n",f[1][0]);
		int ss=0;
		for(int o=1;o<=k;o++)ss=(ss+f[o][0])%mod;
		printf("%d\n",ss);
	}
	return 0;
}
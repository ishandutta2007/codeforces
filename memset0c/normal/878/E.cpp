#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0; register char c=getchar(); register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10); putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
const int N=1e5+10,L=20,mod=1e9+7;
int n,m,pw2[1<<L],pto[N],sum[N][L],jump[N][L],sumall[N][L];
long long a[N];
int ask(int l,int r){
	// printf("ask(%d,%d)=",l,r);
	int res=0; --l;
	for(int i=L-1;i>=0;i--)
		if(r-(1<<i)>=l){
			res=(res+(long long)pw2[r-(1<<i)-l]*sum[r][i])%mod;
			r-=1<<i;
		}
	// printf("%d\n",res);
	return res;
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	pw2[0]=1;
	for(int i=1;i<(1<<L);i++)pw2[i]=(pw2[i-1]*2)%mod;
	read(n),read(m);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=n;i>=1;i--){
		pto[i]=-1;
		long long sum=0;
		for(int j=i;j>=1;j--){
			sum=a[j]+2*sum;
			if(sum<0){pto[i]=j;break;}
			if(sum>(LLONG_MAX>>1))break;
		}
	}
	// for(int i=1;i<=n;i++)printf("%d%c",pto[i]," \n"[i==n]);
	for(int i=1;i<=n;i++){
		sum[i][0]=(a[i]+mod)%mod;
	}
	for(int i=1;i<L;i++)
		for(int j=1;j<=n;j++)
			if(j-(1<<(i-1))>0){
				sum[j][i]=((long long)pw2[1<<(i-1)]*sum[j][i-1]+sum[j-(1<<(i-1))][i-1])%mod;
			}
	for(int i=1;i<=n;i++){
		jump[i][0]=pto[i];
		if(~jump[i][0])sumall[i][0]=ask(pto[i],i);
	}
	for(int i=1;i<L;i++)
		for(int j=1;j<=n;j++)
			if(jump[j][i-1]>1){
				jump[j][i]=jump[jump[j][i-1]-1][i-1];
				sumall[j][i]=(sumall[jump[j][i-1]-1][i-1]+sumall[j][i-1])%mod;
			}else{
				jump[j][i]=-1;
			}
	for(int l,r,i=1;i<=m;i++){
		read(l),read(r);
		if(l==r){print((a[l]+mod)%mod," \n"[i==n]);continue;}
		int ans=(a[l++]+mod)%mod;
		for(int i=L-1;i>=0;i--)
			if(~jump[r][i]&&jump[r][i]>l){
				ans=(ans+2ll*sumall[r][i])%mod;
				r=jump[r][i]-1;
			}
		ans=(ans+2ll*ask(l,r))%mod;
		print(ans,'\n');
	}
}
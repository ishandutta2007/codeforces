
#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
template<class T> inline void print(T a,int l,int r){for(int i=l;i<=r;i++)print(a[i]," \n"[i==r]);}
const int N=1e6+10;
int n,mod,sum,ans,fac[N];
signed main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n),read(mod),fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=(long long)fac[i-1]*i%mod;
	for(int i=1;i<=n;i++){
		sum=(long long)fac[i]*(n-i+1)%mod*(n-i+1)%mod*fac[n-i]%mod;
		ans=(ans+sum)%mod;
	}
	print(ans,'\n');
}
#include<bits/stdc++.h>
// #define ll long long
#define int long long
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
template<class T> inline void print(T a,int l,int r){for(int i=l;i<=r;i++)print(a[i]," \n"[i==r]);}
const int N=1e5+10,mod=1e9+7;
int n,m,f[N];
int calc(int x){
	if(x==1)return 2;
	if(x==2)return 4;
	if(f[x])return f[x];
	return f[x]=(calc(x-1)+calc(x-2))%mod;
}
int solve(int n,int m){
	// if(n==1&&m==1)return 2;
	// if((n==1&&m==2||n==2&&m==1))return 4;
	return (calc(n)+calc(m)-2)%mod;
}
signed main(){
#ifdef memset0
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
#endif
	read(n),read(m);
	printf("%lld\n",solve(n,m));
}
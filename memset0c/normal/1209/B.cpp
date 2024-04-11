#include<bits/stdc++.h>
#define ll long long
// #define int long long
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
const int N=110;
int n,ans,sum,a[N],b[N],x[N];
char s[N];
signed main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n);scanf("%s",s+1);
	for(int i=1;i<=n;i++) x[i]=(s[i]=='1');
	for(int i=1;i<=n;i++) read(a[i]),read(b[i]);
	for(int c=0;c<=100000;c++){
		sum=0;
		for(int i=1;i<=n;i++) if(c-b[i]>=0&&(c-b[i])%a[i]==0) x[i]^=1;
		for(int i=1;i<=n;i++) if(x[i]) sum++;
		ans=std::max(ans,sum);
	}
	print(ans,'\n');
}
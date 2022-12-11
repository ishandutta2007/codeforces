#include<bits/stdc++.h>
#define ll long long
// #define int long long
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
const int N=3e5+10;
int T,n,m,a[N],b[N],L[N],R[N],f[N];
signed main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	for(read(T);T--;){
		read(n);
		for(int i=1;i<=n;i++)L[i]=R[i]=0;
		for(int i=1;i<=n;i++){
			read(a[i]),b[i]=a[i];;
			if(!L[a[i]])L[a[i]]=i; R[a[i]]=i;
		}
		std::sort(b+1,b+1+n),m=std::unique(b+1,b+1+n)-b-1;
		int ans=m;
		for(int i=1,j=2;i<=m;j=i+1){
			while(j<=m&&R[b[j-1]]<L[b[j]])++j;
			ans=std::min(ans,m-(j-i)),i=j;
		}
		print(ans,'\n');
	}
	return 0;
}
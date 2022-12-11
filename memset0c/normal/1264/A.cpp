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
template<class T> inline void print(T x,int l,int r){for(int i=l;i<=r;i++)print(x[i]," \n"[i==r]);}
const int N=4e5+10;
int T,n,m,x,y,z,a[N],b[N];
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	for(read(T);T--;){
		read(n),a[0]=-1,m=0;
		for(int i=1;i<=n;i++)read(a[i]);
		for(int i=1;i<=n;i++)if(a[i]!=a[i-1]){
			b[++m]=1;
		}else{
			b[m]++;
		}
		for(int i=1;i<=n;i++)b[i]+=b[i-1];
		while(m&&b[m]>(n>>1))m--;
		x=y=z=0;
		for(;m>=3;m--){
			int k=std::upper_bound(b+2,b+m+1,b[1]<<1)-b;
			if(k>=m)continue;
			if(b[m]-b[k]<=b[1])continue;
			x=b[1],y=b[k]-b[1],z=b[m]-b[k];
			break;
		}
		printf("%d %d %d\n",x,y,z);
    }
}
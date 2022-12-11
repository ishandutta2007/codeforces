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
const int N=110;
int t,n,x,y,fl,max,a[N],b[N];
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	for(read(t);t--;){
		read(n),read(x),read(y),max=fl=0;
		for(int i=1;i<=x;i++)read(a[i]),max=std::max(max,a[i]);
		for(int i=1;i<=y;i++)read(b[i]),max=std::max(max,b[i]);
		for(int i=1;i<=x;i++)fl|=a[i]==max;
		puts(fl?"YES":"NO");
	}
}
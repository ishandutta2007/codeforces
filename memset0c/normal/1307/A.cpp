// 
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
const int N=110;
int T,n,m,ans,a[N];
int main(){
#ifdef memset0
	// freopen("1.in","r",stdin);
#endif
	for(read(T);T--;){
		read(n),read(m);
		for(int i=1;i<=n;i++)read(a[i]);
		ans=a[1];
		for(int i=2;i<=n;i++){
			int t=std::min(m/(i-1),a[i]);
			ans+=t,m-=t*(i-1);
		}
		std::cout<<ans<<std::endl;
	}
}
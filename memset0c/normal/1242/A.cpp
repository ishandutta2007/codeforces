#include<bits/stdc++.h>
#define ll long long
template<class T> inline void read(T &x){
	x=0; register char c=getchar(); register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10); putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
ll n,g;
inline void add(ll x){
	g=g?std::__gcd(g,x):x;
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	std::cin>>n;
	for(int i=2;(ll)i*i<=n;i++)if(n%i==0){
		add(i),add(n/i);
	}
	g=g?g:n;
	std::cout<<g<<std::endl;
}
#include<bits/stdc++.h>
#include <cstdlib>
template<class T> inline void read(T &x){
	x=0; register char c=getchar(); register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10); putchar(x%10+'0');
}
const int N=2e5+10;
int T,n,k,a[N],b[N],s[N];
bool solve(){
	if(n==1){
		return a[1]==k;
	}
	bool fl=false;
	for(int i=1;i<=n;i++)fl|=a[i]==k;
	if(!fl)return false;
	fl=false;
	for(int i=1;i<=n;i++)
		for(int j=std::max(1,i-2);j<=std::min(n,i+2);j++)
			if(i!=j&&a[i]>=k&&a[j]>=k){
				fl=true;
			}
	return fl;
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	for(read(T);T--;){
		read(n),read(k);
		for(int i=1;i<=n;i++)read(a[i]);
		puts(solve()?"yes":"no");
	}
}
#include<bits/stdc++.h>
using namespace std;
int const N=2333333;
int n,f[N],fa[N],mx1[N],mx2[N];
inline int read(){
	int x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
inline void write(int x){
	if(x>9)write(x/10);
	putchar((x%10)|48);
}
inline int update(int x,int fa){
	if(mx2[fa]>f[x])return 0;
	if(f[x]>mx1[fa])
		mx2[fa]=mx1[fa],mx1[fa]=f[x];
	else if(f[x]>mx2[fa])
		mx2[fa]=f[x];
	int t=max(mx1[fa],mx2[fa]+1);
	return t==f[fa]?0:f[fa]=t;
}
int main(){
	n=read();f[1]=1;
	for(int i=2;i<=n+1;++i){
		fa[i]=read();f[i]=1;
		int p=i;
		while(p!=1&&update(p,fa[p]))p=fa[p];
		write(mx1[1]);putchar(32);
	}
}//
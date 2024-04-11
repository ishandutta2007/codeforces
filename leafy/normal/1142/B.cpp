#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,q;
int p[N],a[N],nxt[N],la[N];
int fa[N][20],num[N];
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s; 
}
int main(){
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) p[i]=read(),nxt[p[i-1]]=p[i],la[i]=m+1;
	nxt[p[n]]=p[1];
	for(int i=1;i<=m;i++) a[i]=read(),num[i]=m+1;
	num[m+1]=m+1;
	for(int i=m;i>=1;i--){
		fa[i][0]=la[nxt[a[i]]];la[a[i]]=i;
		for(int j=1;j<20;j++) fa[i][j]=fa[fa[i][j-1]][j-1];
		int x=n-1,y=i;
		for(int j=19;j>=0;j--) if(fa[y][j]&&fa[y][j]!=m+1&&x>=(1<<j)) x-=(1<<j),y=fa[y][j];
		if(x) num[i]=num[i+1];
		else num[i]=min(y,num[i+1]);
	} 
	while(q--){
		int x=read(),y=read();
		putchar('0'+(num[x]<=y));
	}
	return 0;
}
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native") 
#include<bits/stdc++.h>
using namespace std;
int const N=50010;
int n,q,cur,a[N],in[N],out[N],dep[N],t[N],pre[N];
vector<int>e[N];
inline int read(){
	int x=0,flg=1;
	char c=getchar();
	while(!isdigit(c))flg*=c=='-'?-1:1,c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*flg;
}
inline void write(int x){
	if(x<0)putchar('-'),x*=-1;
	if(x>9)write(x/10);
	putchar((x%10)|48);
}
inline void writeln(int x){
	write(x),puts("");
}
void dfs(int x){
	in[x]=++cur;
	for(int y:e[x])
		dep[y]=dep[x]+1,dfs(y);
	out[x]=cur;
}
int main(){
	n=read(),q=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=2;i<=n;i++)
		e[read()].push_back(i);
	dfs(1);
	memcpy(t,a,sizeof t);
	for(int i=1;i<=n;i++)
		a[in[i]]=t[i];
	memcpy(t,dep,sizeof t);
	for(int i=1;i<=n;i++)
		dep[in[i]]=t[i];
	for(int i=1;i<=q;i++){
		int x,a1=0,a2=0;
		cin>>x;
		for(int j=in[x];j<=out[x];j++)
			if(pre[j]<=i)
				a1++,a2+=dep[j],pre[j]=i+a[j];
		write(a2-a1*dep[in[x]]),putchar(32);
		writeln(a1);
	}
}
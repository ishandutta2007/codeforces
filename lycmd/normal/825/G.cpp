#include<bits/stdc++.h>
using namespace std;
int const N=1000010;
int n,q,op,x,y,pre,cur,a[N];
vector<int>e[N];
namespace fastio{
#define gc() (uu==vv&&(vv=(uu=cc)+fread(cc,1,1<<21,stdin),uu==vv)?EOF:*uu++)
#define pc(c) (*o++=(c))
	int const N=23333333;
	char cc[N],*uu=cc,*vv=cc,buf[N],*p1=buf,*p2=buf,obuf[N],*o=obuf;
	int read(){
		char c=gc();
		int x=0;
		while(c<48||c>57)c=gc();
		while(c>47&&c<58)x=(x<<1)+(x<<3)+c-48,c=gc();
		return x;
	}
	void write(int x){
		if(x>9)write(x/10);
		pc((x%10)|48);
	}
	void writeln(int x){
		write(x),pc(10);
	} 
	void flush(){
		fwrite(obuf,o-obuf,1,stdout);
	}
#undef gc
#undef pc
}
using namespace fastio;
void dfs(int x,int fa,int k){
	for(int y:e[x])
		if(y^fa)
			dfs(y,x,a[y]=min(k,y));
}
int main(){
	cur=n=read(),q=read();
	for(int i=1;i<n;i++)
		x=read(),y=read(),e[x].push_back(y),e[y].push_back(x);
	for(int i=0;i<q;i++)
		if(op=read(),x=(read()+pre)%n+1,op&1)
			!i&&(dfs(x,0,a[x]=x),0),cur=min(cur,a[x]);
		else
			writeln(pre=min(cur,a[x]));
	flush();
}
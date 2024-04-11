#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx")
#include<bits/stdc++.h>
#define ord(x) ((x)>>11)
#define bl(x) ((x)<<11)
#define br(x) ((x)<<11|2047)
using namespace std;
int const N=210010,B=505,K=105;
int n,q,a[N],f[B][K];
namespace fastio{
#ifdef ONLINE_JUDGE
#define gc() (uu==vv&&(vv=(uu=cc)+fread(cc,1,1<<21,stdin),uu==vv)?EOF:*uu++)
#define pc(c) (*o++=(c))
#else
#define gc() getchar()
#define pc(c) putchar(c)
#endif
	int const NN=2333333;
	char cc[NN],*uu=cc,*vv=cc,buf[NN],*p1=buf,*p2=buf,obuf[NN],*o=obuf;
	int read(){
		char c=gc();
		int x=0,flg=1;
		while(c<48||c>57){
			if(c==EOF)exit(0);
			flg=c=='-'?-flg:flg,c=gc();
		}
		while(c>47&&c<58)x=(x<<1)+(x<<3)+c-48,c=gc();
		return x*flg;
	}
	void write(int x){
		if(x<0)pc('-'),x=-x;
		if(x>9)write(x/10);
		pc((x%10)|48);
	}
	void writeln(int x){
		write(x),pc(10);
	}
	void writesp(int x){
		write(x),pc(32);
	}
	int gtc(){
		char c=gc();
		while(c<33){
			if(c==-1)return -1;
			c=gc();
		}
		return c;
	}
	void pts(const char*s){
		int n=strlen(s);
		for(int i=0;i<n;i++)
			pc(s[i]);
		pc(10);
	}
	void flush(){
		fwrite(obuf,o-obuf,1,stdout);
	}
#undef gc
#undef pc
}
using namespace fastio;
void build(int x){
	for(int i=1;i<K;i++)f[x][i]=i;
}
void rebuild(int x){
	for(int i=bl(x);i<=br(x);i++)a[i]=f[x][a[i]];
	build(x);
}
void upd(int l,int r,int x,int y){
	for(int i=l;i<=r;i++)
		if(a[i]==x)a[i]=y;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=0;i<=ord(n);i++)build(i);
	for(q=read();q--;){
		int l=read(),r=read(),x=read(),y=read();
		if(ord(l)==ord(r)){
			rebuild(ord(l)),upd(l,r,x,y);
			continue;
		}
		rebuild(ord(l)),rebuild(ord(r));
		upd(l,br(ord(l)),x,y),upd(bl(ord(r)),r,x,y);
		for(int i=ord(l)+1;i<ord(r);i++)
			for(int j=1;j<K;j++)
				if(f[i][j]==x)f[i][j]=y;
	}
	for(int i=1;i<=n;i++)
		writesp(f[ord(i)][a[i]]);
	flush();
}
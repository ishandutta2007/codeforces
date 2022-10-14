#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=1000010;
int n,ans,a[N],b[N];
namespace fastio{
#define gc() (uu==vv&&(vv=(uu=cc)+fread(cc,1,1<<21,stdin),uu==vv)?EOF:*uu++)
#define pc(c) (*o++=(c))
	int const N=23333333;
	char cc[N],*uu=cc,*vv=cc,buf[N],*p1=buf,*p2=buf,obuf[N],*o=obuf;
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
	int gtc(){
		char c=gc();
		while(c<33){
			if(c==-1)return -1;
			c=gc();
		}
		return c;
	}
	void flush(){
		fwrite(obuf,o-obuf,1,stdout);
	}
#undef gc
#undef pc
}
using namespace fastio;
signed main(){
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<n;i++)
		b[i]=abs(a[i+1]-a[i]);
	for(int i=2;i<n;i+=2)
		b[i]*=-1;
	for(int i=1,cur=0;i<n;i++)
		ans=max(ans,cur=max(cur+b[i],0ll));
	for(int i=1;i<n;i++)
		b[i]*=-1;
	for(int i=1,cur=0;i<n;i++)
		ans=max(ans,cur=max(cur+b[i],0ll));
	writeln(ans),flush();
}
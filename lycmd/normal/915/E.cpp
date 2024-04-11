#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
int const N=14000010;
int n,q,rt,tot,tr[N],ls[N],rs[N];
char lt[N];
namespace fastio{
#ifdef ONLINE_JUDGE
#define gc() (uu==vv&&(vv=(uu=cc)+fread(cc,1,1<<21,stdin),uu==vv)?EOF:*uu++)
#define pc(c) (*o++=(c))
#else
#define gc() getchar()
#define pc(c) putchar(c)
#endif
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
void update(int x){
	tr[x]=tr[ls[x]]+tr[rs[x]];
}
void download(int x,int l,int r){
	int mid=(l+r)>>1;
	char&t=lt[x];
	if(!~t)return;
	if(!ls[x])ls[x]=++tot;
	if(!rs[x])rs[x]=++tot;
	tr[ls[x]]=t*(mid-l+1),tr[rs[x]]=t*(r-mid);
	lt[ls[x]]=lt[rs[x]]=t;
	t=-1;
}
void modify(int&x,int l,int r,int ql,int qr,int k){
	if(!x)x=++tot;
	if(ql<=l&&r<=qr){
		tr[x]=k*(r-l+1),lt[x]=k;
		return;
	}
	download(x,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid)modify(ls[x],l,mid,ql,qr,k);
	if(qr>mid)modify(rs[x],mid+1,r,ql,qr,k);
	update(x);
}
int main(){
	n=read(),q=read();
	memset(lt,-1,sizeof lt);
	modify(rt,1,n,1,n,1);
	while(q--){
		int l=read(),r=read(),op=read();
		modify(rt,1,n,l,r,op-1);
		writeln(tr[1]);
	}
	flush();
}
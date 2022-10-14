#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
int const N=1000010;
int n,a[N],b[N];
long long ans;
__gnu_pbds::priority_queue<int>q;
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
	int gtc(){
		char c=gc();         
		while(c<=32)c=gc();
		return c;
	}
	void write(long long x){
		if(x<0)pc('-'),x=-x;
		if(x>9)write(x/10);
		pc((x%10)|48);
	}
	void writeln(long long x){
		write(x),pc(10);
	} 
	void flush(){
		fwrite(obuf,o-obuf,1,stdout);
	}
}
using namespace fastio;
signed main(){
    n=read();
	for(int i=1;i<=n;i++){
		a[i]=read(),q.push(a[i]-=i);
		if(i>1&&q.top()>a[i])
			q.pop(),q.push(a[i]);
		b[i]=q.top();
	}
	for(int i=n-1;i;i--)
		b[i]=min(b[i],b[i+1]);
	for(int i=1;i<=n;i++)
		ans+=abs(a[i]-b[i]);
	writeln(ans);
    flush();
}
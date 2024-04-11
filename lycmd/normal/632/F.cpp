#include<bits/stdc++.h>
using namespace std;
int const N=2505;
int n,a[N][N],f[N];
vector<int>p[N];
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
struct edge{
	int x,y,w;
	edge(int a=0,int b=0,int c=0):x(a),y(b),w(c){}
	int operator<(const edge&rhs)const{
		return w<rhs.w;
	}
};
vector<edge>e;
void check(int i){
	if(!i)pts("NOT MAGIC"),flush(),exit(0);
}
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=read();
	for(int i=1;i<=n;i++)
		check(!a[i][i]),f[i]=i,p[i].push_back(i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			check(a[i][j]==a[j][i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			e.push_back({i,j,a[i][j]});
	sort(e.begin(),e.end());
	for(edge t:e){
		int fx=find(t.x),fy=find(t.y);
		if(fx==fy)continue;
		for(auto x:p[fx])
			for(auto y:p[fy])
				check(a[x][y]==t.w);
		f[fx]=fy;
		for(auto x:p[fx])
			p[fy].push_back(x);
		p[fx].clear();
	}
	pts("MAGIC"),flush();
}
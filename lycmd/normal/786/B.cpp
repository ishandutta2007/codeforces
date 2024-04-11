#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=2333333,INF=0x3f3f3f3f3f3f3f3f;
int n,m,tot,rt,pos[N],d[N];
vector<int>ein,eout;
vector<pair<int,int> >e[N];
deque<int>q;
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
	void writesp(int x){
		write(x),pc(32);
	} 
	void flush(){
		fwrite(obuf,o-obuf,1,stdout);
	}
#undef gc
#undef pc
}
using namespace fastio;
void add(int x,int y,int v){
	e[x].push_back({y,v});
}
void update(int x){
	add(ls(x),x,0),add(rs(x),x,0);
	add(4*n+x,4*n+ls(x),0),add(4*n+x,4*n+rs(x),0);
}
void build(int x,int l,int r){
	add(4*n+x,x,0);
	if(l==r){
		pos[l]=x;return;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	update(x);
}
void getin(int x,int l,int r,int ql,int qr,int p){
	if(ql<=l&&r<=qr){
		add(x,p,0);
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid)getin(ls(x),l,mid,ql,qr,p);
	if(qr>mid)getin(rs(x),mid+1,r,ql,qr,p);
}
void getout(int x,int l,int r,int ql,int qr,int p,int w){
	if(ql<=l&&r<=qr){
		add(p,4*n+x,w);
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid)getout(ls(x),l,mid,ql,qr,p,w);
	if(qr>mid)getout(rs(x),mid+1,r,ql,qr,p,w);
}
void add_edge(int al,int ar,int bl,int br,int p,int w){
	ein.clear(),eout.clear();
	getin(1,1,n,al,ar,p),getout(1,1,n,bl,br,p,w);
}
signed main(){
	n=read(),m=read(),rt=read();
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int op=read(),al,ar,bl,br,w;
		switch(op){
			case 1:
				al=ar=read(),bl=br=read(),w=read();break;
			case 2:
				al=ar=read(),bl=read(),br=read(),w=read();break;
			default:
				bl=br=read(),al=read(),ar=read(),w=read();break;
		}
		add_edge(al,ar,bl,br,8*n+i,w);
	}
	memset(d,0x3f,sizeof d),d[pos[rt]]=0;
	q.push_back(pos[rt]);
	while(!q.empty()){
		int x=q.front();q.pop_front();
		for(auto i:e[x]){
			int y=i.first,k=i.second;
			if(d[y]>d[x]+k){
				d[y]=d[x]+k;
				if(k)
					q.push_back(y);
				else
					q.push_front(y);
			}
		}
	}
	for(int i=1;i<=n;i++)
		writesp(i^rt?d[4*n+pos[i]]<INF?d[4*n+pos[i]]:-1:0);
	flush();
}
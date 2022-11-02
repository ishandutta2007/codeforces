#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
typedef unsigned ull;
struct Hash
{
	ull a,b;
	inline Hash operator+(ull x) {return(Hash){a+x,b+x};}
	inline Hash operator+(Hash x) {return(Hash){a+x.a,b+x.b};}
	inline Hash operator*(Hash x) {return(Hash){a*x.a,b*x.b};}
	inline Hash operator*(ull x) {return(Hash){a*x,b*x};}
	inline char operator==(Hash x) {return a==x.a&&b==x.b;}
}B=(Hash){137,191},bas[100025],has[100025];
struct edge{int to,w,nxt;}e[200005];const int N=100020,P=1e9+7;
struct segt{int len,sm,ls,rs,lz;Hash hs;}t[25000005];
int n,m,S,T,tt,et,head[100005],rt[100005],lst[100005],pw[100025],st[100005];char vis[100005];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void pushup(int x)
{
	t[x].sm=t[t[x].ls].sm+t[t[x].rs].sm;
	t[x].hs=t[t[x].ls].hs*bas[t[t[x].rs].len]+t[t[x].rs].hs;
}
inline void allc(int &x,int w) {if(~w) t[++tt]=t[x],x=tt,t[x].sm=w?t[x].len:0,t[x].lz=w,t[x].hs=w?has[t[x].len]:(Hash){0ull,0ull};}
inline void pushdw(int &x) {if(~t[x].lz) t[++tt]=t[x],x=tt,allc(t[x].ls,t[x].lz),allc(t[x].rs,t[x].lz),t[x].lz=-1;}
inline void build(int &x,int l,int r,int v)
{
	t[x=++tt].len=r-l+1;if(l==r) return(void)(t[x]=(segt){1,v,0,0,-1,(Hash){(ull)v,(ull)v}});
	build(t[x].ls,l,(l+r)>>1,v),build(t[x].rs,((l+r)>>1)+1,r,v),pushup(x),t[x].lz=-1;
}
inline void motif(int &x,int l,int r,int dl,int dr,int dc)
{
	t[++tt]=t[x],x=tt;if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc);else pushdw(x);
	motif(t[x].ls,l,(l+r)>>1,dl,dr,dc),motif(t[x].rs,((l+r)>>1)+1,r,dl,dr,dc),pushup(x);
}
inline int query(int &x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return 0;else if(dl<=l&&r<=dr) return t[x].sm;else pushdw(x);
	return query(t[x].ls,l,(l+r)>>1,dl,dr)+query(t[x].rs,((l+r)>>1)+1,r,dl,dr);
}
inline void motifd(int &x,int l,int r,int dw,int dc)
{
	t[++tt]=t[x],x=tt;if(l==r) return(void)(t[x].sm=dc,t[x].hs=(Hash){(ull)dc,(ull)dc});else pushdw(x);
	if(dw<=((l+r)>>1)) motifd(t[x].ls,l,(l+r)>>1,dw,dc),pushup(x);
	else motifd(t[x].rs,((l+r)>>1)+1,r,dw,dc),pushup(x);
}
inline int queryd(int &x,int l,int r,int dw)
{
	if(l==r) return t[x].sm;else pushdw(x);
	if(dw<=((l+r)>>1)) return queryd(t[x].ls,l,(l+r)>>1,dw);else return queryd(t[x].rs,((l+r)>>1)+1,r,dw);
}
inline int diff(int &x,int &y,int l,int r)
{
	if(l==r||x==y) return r;else pushdw(x),pushdw(y);
	if(t[t[x].ls].hs==t[t[y].ls].hs) return diff(t[x].rs,t[y].rs,((l+r)>>1)+1,r);else return diff(t[x].ls,t[y].ls,l,(l+r)>>1);
}
inline int monijw(int &rt,int dr)
{
	int le=1,ri=dr,md,res=dr;
	while(le<=ri) {md=(le+ri)>>1;if(query(rt,1,N,md,dr)==dr-md+1) res=md,ri=md-1;else le=md+1;}
	return motif(rt,1,N,res,dr,0),res-1;
}
inline void debug(int &x) {for(int i=1;i<=N;i++) printf("%d",queryd(x,1,N,i));}
inline void plus2(int &rt,int x)
{
	x=N-x+1;//debug(rt),putchar('\n');
	if(queryd(rt,1,N,x)) {int w=monijw(rt,x);motifd(rt,1,N,w,1);/*printf("??? : %d\n",w);*/}
	else motifd(rt,1,N,x,1);
	//debug(rt),putchar('\n'),putchar('\n');
}
inline char comp(int &a,int &b)
{
	int zk1,zk2;if((zk1=queryd(a,1,N,1))^(zk2=queryd(b,1,N,1))) return zk1<zk2;
	int w=diff(a,b,1,N);return queryd(a,1,N,w)<queryd(b,1,N,w);
}
struct ZKAK{int id,gg;bool operator<(ZKAK b) const {int x,y; x=gg, y=b.gg; return !comp(x,y);}};
int main()
{
	read(n),read(m),memset(vis,0,sizeof(vis));
	for(int i=1,x,y,w;i<=m;i++) read(x),read(y),read(w),adde(x,y,w+1),adde(y,x,w+1);
	read(S),read(T),bas[0]=(Hash){1,1},pw[0]=1,has[0]=(Hash){0,0};
	for(int i=1;i<=N;i++) pw[i]=pw[i-1]*2ll%P;
	for(int i=1;i<=N;i++) bas[i]=bas[i-1]*B,has[i]=has[i-1]*B+(Hash){1,1};
	build(rt[S],1,N,0);int ot=1+(S==1);build(rt[ot],1,N,1);
	for(int i=1;i<=n;i++) if(S!=i) rt[i]=rt[ot];
	priority_queue<ZKAK>p;vis[S]=0,lst[S]=-1,p.push((ZKAK){S,rt[S]});
	while(!p.empty())
	{
		int x=p.top().id;p.pop();if(vis[x]) continue;else vis[x]=1;
//		printf("pop %d\n",x);
		for(int i=head[x];i;i=e[i].nxt)
		{
			int tmprt=rt[x];plus2(tmprt,e[i].w);
			if(comp(tmprt,rt[e[i].to]))
			{
				rt[e[i].to]=tmprt,lst[e[i].to]=x;
				if(!vis[e[i].to]) p.push((ZKAK){e[i].to,rt[e[i].to]});//printf("push %d\n",e[i].to);
			}
		}
		//for(int i=1;i<=n||!putchar('\n');i++) printf("%d : ",i),debug(rt[i]),putchar('\n');
//		debug(rt[3]),putchar('\n'),debug(rt[4]),putchar('\n');
//		if(comp(rt[3],rt[4])) puts("<");else puts(">=");
	}
	if(!lst[T]) return puts("-1"),0;
	int cnt=0,x=T,tp=1,res=0;st[tp]=x;
	for(int i=1;i<=N;i++) res=(res<<1|queryd(rt[T],1,N,i))%P;
	while(x!=S) cnt++,x=lst[x],st[++tp]=x;
	printf("%d\n%d\n",res,tp);
	while(tp) printf("%d ",st[tp--]);
	return putchar('\n'),0;
}
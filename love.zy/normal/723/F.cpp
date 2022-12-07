#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
#include<vector>
#include<set>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define ForkD(i,k,n) for(int i=n;i>=k;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=Pre[x];p;p=Next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=Next[p])  
#define Lson (o<<1)
#define Rson ((o<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (1000000007)
#define pb push_back
#define mp make_pair 
#define fi first
#define se second
#define vi vector<int> 
#define pi pair<int,int>
#define SI(a) ((a).size())
#define Pr(kcase,ans) printf("Case #%d: %I64d\n",kcase,ans);
#define PRi(a,n) For(i,n-1) cout<<a[i]<<' '; cout<<a[n]<<endl;
#define PRi2D(a,n,m) For(i,n) { \
						For(j,m-1) cout<<a[i][j]<<' ';\
						cout<<a[i][m]<<endl; \
						} 
#pragma comment(linker, "/STACK:102400000,102400000")
#define ALL(x) (x).begin(),(x).end()
long long mul(long long a,long long b){return (a*b)%F;}
long long add(long long a,long long b){return (a+b)%F;}
long long sub(long long a,long long b){return (a-b+(a-b)/F*F+F)%F;}
typedef long long ll;
#define MAXN (500000+10)
class bingchaji
{
public:
	int father[MAXN],n;
	void mem(int _n)
	{
		n=_n;
		For(i,n) father[i]=i;
	}
	int getfather(int x) 
	{
		if (father[x]==x) return x;
		
		return father[x]=getfather(father[x]);
	}
	void unite(int x,int y)
	{
		x=getfather(x);
		y=getfather(y);
		if (x^y) {
			father[x]=y;
		}
	}
	bool same(int x,int y)
	{
		return getfather(x)==getfather(y);
	}
}S;
int n,m,s,t,ds,dt;
struct edge{
	int u,v,w;
}e[MAXN*2+10];
vector<edge> ans;
bool operator<(edge a,edge b) {
	return a.w<b.w;
}
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 

int b[MAXN][2]={0};
vi ri;
int find(int x) {
	return lower_bound(ALL(ri),x)-ri.begin();
}

int main()
{
//	freopen("F.in","r",stdin);
//	freopen(".out","w",stdout);
	
	cin>>n>>m;
	For(i,m) {
		int u=read(),v=read();
		e[i].u=u,e[i].v=v;
	}
	cin>>s>>t>>ds>>dt;
	
	swap(s,t);swap(ds,dt);
	
	For(i,m) {
		e[i].w=0;
		if (e[i].u==s||e[i].v==s) ++e[i].w;
		if (e[i].u==t||e[i].v==t) ++e[i].w;
	}
	sort(e+1,e+1+m);
	
	S.mem(n);
	For(i,m) if (!e[i].w) {
		if (!S.same(e[i].u,e[i].v)) {
			S.unite(e[i].u,e[i].v);
			ans.pb(e[i]);
		}
	}
	For(i,n) S.getfather(i);
	
	ri;
	For(i,n) ri.pb(S.father[i]);
	sort(ALL(ri));
	ri.erase(unique(ri.begin(),ri.end()),ri.end()); 
	int cnt=SI(ri);
	
	For(i,m) if (e[i].w==1) {
		int p=S.father[e[i].u],p2=S.father[e[i].v];
		if (p2==s||p2==t) swap(p,p2);
		int now=find(p2);
		if (p==s) b[now][0]=i;
		else b[now][1]=i;
	}
	
	vi oer;
	
	bool fl=0;
	Rep(i,cnt) if (ri[i]!=s&&ri[i]!=t){
		if (b[i][0]==0&&b[i][1]==0) {
			puts("No"); return 0;
		}
		else if(b[i][0]==0&&b[i][1]!=0) {
			ans.pb(e[b[i][1]]); dt--;
		}else if(b[i][0]!=0&&b[i][1]==0) {
			ans.pb(e[b[i][0]]); ds--;
		} else {
			if (!fl) {
				ans.pb(e[b[i][0]]);
				ans.pb(e[b[i][1]]);
				ds--;dt--;
				fl=1;
			} else oer.pb(i);
		}
	}
	if (!fl&&e[m].w==2) {
			ans.pb(e[m]);
			ds--;dt--;
			fl=1;
	}
	
	Rep(i,SI(oer)) {
		int now=oer[i];
		if (ds<=dt) {
			ans.pb(e[b[now][1]]); dt--;
		} else {
			ans.pb(e[b[now][0]]); ds--;
		}
	}
	
	
	
	
	if (ds<0||dt<0|| !fl || ans.size()<n-1 ) {
			puts("No"); return 0;
	}
	puts("Yes");
	Rep(i,SI(ans)) {
		printf("%d %d\n",ans[i].u,ans[i].v);
	}	
	
	
	return 0;
}
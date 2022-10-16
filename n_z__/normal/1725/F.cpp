#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#undef ONLINE_JUDGE
#include<bits/stdc++.h>
#define Luogu 1
#define Cf 2
#define At 3
#define Other 4
#define No 5
//settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings
                                                                    #define use_qp                 0
                                                                    #define use_inv                0
                                                                    #define use_C                  0
                                                                    #define use_modint             0
                                                                    #define use_dinic              0
                                                                    #define use_mcmf               0
                                                                    #define use_gcd                0
                                                                    #define use_prime              0
                                                                    #define use_pbds               0
                                                                    #define use_BIT                0
                                                                    #define use_seg                0
                                                                    #define use_long_long          1
                                                                    #define use_fastio             1
                                                                    #define use_multiple_test_data 0
                                                                    #define ONLINE_JUDGE           Luogu
                                                                    #define me(x,y)                memset(x,y,sizeof(x))
                                                                    #define ex(x)                  return cout<<x<<endl,void(0)
                                                                    #define length_of_double_cout  10
//settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings
using namespace std;
#if ONLINE_JUDGE==No
#undef ONLINE_JUDGE
#endif
#if ONLINE_JUDGE==Cf or ONLINE_JUDGE==At
#pragma GCC optimize(3)
#endif
#ifdef ONLINE_JUDGE
	namespace Fread{const int SIZE=1<<16;char buf[SIZE],*S,*T;inline char getchar(){if(S==T){T=(S=buf)+fread(buf,1,SIZE,stdin);if(S==T)return'\n';}return *S++;}}namespace Fwrite{const int SIZE=1<<16;char buf[SIZE],*S=buf,*T=buf+SIZE;inline void flush(){fwrite(buf,1,S-buf,stdout);S=buf;}inline void putchar(char c){*S++=c;if(S==T)flush();}struct NTR{~NTR(){flush();}}ztr;}
    #define getchar Fread::getchar
	#define putchar Fwrite::putchar
#endif
#if use_pbds==1
#if ONLINE_JUDGE==Luogu
#include<bits/extc++.h>
#else
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#endif
using namespace __gnu_pbds;
#endif
#define Setprecision length_of_double_cout
namespace Fastio{struct Reader{template<typename T>Reader&operator>>(T&x){char c=getchar();short f=1;while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}x=0;while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}x*=f;return *this;}Reader&operator>>(double&x){char c=getchar();short f=1,s=0;x=0;double t=0;while((c<'0'||c>'9')&&c!='-'&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else return x*=f,*this;while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}Reader&operator>>(long double&x){char c=getchar();short f=1,s=0;x=0;long double t=0;while((c<'0'||c>'9')&&c!='-'&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else return x*=f,*this;while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}Reader&operator>>(__float128&x){char c=getchar();short f=1,s=0;x=0;__float128 t=0;while((c<'0'||c>'9')&&c!='-'&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else return x*=f,*this;while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}Reader&operator>>(char&c){c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();return *this;}Reader&operator>>(char*str){int len=0;char c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();while(c!='\n'&&c!=' '&&c!='\r')str[len++]=c,c=getchar();str[len]='\0';return*this;}Reader&operator>>(std::string&str){char c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();while(c!='\n'&&c!=' '&&c!='\r')str.push_back(c),c=getchar();return*this;}Reader(){}}cin;const char endl='\n';struct Writer{typedef __int128 mxdouble;template<typename T>Writer&operator<<(T x){if(x==0)return putchar('0'),*this;if(x<0)putchar('-'),x=-x;static int sta[45];int top=0;while(x)sta[++top]=x%10,x/=10;while(top)putchar(sta[top]+'0'),--top;return*this;}Writer&operator<<(double x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(double)_;static int sta[45];int top=0;while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');while(top)putchar(sta[top]+'0'),--top;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top)putchar(sta[top]+'0'),--top;return*this;}Writer&operator<<(long double x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(long double)_;static int sta[45];int top=0;while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');while(top)putchar(sta[top]+'0'),--top;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top)putchar(sta[top]+'0'),--top;return*this;}Writer&operator<<(__float128 x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(__float128)_;static int sta[45];int top=0;while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');while(top)putchar(sta[top]+'0'),--top;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top)putchar(sta[top]+'0'),--top;return*this;}Writer&operator<<(char c){putchar(c);return*this;}Writer&operator<<(char*str){int cur=0;while(str[cur])putchar(str[cur++]);return *this;}Writer&operator<<(const char*str){int cur=0;while(str[cur])putchar(str[cur++]);return*this;}Writer&operator<<(std::string str){int st=0,ed=str.size();while(st<ed)putchar(str[st++]);return*this;}Writer(){}}cout;}
#if use_fastio==1
#define cin Fastio::cin
#define cout Fastio::cout
#define endl Fastio::endl
#endif
#if use_long_long==1
#define int long long
#endif
//constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants
                                                                    #define N                      300000
                                                                    #define maxw                   300000
                                                                    #define eps                    1e-10
                                                                    #define p                      998244353
                                                                    //#undef N
                                                                    #undef p
                                                                    //#undef maxw
//constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants
#if (use_qp==1||use_C==1||use_inv==1)
#ifdef p
int qp(int x,int n=p-2,int P=p){int r=1;while(n){if(n&1)r=r*x%P;x=x*x%P,n>>=1;}return r;}
#else
int qp(int x,int n,int P){int r=1;while(n){if(n&1)r=r*x%P;x=x*x%P,n>>=1;}return r;}
#endif
#endif
#if (use_C==1||use_inv==1)
int fac[N+100],ifac[N+100];
void init(int n,int P=p){fac[0]=1;for(int x=1;x<=n;x++)fac[x]=fac[x-1]*x%P;ifac[n]=qp(fac[n],P-2,P);for(int x=n;x>=1;x--)ifac[x-1]=ifac[x]*x%P;}
int C(int x,int y,int P=p){if(x<y||y<0)return 0;return fac[x]*ifac[y]%P*ifac[x-y]%P;}
int iC(int x,int y,int P=p){if(x<y||y<0)return 0;return ifac[x]*fac[y]%P*fac[x-y]%P;}
int inv(int x,int P=p){return iC(x,1,P);}
#endif
#if use_modint==1
#define mod 20170408
struct modint{//
	int x;
	modint(int o=0){x=o%mod;}
	modint &operator = (int o){return x=o%mod,*this;}
	modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
	modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
	modint &operator *=(modint o){return x=1ll*x*o.x%mod,*this;}
	modint &operator +=(int o){return x=x+(o%mod)>=mod?x+(o%mod)-mod:x+(o%mod),*this;}
	modint &operator -=(int o){return x=x-(o%mod)<0?x-(o%mod)+mod:x-(o%mod),*this;}
	modint &operator *=(int o){return x=1ll*x*(o%mod)%mod,*this;}
	modint &operator ^=(int b){
		modint a=*this,c=1;
		for(;b;b>>=1,a*=a)if(b&1)c*=a;
		return x=c.x,*this;
	}
	modint &operator /=(modint o){return *this *=o^=mod-2;}
    modint &operator /=(int o){return *this *=modint(o)^=mod-2;}
	friend modint operator +(modint a,modint b){return a+=b;}
	friend modint operator -(modint a,modint b){return a-=b;}
	friend modint operator *(modint a,modint b){return a*=b;}
	friend modint operator /(modint a,modint b){return a/=b;}
	friend modint operator +(modint a,int b){return a+=b;}
	friend modint operator -(modint a,int b){return a-=b;}
	friend modint operator *(modint a,int b){return a*=b;}
	friend modint operator +(int a,modint b){return b+=a;}
	friend modint operator -(int a,modint b){return -1*(b-=a);}
	friend modint operator *(int a,modint b){return b*=a;}
	friend modint operator ^(modint a,int b){return a^=b;}
	friend bool operator ==(modint a,int b){return a.x==b;}
	friend bool operator !=(modint a,int b){return a.x!=b;}
	friend bool operator <(modint a,int b){return a.x<b;}
	friend bool operator >(modint a,int b){return a.x>b;}
	friend bool operator <=(modint a,int b){return a.x<=b;}
	friend bool operator >=(modint a,int b){return a.x>=b;}
	bool operator ! () {return !x;}
	modint operator - () {return x?mod-x:0;}
	bool operator <(const modint&b)const{return x<b.x;}
	bool operator >(const modint&b)const{return x>b.x;}
	bool operator <=(const modint&b)const{return x<=b.x;}
	bool operator >=(const modint&b)const{return x>=b.x;}
	bool operator ==(const modint&b)const{return x==b.x;}
	bool operator !=(const modint&b)const{return x!=b.x;}
    operator int() const {return x;}
};
inline modint qp(modint x,int y){return x^y;}
inline modint abs(modint x){return x>0?x:-x;}
istream&operator>>(istream&is,modint&m)
{
    int o;
    is>>o;
    m=o;
	return is;
}
ostream&operator<<(ostream&os,modint m)
{
    os<<m.x;
	return os;
}
#endif
#if use_BIT==1
struct BIT
{
    int BIT_a[N+10],BIT_b[N+10];
    BIT(){memset(BIT_a,0,sizeof(BIT_a));memset(BIT_b,0,sizeof(BIT_b));}
    void Add_a(int n,int u,int U=N){for(int x=n;x<=U;x+=x&-x)BIT_a[x]+=u;}
    void Add_b(int n,int u,int U=N){for(int x=n;x<=U;x+=x&-x)BIT_b[x]+=u;}
    void add(int L,int R,int u,int U=N){int l=L+1,r=R+1;Add_a(l,u),Add_a(r+1,-u);Add_b(l,l*u),Add_b(r+1,-(r+1)*u);}
    int Query_a(int n){int r=0;for(int x=n;x;x-=x&-x)r+=BIT_a[x];return r;}
    int Query_b(int n){int r=0;for(int x=n;x;x-=x&-x)r+=BIT_b[x];return r;}
    int query(int L,int R){int l=L+1,r=R+1;return (r+1)*Query_a(r)-Query_b(r)-l*Query_a(l-1)+Query_b(l-1);}
};
#endif
#if use_seg==1
#define builddd \
	void buildd(int num,int le,int ri)\
    {\
        if(le==ri){tre[num]=a[le];return;}\
        int mid=(le+ri)/2;\
        buildd(num*2,le,mid);\
        buildd(num*2+1,mid+1,ri);\
        tre[num]=tre[num*2]+tre[num*2+1];\
    }
struct seg_with_lazytag{
    int tre[N*4],laz[N*4],a[N],n;
    builddd
    void build(int nn,int *A)
    {
        n=nn;
        for(int x=1;x<=n;x++)
        a[x]=A[x];
        memset(tre,0,sizeof(tre));
        memset(laz,0,sizeof(laz));
        buildd(1,1,n);
    }
    seg_with_lazytag(int nn,int *A){build(nn,A);}
    void pushdown(int num,int le,int ri)
    {
    	int mid=(le+ri)/2;
        if(laz[num]!=0)tre[num*2]+=laz[num]*(mid-le+1),tre[num*2+1]+=laz[num]*(ri-mid),laz[num*2]+=laz[num],laz[num*2+1]+=laz[num],laz[num]=0;
    }
    void update(int num,int le,int ri,int x,int y,int k)
    {
        if(x<=le&&y>=ri){tre[num]+=k*(ri-le+1);laz[num]+=k;return;}
        tre[num]+=max(0ll,k*(min(ri,y)-max(le,x)+1));
        pushdown(num,le,ri);
        int mid=(le+ri)/2;
        if(x<=mid)update(num*2,le,mid,x,y,k);
        if(y>mid)update(num*2+1,mid+1,ri,x,y,k);
    }
    void update(int x,int y,int k=1){update(1,1,n,x,y,k);}
    int query(int num,int le,int ri,int x,int y)
    {
        if(x<=le&&y>=ri)return tre[num];
        pushdown(num,le,ri);
        int mid=(le+ri)/2;
        int ans=0;
        if(x<=mid)ans+=query(num*2,le,mid,x,y);
        if(y>mid)ans+=query(num*2+1,mid+1,ri,x,y);
        return ans;
    }
    int query(int x,int y){return query(1,1,n,x,y);}
};
#define update_querysum \
    void update(int num,int le,int ri,int x,int y)\
    {\
        if(le==ri){tre[num]+=y;return;}\
        int mid=(le+ri)/2;\
        if(x<=mid)update(num*2,le,mid,x,y);\
        else update(num*2+1,mid+1,ri,x,y);\
        tre[num]=tre[num*2]+tre[num*2+1];\
    }\
    void update(int x,int k=1){update(1,1,n,x,k);}\
    int query(int num,int le,int ri,int x,int y)\
    {\
        if(x<=le&&y>=ri)return tre[num];\
        int mid=(le+ri)/2;\
        int ans=0;\
        if(x<=mid)ans+=query(num*2,le,mid,x,y);\
        if(y>mid)ans+=query(num*2+1,mid+1,ri,x,y);\
        return ans;\
    }\
    int query(int x,int y){return query(1,1,n,x,y);}
struct seg_without_lazytag{
    int tre[N*4],a[N],n;
    builddd
    void build(int nn,int *A)
    {
        n=nn;
        for(int x=1;x<=n;x++)
        a[x]=A[x];
        memset(tre,0,sizeof(tre));
        buildd(1,1,n);
    }
    seg_without_lazytag(int nn,int *A){build(nn,A);}
    update_querysum
};
struct seg_without_lazytag_with_MaxMin{
    int tre[N*4],a[N],n,Max[N*4],Min[N*4];
    void buildd(int num,int le,int ri)
    {
        if(le==ri){tre[num]=Max[num]=Min[num]=a[le];return;}
        int mid=(le+ri)/2;
        buildd(num*2,le,mid);
        buildd(num*2+1,mid+1,ri);
        tre[num]=tre[num*2]+tre[num*2+1];
        Max[num]=max(Max[num*2],Max[num*2+1]);
        Min[num]=min(Min[num*2],Min[num*2+1]);
    }
    void build(int nn,int *A)
    {
        n=nn;
        for(int x=1;x<=n;x++)
        a[x]=A[x];
        memset(tre,0,sizeof(tre));
        memset(Max,0,sizeof(Max));
        memset(Min,0,sizeof(Min));
        buildd(1,1,n);
    }
    seg_without_lazytag_with_MaxMin(int nn,int *A){build(nn,A);}
    update_querysum
    int query_max(int num,int le,int ri,int x,int y)
    {
        if(x<=le&&y>=ri)return Max[num];
        int mid=(le+ri)/2;
        int ans=-10000000000;
        if(x<=mid)ans=max(ans,query_max(num*2,le,mid,x,y));
        if(y>mid)ans=max(ans,query_max(num*2+1,mid+1,ri,x,y));
        return ans;
    }
    int query_max(int x,int y){return query_max(1,1,n,x,y);}
    int query_min(int num,int le,int ri,int x,int y)
    {
        if(x<=le&&y>=ri)return Min[num];
        int mid=(le+ri)/2;
        int ans=10000000000;
        if(x<=mid)ans=min(ans,query_min(num*2,le,mid,x,y));
        if(y>mid)ans=min(ans,query_min(num*2+1,mid+1,ri,x,y));
        return ans;
    }
    int query_min(int x,int y){return query_min(1,1,n,x,y);}
};
#endif
#define exmax(a,...) (max({a,##__VA_ARGS__}))
#define exmin(a,...) (min({a,##__VA_ARGS__}))
#define mymax(x,y)  ({__typeof(x) _x=x;__typeof(y) _y=y;_x>_y?_x:_y;})
#define mymin(x,y)  ({__typeof(x) _x=x;__typeof(y) _y=y;_x<_y?_x:_y;})
#define ff(a,l,r) for(int a=l;a<=r;a++)
#define fb(a,r,l) for(int a=r;a>=l;a--)
#if use_prime==1
int ck[maxw+1],pe[maxw+1];
#endif
#if use_dinic==1
struct DINIC{
	#define qpqpqpqp N*2+10
	const int MAXN=qpqpqpqp;
    const int inf=2147483647;
	vector<long long>Stream,S2;
	int Arc[qpqpqpqp],Deep[qpqpqpqp];
	vector< pair<int,int> >Edge[qpqpqpqp];
    vector<array<int,3>>ee;
	inline bool Bfs(int Start,int End)
	{
	    queue<int>Queue;
	    memset(Deep,0,sizeof(Deep));
	    Queue.push(Start);
	    Deep[Start]=1;
	    int i;
	    while(!Queue.empty())
	    {
	        int Top;
	        Top=Queue.front();
	        Queue.pop();
	        for(i=0;i<Edge[Top].size();i++)
	        {
	            if(!Deep[Edge[Top][i].first]&&Stream[Edge[Top][i].second])
	            {
	                Deep[Edge[Top][i].first]=Deep[Top]+1;
	                Queue.push(Edge[Top][i].first);
	                if(Edge[Top][i].first==End)
	                {
	                    return true;
	                }
	            }
	        }
	    }
	    return false;
	}
	inline long long Dfs(int Now,int End,long long Min)
	{
	    if(Now==End)
	    {
	        return Min;
	    }
	    for(int &i=Arc[Now];i<Edge[Now].size();i++)
	    {
	        int U,V;
	        U=Edge[Now][i].first;
	        V=Edge[Now][i].second;
	        if(Deep[U]==Deep[Now]+1&&Stream[V])
	        {
	            int MinStream=0;
	            MinStream=min(Min,Dfs(U,End,min(Min,Stream[V])));
	            if(!MinStream)
	            {
	                continue;
	            }
	            Stream[V]-=MinStream;
	            Stream[V^1]+=MinStream;
	            return MinStream;
	        }
	    }
	    return 0;
	}
	inline long long Dinic(int Start,int End)
	{
	    memset(Arc,0,sizeof(Arc));
	    memset(Deep,0,sizeof(Deep));
	    long long Return;
	    Return=0;
	    long long Delta;
	    while(Bfs(Start,End))
	    {
	        memset(Arc,0,sizeof(Arc));
	        while(Delta=Dfs(Start,End,inf))
	        {
	            Return+=Delta;
	        }
	    }
	    return Return;
	}
	int Count=0;
    void addedge(int u,int v,int w=1)
    {
		Stream.push_back(w);
		S2.push_back(0);
        ee.push_back({u,v,w});
		Edge[u].push_back(pair<int,int>(v,Count));
		++Count;
    }
	void add_edge(int u,int v,int w=1)
	{
        addedge(u,v,w);
        addedge(v,u,0);
	}
    void init()
    {
        Stream.clear();
        S2.clear();
        memset(Arc,0,sizeof(Arc));
        memset(Deep,0,sizeof(Deep));
        for(int x=0;x<MAXN;x++)
        {
            vector<pair<int,int>>pp;
            swap(Edge[x],pp);
        }
	    Count=0;
    }
    DINIC(){init();}
    #undef qpqpqpqp
};
#endif
#if use_mcmf==1
struct MCMF{
	#define qpqpqpqp N*2+10
	const int MAXN=qpqpqpqp;
    const int inf=2147483647;
	double dis[qpqpqpqp];
    int flow[qpqpqpqp],exist[qpqpqpqp];
	int pre[qpqpqpqp],preedge[qpqpqpqp];
	struct Edge
	{
	    int next,to,flow;
        double dis;
	};
	vector<Edge>edge; int head[qpqpqpqp],cnt;
	void init()
	{
		memset(pre,0,sizeof(pre));
		memset(preedge,0,sizeof(preedge));
		memset(head,0,sizeof(head));
		cnt=1;
		edge.clear();
		edge.resize(2);
	}
	MCMF(){init();}
	void addedge(int from,int to,int flow,double dis)
	{
		edge.push_back({head[from],to,flow,dis});
		cnt++;
	    head[from]=cnt;
	}
	void add_edge(int from,int to,int flow,double dis)
	{
	    addedge(from,to,flow,dis);
	    addedge(to,from,0,-dis);
	}
	bool spfa(int s,int t)
	{
	    fill(dis,dis+MAXN,inf);
	    fill(flow,flow+MAXN,inf);
	    memset(exist,0,sizeof(exist));
	    queue<int> q;
	    pre[t]=-1; exist[s]=1; dis[s]=0; q.push(s);
	    while(!q.empty())
	    {
	        int u=q.front();q.pop();exist[u]=0;
	        for(int i=head[u];i;i=edge[i].next)
	        {
	            int v=edge[i].to;
	            if(edge[i].flow>0&&dis[v]>dis[u]+edge[i].dis+eps)
	            {
	                dis[v]=dis[u]+edge[i].dis;
	                flow[v]=min(edge[i].flow,flow[u]);
	                pre[v]=u;
	                preedge[v]=i;
	                if(!exist[v])
	                {
	                    exist[v]=1;
	                    q.push(v);
	                }
	            }
	        }
	    }
	    return pre[t]!=-1;
	}
	pair<int,double>Mcmf(int s,int t)
	{
	    double ret=0;
        int ans=0;
	    while(spfa(s,t))
	    {
	        ret += 1.0*flow[t] * dis[t];
	        int now = t;
	        while(now!=s)
	        {
	            edge[preedge[now]].flow -= flow[t];
	            edge[preedge[now]^1].flow += flow[t];
                //if(edge[preedge[now]^1].to==t)ans-=flow[t];
                if(edge[preedge[now]].to==t)ans+=flow[t];
	            now=pre[now];
	        }
	    }
        return {ans,ret};
	}
	#undef qpqpqpqp
};
#endif
#if use_gcd==1
const int gcd_maxw=maxw,gcd_sqr=sqrt(gcd_maxw);
int gcd_fac[gcd_maxw+10][3];
bool isp[gcd_maxw + 10];
int pri[gcd_maxw+10], tot;
int pre[gcd_sqr+10][gcd_sqr+10];
int gcd(int a, int b) {
  int ans = 1;
  for (int i = 0; i < 3; ++i) {
    int tmp = (gcd_fac[a][i] > gcd_sqr) ?
                (b % gcd_fac[a][i] ?
                   1
                 : gcd_fac[a][i]
                )
              : pre[gcd_fac[a][i]][b % gcd_fac[a][i]];
    b /= tmp;
    ans *= tmp;
  }
  return ans;
}
#endif
void Init_for_all_task()
{
#if (use_C==1||use_inv==1)
init(maxw+10);
#endif
#if use_prime==1
ck[1]=1;
register int sum=0;
for(register int x=2;x<=N;x++)
{
	if(!ck[x])pe[++sum]=x;
	for(register int j=1;j<=sum&&x*pe[j]<=N;j++)
	{
		ck[x*pe[j]]=1;
		if(x%pe[j]==0)break;
	}
}
#endif
#if use_gcd==1
{
  gcd_fac[1][0] = gcd_fac[1][1] = gcd_fac[1][2] = 1;
  for (int i = 2; i <= gcd_maxw; ++i) {
    if (!isp[i]) {
      gcd_fac[i][0] = gcd_fac[i][1] = 1;
      gcd_fac[i][2] = i;
      pri[++tot] = i;
    }
    for (int j = 1; pri[j] * i <= gcd_maxw; ++j) {
      int tmp = pri[j] * i;
      isp[tmp] = true;
      gcd_fac[tmp][0] = gcd_fac[i][0] * pri[j];
      gcd_fac[tmp][1] = gcd_fac[i][1];
      gcd_fac[tmp][2] = gcd_fac[i][2];
      if (gcd_fac[tmp][0] > gcd_fac[tmp][1])swap(gcd_fac[tmp][0],gcd_fac[tmp][1]);
      if (gcd_fac[tmp][1] > gcd_fac[tmp][2])swap(gcd_fac[tmp][1],gcd_fac[tmp][2]);
      if (i % pri[j] == 0)break;
    }
  }
  for (int i = 0; i <= gcd_sqr; ++i) {
    pre[0][i] = pre[i][0] = i;
  }
  for (int i = 1; i <= gcd_sqr; ++i) {
    for (int j = 1; j <= i; ++j) {
      pre[i][j] = pre[j][i] = pre[j][i % j];
    }
  }
}
#endif
//111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111//
//111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111//
}
/*main-head---------------------------------------------------------------------------------------*/
//222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222//
//222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222//
/*default-var-------------------------------------------------------------------------------------*/
namespace nz{
/*namespace-head----------------------------------------------------------------------------------*/
//333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333//
//333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333//
/*var-and-func------------------------------------------------------------------------------------*/
void Main(){
struct custom_hash{static uint64_t splitmix64(uint64_t x) {x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x+FIXED_RANDOM);}};
/*Main-head---------------------------------------------------------------------------------------*/
//444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444//
//when using um,us,gp or cc,add a hash function named custom_hash,use it like unordered_map<int,int,custom_hash>
//also,if want to hack them,https://codeforces.com/blog/entry/62393 is a good choise.
int n;
cin>>n;
vector<int>l(n+1),r(n+1);
unordered_map<int,int,custom_hash>ans;
for(int x=1;x<=n;x++)
cin>>l[x]>>r[x];
int q;
cin>>q;
while(q--)
{
    int d;
    cin>>d;
    int qwq=d&(-d);
    if(ans[qwq]!=0)cout<<ans[qwq]<<endl;
    else{
        int ada=0;
        vector<pair<int,int>>p;
        for(int t=1;t<=n;t++)
        if(r[t]-l[t]+1>=qwq)ada++;
        else if(r[t]%qwq>=l[t]%qwq)p.push_back({l[t]%qwq,1}),p.push_back({r[t]%qwq+1,-1});
        else p.push_back({0,1}),p.push_back({r[t]%qwq+1,-1}),p.push_back({l[t]%qwq,1}),p.push_back({qwq,-1});
        sort(p.begin(),p.end());
        int now=ada;
        ans[qwq]=now;
        for(auto q:p)
        now+=q.second,ans[qwq]=max(ans[qwq],now);
        cout<<ans[qwq]<<endl;
    }
}
//444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444//
/*Main-end----------------------------------------------------------------------------------------*/
}
/*Main-end----------------------------------------------------------------------------------------*/
}
/*namespace-end-----------------------------------------------------------------------------------*/
main()
{
    Init_for_all_task();
#if use_multiple_test_data==1
    int t;cin>>t;while(t--)
#endif
    nz::Main();
}
/*main-end----------------------------------------------------------------------------------------*/
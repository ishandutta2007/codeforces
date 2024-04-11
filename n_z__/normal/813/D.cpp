#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#pragma GCC optimize(3)
#include<bits/stdc++.h>
//#include<bits/extc++.h>
namespace Fread{
const int SIZE= 1 << 16;
	char buf[SIZE],*S,*T;
	inline char getchar(){if(S==T){T=(S=buf)+
	fread(buf,1,SIZE,stdin);if(S==T)return'\n';}return *S++;}
}
namespace Fwrite {
const int SIZE= 1 << 16;
	char buf[SIZE],*S=buf,*T=buf+SIZE;
	inline void flush(){fwrite(buf,1,S-buf,stdout);S=buf;}
	inline void putchar(char c){*S++=c;if(S==T)flush();}
	struct NTR{~NTR(){flush();}}ztr;
}
#ifdef ONLINE_JUDGE
	#define getchar Fread::getchar
	#define putchar Fwrite::putchar
#endif
namespace Fastio{
struct Reader{
	template<typename T>Reader&operator>>(T&x){
		char c=getchar();short f=1;
		while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}
		x=0;while(c>='0'&&c<='9'){
			x=(x<<1)+(x<<3)+(c^48);
			c=getchar();
		}x*=f;return *this;
	}
	Reader&operator>>(double&x){
		char c=getchar();short f=1,s=0;x=0;double t=0;
		while((c<'0'||c>'9')&&c!='-'&&c!='.'){if(c=='-')f*=-1;c=getchar();}
		while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();
		if(c=='.')c=getchar();else return x*=f,*this;
		while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();
		while(s--)t/=10.0;x=(x+t)*f;return*this;
	}
	Reader&operator>>(long double&x){
		char c=getchar();short f=1,s=0;x=0;long double t=0;
		while((c<'0'||c>'9')&&c!='-'&&c!='.'){if(c=='-')f*=-1;c=getchar();}
		while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();
		if(c=='.')c=getchar();else return x*=f,*this;
		while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();
		while(s--)t/=10.0;x=(x+t)*f;return*this;
	}
	Reader&operator>>(__float128&x){
		char c=getchar();short f=1,s=0;x=0;__float128 t=0;
		while((c<'0'||c>'9')&&c!='-'&&c!='.'){if(c=='-')f*=-1;c=getchar();}
		while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();
		if(c=='.')c=getchar();else return x*=f,*this;
		while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();
		while(s--)t/=10.0;x=(x+t)*f;return*this;
	}
	Reader&operator>>(char&c){
		c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();
		return *this;
	}
	Reader&operator>>(char*str){
		int len=0;char c=getchar();
		while(c=='\n'||c==' '||c=='\r')c=getchar();
		while(c!='\n'&&c!=' '&&c!='\r')str[len++]=c,c=getchar();
		str[len]='\0';return*this;
	}
	/*Reader&operator>>(string&str){
		int len=0;char c=getchar();
		while(c=='\n'||c==' '||c=='\r')c=getchar();
		while(c!='\n'&&c!=' '&&c!='\r')str.push_back(c),c=getchar();
		return*this;
	}*/
	Reader(){}
}cin;
const char endl='\n';
struct Writer{
const int Setprecision=6;
typedef int mxdouble;
	template<typename T>Writer&operator<<(T x){
		if(x==0)return putchar('0'),*this;
		if(x<0)putchar('-'),x=-x;
		static int sta[45];int top=0;
		while(x)sta[++top]=x%10,x/=10;
		while(top)putchar(sta[top]+'0'),--top;
		return*this;
	}
	Writer&operator<<(double x){
		if(x<0)putchar('-'),x=-x;
		mxdouble _=x;x-=(double)_;static int sta[45];int top=0;
		while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;putchar('.');
		for(int i=0;i<Setprecision;i++)x*=10;
		_=x;while(_)sta[++top]=_%10,_/=10;
		for(int i=0;i<Setprecision-top;i++)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;
		return*this;
	}
	Writer&operator<<(long double x){
		if(x<0)putchar('-'),x=-x;
		mxdouble _=x;x-=(long double)_;static int sta[45];int top=0;
		while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;putchar('.');
		for(int i=0;i<Setprecision;i++)x*=10;
		_=x;while(_)sta[++top]=_%10,_/=10;
		for(int i=0;i<Setprecision-top;i++)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;
		return*this;
	}
	Writer&operator<<(__float128 x){
		if(x<0)putchar('-'),x=-x;
		mxdouble _=x;x-=(__float128)_;static int sta[45];int top=0;
		while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;putchar('.');
		for(int i=0;i<Setprecision;i++)x*=10;
		_=x;while(_)sta[++top]=_%10,_/=10;
		for(int i=0;i<Setprecision-top;i++)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;
		return*this;
	}
	Writer&operator<<(char c){putchar(c);return*this;}
	Writer& operator<<(char*str){
		int cur=0;while(str[cur])putchar(str[cur++]);
		return *this;
	}
	Writer&operator<<(const char*str){
		int cur=0;while(str[cur])putchar(str[cur++]);
		return*this;
	}
	/*Writer&operator<<(string str){
		int st=0,ed=str.size();
		while(st<ed)putchar(str[st++]);
		return*this;
	}*/
	Writer(){}
}cout;
}
#define cin Fastio :: cin
#define cout Fastio :: cout
#define endl Fastio :: endl
#define string char*
using namespace std;
//using namespace __gnu_pbds;
#define int long long
/*main-head---------------------------------------------------------------------------------------*/
int a[5001],flow[100001],val[100001],nxt[100001],to[100001],head[100001],d[100001],vis[100001],pre1[100001],pre2[100001];
/*default-var-------------------------------------------------------------------------------------*/
namespace nz{
/*namespace-head----------------------------------------------------------------------------------*/
int S,s,t,cnt=1,n;
void addedge(int u,int v,int f,int w){
	flow[++cnt]=f,val[cnt]=w,to[cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
	flow[++cnt]=0,val[cnt]=-w,to[cnt]=u,nxt[cnt]=head[v],head[v]=cnt;
}
const int INF=0x3f3f3f3f;
int ans;
queue<int>q;
bool spfa(){
	
    for(int i=1;i<=t;i++)d[i]=-1;
	d[S]=0;q.push(S);vis[S]=1;
	while(!q.empty()){
		
		int u=q.front();q.pop();
		vis[u]=0;
	    for(int i=head[u];i;i=nxt[i])
	    	if(flow[i]&&d[to[i]]<d[u]+val[i]){
	    		d[to[i]]=d[u]+val[i];
	    		pre1[to[i]]=u;
	    		pre2[to[i]]=i;
	    		if(!vis[to[i]]){
	    			vis[to[i]]=1;
	    			q.push(to[i]);
				}
			}
	}
	return d[t]!=-1;
}
void MCMF()
{
    while(spfa())
    {
        ans+=d[t];
        int now=t;
        while(now){
            flow[pre2[now]]--;
            flow[pre2[now]^1]++;
            now=pre1[now];
        }
    }
}
/*var-and-func------------------------------------------------------------------------------------*/
void Main(){
/*Main-head---------------------------------------------------------------------------------------*/
	cin>>n;
    S=4*n+2,s=4*n+1,t=4*n+3;
	for(int i=1;i<=n;i++)
    cin>>a[i];
	addedge(S,s,2,0);
	for(int i=1;i<=n;i++){
		addedge(s,i,1,0);
		addedge(i,i+n,1,1);
		addedge(i+n,t,1,0);
		addedge(i+2*n,i,1,0);
		addedge(i+3*n,i,1,0);
		for(int j=i+1;j<=n;j++)if(a[i]%7==a[j]%7){addedge(i+n,j+3*n,1,0);addedge(i+3*n,j+3*n,1,0);break;}
		for(int j=i+1;j<=n;j++)if(a[i]+1==a[j]){addedge(i+n,j+2*n,1,0);break;}
		for(int j=i+1;j<=n;j++)if(a[i]-1==a[j]){addedge(i+n,j+2*n,1,0);break;}
		for(int j=i+1;j<=n;j++)if(a[i]==a[j]){addedge(i+2*n,j+2*n,1,0);break;}
	}
    MCMF();
	cout<<ans<<endl;
}
/*Main-end----------------------------------------------------------------------------------------*/
}
/*namespace-end-----------------------------------------------------------------------------------*/
main()
{
    //int t;cin>>t;while(t--)
    nz::Main();
}
/*main-end----------------------------------------------------------------------------------------*/